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

int mpn[10][10];
int dist[100][100];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n;
	while( cin >> n && n ){
		
		int cur = 0;
		REP( i, n ) REP( j, n ) mpn[i][j] = cur++;
		
		REP( i, cur ) REP( j, cur ) dist[i][j] = ((i==j)?(0):(INF));
		
		RREP( j, n ){
			REP( i, n ){
				int a, b, c, d; cin >> a >> b >> c >> d;
				if( a ) dist[ mpn[i][j] ][ mpn[i][j+1] ] = 1;
				if( b ) dist[ mpn[i][j] ][ mpn[i][j-1] ] = 1;
				if( c ) dist[ mpn[i][j] ][ mpn[i-1][j] ] = 1;
				if( d ) dist[ mpn[i][j] ][ mpn[i+1][j] ] = 1;
			}
		}
		
		REP( k, cur ) REP( i, cur ) REP( j, cur )
			dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
		
		int P;
		cin >> P;
		while( P-- ){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if( dist[ mpn[a][b] ][ mpn[c][d] ] == INF ) cout << "Impossible\n";
			else cout << dist[ mpn[a][b] ][ mpn[c][d] ] << "\n";
		}		
	}
	
			
	return 0;
}

























