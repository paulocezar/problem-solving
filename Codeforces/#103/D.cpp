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

struct edge_t{
	int v, w;
	edge_t( int vv = 0, int ww = 0 ) : v(vv), w(ww) {}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n, m, s, l;
	
	cin >> n >> m >> s; s--;
	
	vector< vector< edge_t > > gr( n );
	
	REP( i, m ){
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		gr[u].PB( edge_t(v,w) );
		gr[v].PB( edge_t(u,w) );
	}
	cin >> l;
	
	int d[n];
	REP( i, n ) d[i] = INF;
	
	priority_queue< pair<int,int> > q;
	q.push( MP( 0, s ) );
	d[s] = 0;
	
	while( !q.empty() ){
		
		int dd = -q.top().first;
		int u = q.top().second; q.pop();
		
		if( dd > d[u] ) continue;
		if( dd >= l ) continue;
		
		for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
			int w = gr[u][i].w;
			int v = gr[u][i].v;
			if( dd+w < d[ v ] ){
				d[ v ] = dd + w;
				q.push( MP( -d[ v ], v ) );
			}
		}
	}
	
	int ans = 0;
	REP( i, n ){
		if( d[i] == l ) ans++;
		else if( d[i] < l ){
			for( size_t j = 0, sz = gr[i].size(); j < sz; j++ ){
				int v = gr[i][j].v;
				int w = gr[i][j].w;
				if( d[i]+w > l ){
					ans++;
					if( v < i && (d[i]==d[v]) && (2*(l-d[i]) == w) ) ans--;
				}
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}




















