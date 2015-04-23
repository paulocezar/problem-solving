#include <set>
#include <string> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string board[12];
int seen[12][10], seen_now;

int dx[] = {-1, +1, 0, 0};
int dy[] = { 0,  0,-1,+1};

bool valid(int i, int j) { return ((i >= 0) && (i < 12) && (j >= 0) && (j < 10)); }

char cur_piece;

int flood(int i, int j, bool erase = false) {
    if (!valid(i,j)) return 0;
    if (board[i][j] != cur_piece) return 0;
    if (seen[i][j] == seen_now) return 0;
    seen[i][j] = seen_now;
    
    int res = 1;
    for (int dir = 0; dir < 4; ++dir) {
        res += flood(i+dx[dir],j+dy[dir],erase);
    }
    
    if (erase) board[i][j] = '.';
    return res;
}

void fixboard() {
    int keep = 0;
    for (int j = 0; j < 10; ++j) {
        int curi = 11;
        for (int i = 11; i >= 0; --i) {
            if (board[i][j] != '.') {
                board[curi][j] = board[i][j];
                curi--;
            }
        }
        while (curi >= 0) {
            board[curi][j] = '.';
            curi--;
        }
        if (board[11][j] != '.') keep |= (1<<j);
    }
    
    int curj = 0;    
    for (int j = 0; j < 10; ++j) {
        if (keep & (1<<j)) {
            for (int i = 0; i < 12; ++i)
                board[i][curj] = board[i][j];
            curj++;
        }
    }
    while (curj < 10) {
        for (int i = 0; i < 12; ++i)
            board[i][curj] = '.';
        curj++;
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    while (cin >> T && T) {
        for (int i = 0; i < 12; ++i) cin >> board[i];
        
        int lin, col;
        char cl;
        
        int erased = 0;
        while (T--) {
            cin >> cl >> lin;
            lin = 12-lin;
            col = cl-'a';
            seen_now++;
            cur_piece = board[lin][col];

            int cur_turn = ((cur_piece == '.') ? 0 : flood(lin, col));
            
            if (cur_turn > 2) {
                erased += cur_turn;
                seen_now++;
                flood(lin, col, true);
            }
            fixboard();
            //for (int i = 0; i < 12; ++i) cout << board[i] << endl;
            //cout << "--------" << endl;
        }
        cout << 120-erased << "\n";
        
    }
    

	return 0;
}

















