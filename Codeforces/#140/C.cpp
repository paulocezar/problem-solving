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

int64 ax[2][2], MOD;

void mult(int64 a[][2], int64 b[][2]) {
    REP(i,2) REP(j,2){
        ax[i][j] = 0;
        REP(k,2) {
            ax[i][j] += (a[i][k]*b[k][j])%MOD;
            ax[i][j] %= MOD;
        }
    }
    REP(i,2) REP(j,2) a[i][j] = ax[i][j];
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int64 l, r, k;
    cin >> MOD >> l >> r >> k;
    
    int64 lo = 1LL, hi = r;
    int64 n = 1LL;
    while (lo <= hi) {
        int64 mid = lo + ((hi-lo)>>1);
        
        if (((r/mid) - ((l-1LL)/mid)) >= k) {
            n = mid;
            lo = mid+1LL;
        } else {
            hi = mid-1LL;
        }
    }
    
    int64 pot[][2] = {{1,1},{1,0}};
    int64 res[][2] = {{1,0},{0,1}};
    n--;
    while(n) {
        if(n&1LL) mult(res,pot);
        mult(pot,pot);
        n >>= 1;
    }
    cout << (res[1][0] + res[1][1])%MOD << "\n";
    
    
    return 0;
}
















