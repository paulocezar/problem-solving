#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(double a, double b) { return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int c, n;
vector< vector<int> > m;
vector< vector<int> > dp;

int solve( int y, int z ){
	if( z == n ) return 0;
	if( dp[y][z] == -1 ){
		dp[y][z] = INF;
		REP( i, SIZE(m[y]) )
			dp[y][z] = MIN( dp[y][z], c+m[y][i] + solve( z+i+1, z+i+1 ) );
	}
	return dp[y][z];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( cin >> c ){
		cin >> n;
		m.resize( n ); dp.resize(n);
		REP( i, n ){
			m[i].resize( n-i );
			dp[i].resize( n );
			REP( j, n-i ){ cin >> m[i][j]; dp[i][j] = -1; }
			FOR( j, n-i, n ) dp[i][j] = -1;
		}
		cout << solve( 0, 0 ) << endl;
	}
	
	return 0;
}




















