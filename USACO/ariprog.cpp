/*
ID: knightp2
PROG: ariprog
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

#define MAXVAL 125001    
bitset< MAXVAL > bisquare;
vector< pair<int,int> > ans;

int main(int argc, char* argv[]) {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");	
    
    int N, M;
    fin >> N >> M;
    
    for (int p = 0; p <= M; ++p) {
        for (int q = p; q <= M; ++q) {
            bisquare[p*p + q*q] = true;
        }
    }
    
    FOR(a,0,125000) if (bisquare[a]) {
        int maxdif = (125000 - a) / (N-1);
        FOR(b,1,maxdif) {
            bool ok = true;
            FOR(k,1,N-1) if (!bisquare[a+k*b]) { ok = false; break; }
            if (ok) ans.PB(MP(b,a));
        }
    }
    sort(ALL(ans));
    
    if (SIZE(ans)) REP(i,SIZE(ans)) fout << ans[i].second << " " << ans[i].first << "\n";
    else fout << "NONE\n";
    
	return 0;
}

















