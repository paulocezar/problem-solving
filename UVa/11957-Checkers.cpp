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

#define MAXN 111

const int64 MOD = 1000007LL;

string grid[MAXN];
int64 dp[MAXN][MAXN]; int N;

inline bool ok( int x, int y ){ return ( (x>=0) && (y>=0) && (x<N) && (y<N) ); }

int64 solve( int x, int y ){
	if( x == 0 ) return 1;
	if( dp[x][y] == -1 ){
		
		dp[x][y] = 0;
		
		if( ok( x-1, y-1 ) && grid[x-1][y-1] == '.' )
			dp[x][y] += solve( x-1, y-1 );
		else if( ok(x-1, y-1) && ok(x-2, y-2) && grid[x-2][y-2] == '.' )
			dp[x][y] += solve( x-2, y-2 );
		dp[x][y] %= MOD;
		
		if( ok( x-1, y+1 ) && grid[x-1][y+1] == '.' )
			dp[x][y] += solve( x-1, y+1 );
		else if( ok(x-1, y+1) && ok(x-2, y+2) && grid[x-2][y+2] == '.' )
			dp[x][y] += solve( x-2, y+2 );
		dp[x][y] %= MOD;	
	}
	return dp[x][y];
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	FOR( tc, 1, t ){
		cin >> N;
		REP( i, N ) cin >> grid[i];
		REP( i, N ) REP( j, N ) dp[i][j] = -1;
		REP( i, N ) REP( j, N ) if( grid[i][j] == 'W' ) {
			cout << "Case " << tc << ": " << solve( i, j ) << "\n";
		}
	}
	return 0;
}




















