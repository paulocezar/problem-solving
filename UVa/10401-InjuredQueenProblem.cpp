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

#define MAXN 15
string line;

int N;
int64 dp[MAXN][MAXN];
inline int col( char c ){ return ((('1'<=c)&&(c<='9'))?( c-'1' ):( 9+c-'A' )); }

int64 ways( int x, int y ){
	if( x == N-1 ) return 1LL;
	if( dp[x][y] == -1 ){
		dp[x][y] = 0LL;
		
		if( line[x+1] == '?' ){
			
			REP( cc, N ) if( cc != y && cc != y+1 && cc != y-1 )
				dp[x][y] += ways( x+1, cc );
			
		} else if( ABS( col( line[x+1] ) - y ) > 1 ) dp[x][y] = ways( x+1, col( line[x+1] ) );	
		
 	}
	return dp[x][y];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( getline(cin,line) ) if( SIZE(line) ){
		int64 ans = 0; 
		N = SIZE(line); REP( i, N ) REP( j, N ) dp[i][j] = -1;
		if( line[0] == '?' ) REP( i, N ) ans += ways( 0, i );
		else ans = ways( 0, col( line[0] ) );
		cout << ans << "\n";
	}
	
	return 0;
}




















