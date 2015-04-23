/*
ID: knightp2
PROG: subset
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

char calc[40][20*40];
int64 res[40][20*40];

int N, sum;
int64 solve(int at, int with) {
    if (at == N+1) return ((2*with == sum) ? 1 : 0);
    if (calc[at][with]) return res[at][with];
    calc[at][with] = true;
    res[at][with] = solve(at+1,with+at) + solve(at+1,with);
    return res[at][with];
}

int main(int argc, char* argv[]) {
    ifstream fin("subset.in");
    ofstream fout("subset.out");	
    
    fin >> N;
    sum = (N * (N+1))/2;

    if (sum & 1) fout << "0\n";
    else fout << solve(1,0)/2LL << "\n";
        
	return 0;
}

















