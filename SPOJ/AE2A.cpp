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

#define MXXX 1000

double dp[MXXX+1][6*MXXX+1];
char memo[MXXX+1][6*MXXX+1];

double solve( int n, int k ){
	if( n > MXXX || 6*n < k || n > k ) return 0;
	if( n == 0 ) return k == 0 ;
	
	if( memo[n][k] ) return dp[n][k];
	memo[n][k] = 1;
	
	dp[n][k] = 0.0;
	FOR( c, 1, 6 ) if( k >= c )
		dp[n][k] += solve(n-1,k-c)/6.0;
	
	return dp[n][k];
}

int main( int argc, char* argv[] ){
	ios::sync_with_stdio( false );
	int t, n, k;
	cin >> t;
	FILL(memo,0);
	while(t--){
		cin >> n >> k;
		cout << int( 100.0*solve( n, k ) ) << "\n";
	}
	return 0;
}




















