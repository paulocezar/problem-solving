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
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

inline int next_int() {
	int n = 0, neg = 1;
	char c = getchar_unlocked();
	if( c == EOF ) exit(0);
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
		if( c == EOF ) exit(0);
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return neg*n;
}

#define MAXN 510

int dp[MAXN][MAXN], a[MAXN][MAXN], b[MAXN][MAXN];

int solve( int n, int  m ){
	if( n == 0 || m == 0 ) return 0;
	if( dp[n][m] == -1 ) dp[n][m] = max( a[n][m]+solve(n-1,m), b[n][m]+solve(n,m-1) );
	return dp[n][m];
}

int main( int argc, char* argv[] ){
	
	int n, m, x;

play:	
	n = next_int();
	m = next_int();
	if( n+m ){
		
		REP( i, n+1 ){ a[i][0] = 0; b[i][0] = 0; dp[i][0] = 0; }
		REP( i, m+1 ){ a[0][i] = 0; b[0][i] = 0; dp[0][i] = 0; }
		
		FOR( i, 1, n )
			FOR( j, 1, m ){
				x = next_int();
				a[i][j] = a[i][j-1] + x;
			}
		
		FOR( i, 1, n )
			FOR( j, 1, m ){
				x = next_int();
				b[i][j] = b[i-1][j] + x;
				dp[i][j] = max( a[i][j]+dp[i-1][j], b[i][j]+dp[i][j-1] );
			}
		
		printf("%d\n", dp[n][m] );
		goto play;
	}
	
	return 0;
}




















