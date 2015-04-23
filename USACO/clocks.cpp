/*
ID: knightp2
PROG: clocks
LANG: C++
*/
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
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char seen[2<<18];

int encode(char board[9]) {
    int res = 0;
    for (int i = 0; i < 9; ++i) res = 4*res + board[i];
    return res;   
}

void decode(int x, char board[9]) {
    for (int i = 8; i >= 0; --i) {
        board[i] = x%4;
        x /= 4; 
    }
}

void clockwise(int move, char board[9]) {
    for (int i = 0; i < 9; ++i) if (move & (1<<i)) {
        board[i]++; if (board[i] == 4) board[i] = 0;
    }
}

void counterclock(int move, char board[9]) {
    for (int i = 0; i < 9; ++i) if (move & (1<<i)) {
        board[i]--; if (board[i] == -1) board[i] = 3;
    }
}

int affects[] = {0,0x1B,0x7,0x36,0x49,0xBA,0x124,0xD8,0x1C0,0x1B0};

ofstream fout("clocks.out");

bool show(int stt) {
    
    if (seen[stt] == -1) return false;
    char ax[9];
    
    decode(stt,ax);
    counterclock(affects[seen[stt]], ax);
    if (show(encode(ax))) fout << " ";
    fout << int(seen[stt]);
    return true;
}

int main(int argc, char* argv[]) {
    ifstream fin("clocks.in");
	
    char initial[9], current[9], next[9];
    
    for (int i = 0; i < 9; ++i) {
        int x; fin >> x;
        initial[i] = (x/3)%4;
    }
        
    seen[ encode(initial) ] = -1;
    
    queue< int > q; q.push(encode(initial));
    while (!q.empty()) {
        if (q.front() == 0) break;
        decode(q.front(), current);
        q.pop();
        
        for (int move = 1; move <= 9; ++move) {
            memcpy(next,current,9);
            clockwise(affects[move],next);
            int enc = encode(next);
            if (seen[enc] == 0) {
                seen[enc] = move;
                q.push(enc);
            }
        }
    }
    show(0);
    fout << "\n";
	
	return 0;
}

















