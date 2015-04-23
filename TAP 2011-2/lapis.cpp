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
	short v, w;
	edge_t( short vv = 0, short ww = 0 ) : v(vv), w(ww) {}
};

#define MAXN 5000

int dist[MAXN];
vector< edge_t > gr[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, N, R, K;
	short u, v, w;
	
	cin >> t;
	while( t-- ){
		cin >> N;
		REP( i, N ){ dist[i] = INF; gr[i].clear(); }
		cin >> R;
		while( R-- ){
			cin >> u >> v >> w; u--, v--;
			gr[u].PB( edge_t(v,w) );
			gr[v].PB( edge_t(u,w) );
		}
		cin >> K;
		priority_queue< pair<int,short> > q;
		while( K-- ){
			cin >> u >> w; u--;
			dist[u] = w;
			q.push( MP(-w,u) );
		}
		cin >> v; v--;
		
		while( !q.empty() ){
			
			u = q.top().second;
			int dis = -q.top().first; q.pop();
			if( dis > dist[v] ) continue;
			if( u == v ){ cout << dis << "\n"; break; }
			
			REP( i, SIZE(gr[u]) ){
				if( gr[u][i].w+dis < dist[gr[u][i].v] ){
					dist[gr[u][i].v] = gr[u][i].w+dis;
					q.push( MP(-dist[gr[u][i].v], gr[u][i].v) );
				}
			}
			
		}
		
	}
	
	return 0;
}




















