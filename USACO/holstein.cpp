/*
ID: knightp2
PROG: holstein
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

int has[15][25];
int need[25], cur[25];

int main(int argc, char* argv[]) {
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");	
    
    int V;
    fin >> V;
    REP(i,V) fin >> need[i];
    int G;
    fin >> G;
    REP(i,G) REP(j,V) fin >> has[i][j];
    
    int best = G+1;
    int bmask;
    REP(mask,(1<<G)) {
        if (__builtin_popcount(mask) >= best) continue;
        REP(i,V) cur[i] = 0;
        REP(i,G) if (mask & (1<<i)) {
            REP(j,V) cur[j] += has[i][j];
        }
        bool ok = true;
        REP(i,V) {
            if (cur[i] < need[i]) {
                ok = false;
                break;
            }
        }
        if (ok) best = __builtin_popcount(mask), bmask = mask;
        
    }
    fout << best;
    REP(i,G) if (bmask & (1<<i)) fout << " " << (i+1);
    fout << "\n";
            
	return 0;
}

















