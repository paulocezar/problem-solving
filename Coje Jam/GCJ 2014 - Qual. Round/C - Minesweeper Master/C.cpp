#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int grid[64][64];
int cnt[64][64];
int last_seen[64][64], seen_now, R, C, M, put;

int dx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int dy[] = {-1,  0, +1,-1,+1, -1,  0, +1};

void print() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            switch(grid[i][j]) {
                case 0: cout << "."; break;
                case 1: cout << "*"; break;
                case 2: cout << "c"; break;
            }
        }
        cout << "\n";
    }
}

int flood(int i, int j) {
    if ((i < 1) || (i > R) || (j < 1) || (j > C)) return 0;
    if (last_seen[i][j] == seen_now) return 0;
    if (grid[i][j]) return 0;
    last_seen[i][j] = seen_now;
    int ret = 1;
    
    if (!cnt[i][j]) {
        for (int dir = 0; dir < 8; ++dir) ret += flood(i+dx[dir],j+dy[dir]);
    }
    
    return ret;
}

bool check() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (!grid[i][j] && !cnt[i][j]) {
                seen_now++;
                int reveal = flood(i, j);
                if ((reveal + M) == (R*C)) {
                    grid[i][j] = 2;
                    print();
                    return true;
                }
                return false;
            }
        }
    }
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (!grid[i][j] && cnt[i][j]) {
                seen_now++;
                int reveal = flood(i, j);
                if ((reveal + M) == (R*C)) {
                    grid[i][j] = 2;
                    print();
                    return true;
                }
                return false;
            }
        }
    }
    
    return false;
}

bool gen(int i, int j) {
    if (j == (C+1)) return gen(i+1,1);
    
    if (((R-i+1)*C - j + 1 + put) < M) return false;
    
    if (put == M) return check();
    
    if (gen(i,j+1)) return true;
    
    for (int dir = 0; dir < 8; ++dir) cnt[i+dx[dir]][j+dy[dir]]++;
    put++;
    grid[i][j] = 1;
    if (gen(i, j+1)) return true;
    grid[i][j] = 0;
    put--;
    for (int dir = 0; dir < 8; ++dir) cnt[i+dx[dir]][j+dy[dir]]--;
    
    return false;    
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int kase = 1; kase <= cases; ++kase) {
        cin >> R >> C >> M;
        
        for (int i = 1; i <= R; ++i)
            for (int j = 1; j <= C; ++j)
                grid[i][j] = 0, cnt[i][j] = 0;
        
        put = 0;
        cout << "Case #" << kase << ":\n";
        if (!gen(1,1)) cout << "Impossible\n";
    }

	return 0;
}

















