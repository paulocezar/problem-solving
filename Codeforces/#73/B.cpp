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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>

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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int n, m, x;
	cin >> n >> m >> x;
	
	string grid[n];
	REP( i, n ) cin >> grid[i];
	
	int dist[30];
	char ok[30];
	FILL( dist, INF );
	FILL( ok, 0 );
	
	REP( i, n ) REP( j, m ) if( grid[i][j] != 'S' ){
		ok[ grid[i][j] - 'a' ] = 1;
		REP( ii, n ) REP( jj, m ) if( grid[ii][jj] == 'S' ){
			int cur = grid[i][j]-'a';
			dist[ cur ] = MIN( dist[cur], SQR(ii-i) + SQR(jj-j) );
		}
	}
	x = SQR(x);
	int q;
	cin >> q; cin.ignore();
	string T;
	getline( cin, T );
	int ans = 0;
	REP( i, q )
	if( 'a' <= T[i] && T[i] <= 'z' ){
		if( !ok[T[i]-'a'] ){ ans = -1; break; }
	} else if( 'A' <= T[i] && T[i] <= 'Z' ){
		if( !ok[T[i]-'A'] || dist[T[i]-'A'] == INF ){ ans = -1; break; }
		if( dist[ T[i]-'A' ] > x ) ans++;
	}
	
	cout << ans << "\n";
 	return 0;
}

































