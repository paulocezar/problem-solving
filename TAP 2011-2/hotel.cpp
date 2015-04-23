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

#define MAXN 10000

struct edge_t{
	int v, w;
	edge_t( int vv = 0, int ww = 0 ) : v(vv), w(ww) {}
};

struct state {
	int u, dis, days;
	state( int uu = 0, int dd = 0, int da = 0 ) : u(uu), dis(dd), days(da){}
	bool operator < (const state& a) const {
		if( days != a.days ) return days > a.days;
		if( dis != a.dis ) return dis > a.dis;
		return u < a.u;
	}
};

vector< edge_t > gr[MAXN];
bool hotel[MAXN];
int dist[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n, h, x, m, u, v, w;
	
	while( cin >> n && n ){
		REP( i, n ){
			gr[i].clear(); hotel[i] = false;
		}
		
		cin >> h;
		while( h-- ){ cin >> x; hotel[ x-1 ] = true; }
		
		cin >> m;
		while( m-- ){
			cin >> u >> v >> w; u--, v--;
			gr[u].PB( edge_t(v,w) );
			gr[v].PB( edge_t(u,w) );
		}
		
		
		queue< int > q; q.push( 0 );
		int days = 0;
		while( !q.empty() ){
			
			REP( i, n ) dist[i] = INF;
			priority_queue< pair<int,int> > pq;
			while( !q.empty() ){ u = q.front(); dist[u] = 0; q.pop(); pq.push( MP(0,u) ); }
			
			while( !pq.empty() ){
				u = pq.top().second;
				w = -pq.top().first; pq.pop();
				
				if( w > dist[u] ) continue;
				if( u == n-1 ){ cout << days; goto hell; }
				if( hotel[u] ){ q.push( u ); hotel[u] = false; }

				REP( i, SIZE(gr[u]) ){
					v = gr[u][i].v;
					x = w + gr[u][i].w;

					if( x > 600 ) continue;
					if( x < dist[ v ] ){
						dist[v] = x;
						pq.push( MP(-x,v) );
					}	
				}
			}
			
			days++;
		}
		
		cout << "-1";
	hell:
		cout << "\n";
 	}
	
	return 0;
}




















