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
const int64 base[5] = {1,1,1,2,2};

int64 ax[5][5];

int next_int(){
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}

void mult(int64 a[][5], int64 b[][5]) {
    REP(i,5) REP(j,5) {
        ax[i][j] = 0;
        REP(k,5) {
            ax[i][j] += (a[i][k]*b[k][j]) % mod;
            ax[i][j] %= mod;
        }
    }
    REP(i,5) REP(j,5) a[i][j] = ax[i][j];
}

int64 f(int n) {
    int64 a[][5] = {{1, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 1, 0},
                    {0, 0, 0, 0, 1}};
    int64 b[][5] = {{1, 0, 1, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 1, 0},
                    {0, 0, 0, 0, 1},
                    {0, 4, 0, 0, 0}};
    
    while (n) {
        if (n&1) mult(a,b);
        mult(b,b);
        n >>= 1;
    }
    int64 res = 0;
    REP(i,5) {
        res += (a[0][i] * base[i]) % mod;
        res %= mod;
    }
    return res;
}

int main( int argc, char* argv[] ){
	
	int t;
    t = next_int();
    while (t--) {
        int n;
        n = next_int();
        printf("%lld\n", f(n));
    }
        
	return 0;
}


























