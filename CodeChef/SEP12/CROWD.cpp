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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1000000007LL;
int64 ax[4][4];
void mult(int64 a[][4], int64 b[][4]) {
    REP(i,4) REP(j,4) {
        ax[i][j] = 0;
        REP(k,4) {
            ax[i][j] += (a[i][k]*b[k][j])%mod;
            ax[i][j] %= mod;
        }
    }
    REP(i,4) REP(j,4)
        a[i][j] = ax[i][j];
}

int64 cool(int64 n) {
    int64 a[][4] = {{1, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};
    int64 b[][4] = {{1, 0, 1, 0},
                    {1, 0, 1, 0},
                    {0, 1, 0, 1},
                    {0, 1, 0, 0}};
    while (n) {
        if (n&1LL) mult(a,b);
        mult(b,b);
        n >>= 1;
    }
    int64 res = 0;
    REP(i,4) { res += a[0][i]; res %= mod; }
    return res;
}

int64 total(int64 n) {
    int64 res = 1;
    int64 pw = 2;
    while (n) {
        if (n&1LL) {
            res *= pw;
            res %= mod;
        }
        pw *= pw;
        pw %= mod;
        n >>= 1;
    }
    return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
    
    int t;
    cin >> t;
    while (t--) {
        int64 n;
        cin >> n;
        int64 res = total(n) - cool(n);
        res %= mod;
        res += mod;
        res %= mod;
        cout << res << "\n";
    }
    

	return 0;
}


























