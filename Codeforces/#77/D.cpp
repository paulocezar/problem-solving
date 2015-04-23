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
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1000
int n, m, x, y;

int cost[MAXN][MAXN];
int ccost[MAXN][MAXN];

int t[MAXN], c[MAXN];

vector< int > gr[MAXN];
int64 pay[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int u, v, cuv;
	int64 cc;
	cin >> n >> m;
	cin >> x >> y; x--, y--;
	
	REP( i, n ){
		gr[i].clear(); pay[i] = -1;
		REP( j, n ) cost[i][j] = ccost[i][j] = INF; 
	}
	
	REP( i, m ){
		cin >> u >> v >> cuv; u--, v--;
		if( cost[u][v] == INF ){
			gr[u].PB( v );
			gr[v].PB( u );
		}
		cost[u][v] = MIN( cost[u][v], cuv );
		cost[v][u] = cost[u][v];
	}
	
	vector< int > gr2[n];	
	REP( i, n ){
		cin >> t[i] >> c[i];

		priority_queue< pair< int64, int > > q;
		ccost[i][i] = 0;
		q.push( MP( 0, i ) );
		
		while( !q.empty() ){
			u = q.top().second;
			cc = -q.top().first; q.pop();
			
			if( ccost[i][u] == c[i] ) continue;
			if( u != i ){ 
				gr2[ i ].PB( u );
				ccost[i][u] = c[i];
			}
			
			for( int j = 0, sz = SIZE(gr[u]); j < sz; j++ ) if( cc + cost[u][ gr[u][j] ] <= t[i] )
				q.push( MP(-(cc+cost[u][ gr[u][j] ]), gr[u][j]) );
				
		}
	}
	
	pay[x] = 0;	
	priority_queue< pair<int64, int> > q;
	q.push( MP( 0, x ) );
	
	while( !q.empty() ){
		
		u = q.top().second;
		cc = -q.top().first; q.pop();

		if( u == y ) break;
		
		for( int i = 0, sz = SIZE(gr2[u]); i < sz; i++ ){
			if( pay[ gr2[u][i] ] == -1 || cc + ccost[u][ gr2[u][i] ] < pay[ gr2[u][i] ] ){
				pay[ gr2[u][i] ] = cc+ccost[u][ gr2[u][i]];
				q.push( MP( -pay[ gr2[u][i] ], gr2[u][i] ) );
			}
		}
		
	}
	cout << pay[y] << "\n";
	
	return 0;
}




















