/*
ID: knightp2
PROG: stamps
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

#define MAXN 64
#define MAXK 200
#define MAXSTAMP 10000

int a[MAXN];
int dist[MAXK*MAXSTAMP + 10];

int main(int argc, char* argv[]) {
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    
    int n, k;
    cin >> k >> n;
    
    REP(i, n) cin >> a[i];
    sort(a, a+n);
    
    dist[0] = 0;
    
    int M = 1;
    while (true) {
        dist[M] = k+1;
        
        REP(i, n) {
            if (M >= a[i]) dist[M] = min(dist[M], dist[M-a[i]]+1);
            else break;
        }
        
        if (dist[M] > k) {
            cout << M-1 << "\n";
            break;
        }
        
        M++;
    }
        
	return 0;
}

















