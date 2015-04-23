/*
ID: knightp2
PROG: checker
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

ofstream fout("checker.out");	
int N;

int at[16];
int sol;

int cc, d1, d2;

void gen(int row) {
    if (row == N) {
        sol++;
        if (sol <= 3) {
            REP(i,N) {
                if (i) fout << " ";
                fout << (at[i]+1);
            }
            fout << "\n";
        }
    }
    
    for (int col = 0; col < N; ++col) {
        if (cc & (1<<col)) continue;
        if (d1 & (1<<(row+col))) continue;
        if (d2 & (1<<(N-(col-row)))) continue;
        
        at[row] = col;
        cc |= (1<<col);
        d1 |= (1<<(row+col));
        d2 |= (1<<(N-(col-row)));
    
        gen(row+1);
        
        cc ^= (1<<col);
        d1 ^= (1<<(row+col));
        d2 ^= (1<<(N-(col-row)));
    }    
}

int main(int argc, char* argv[]) {
    ifstream fin("checker.in");
    
    fin >> N;
    
    cc = 0, d1 = 0, d2 = 0, sol = 0;
    gen(0);
    fout << sol << "\n";
        
	return 0;
}

















