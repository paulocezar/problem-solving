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
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 77
#define MAXK 10

int N;
int grid[MAXN][MAXN];	
int dp[MAXN][MAXN][MAXK][2];

int solve( int i, int j, int k, int dir ){
	if( (i == N-1) && (dir == 1) ) return -INF;
	if( (i == N-1) && (j == N-1) ) return ((grid[i][j] < 0)?((k)?(grid[i][j]):(-INF)):(grid[i][j])); 
	
	int &r = dp[i][j][k][dir];
	if( r == -1 ){	
		r = -INF;
		int nk = k - ((grid[i][j]<0)?(1):(0));
		if( nk >= 0 ){
			if( i+1 < N ) r = MAX( r, MAX( solve(i+1,j,nk,0), solve(i+1,j,nk,1) ) );
			if( dir == 0 && j+1 < N ) r = MAX( r, solve(i,j+1,nk,dir) );
			if( dir == 1 && j ) r = MAX( r, solve(i,j-1,nk,dir) );
			if( r != -INF ) r += grid[i][j];
		} 
	}
	
	return r;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int K, tc = 1;
	while( (cin>>N>>K) && (N+K) ){
		
			REP( i, N ) REP( j, N ){
				cin >> grid[i][j];
				REP( k, K+1 )
				dp[i][j][k][0] = -1, dp[i][j][k][1] = -1;
			}
			int ans = solve( 0, 0, K, 0 );
			
			cout << "Case " << tc++ << ": ";
			if( ans != -INF ) cout << ans << '\n';
			else cout << "impossible\n";
			
	}
	
	return 0;
}




















