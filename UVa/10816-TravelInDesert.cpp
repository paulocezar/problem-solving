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
struct edge_t{
	int v, dist, temp;
	edge_t( int vv = 0, int dd = 0, int tt = 0 ) : v(vv), dist(dd), temp(tt) {}
};
vector< edge_t > gr[MAXN];
int parent[MAXN], d[MAXN], pans[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, E, s, t, u, v, dis, tmp, dd;
	double dist, temp;
	
	while( (cin >> N >> E) && (N+E) ){
		REP( i, N ) gr[i].clear();
		cin >> s >> t; s--, t--;
		int mid, lo = INF, hi = -1;
		while( E-- ){
			cin >> u >> v >> temp >> dist;
			u--, v--;
			temp *= 10;
			dist *= 10;
			lo = MIN( lo, int(temp) );
			hi = MAX( hi, int(temp) );
			gr[u].PB( edge_t( v, int(dist), int(temp) ) );
			gr[v].PB( edge_t( u, int(dist), int(temp) ) );
		}
		
		tmp = dis = -1;
		while( lo <= hi ){
			mid = (lo+hi)/2;
			REP( i, N ){ parent[i] = -1; d[i] = INF; }
			d[s] = 0;
			priority_queue< pair<int,int> > q;
			q.push( MP( 0, s ) );
			while( !q.empty() ){
				u = q.top().second;
				dd = -q.top().first; q.pop();
				if( u == t ) break;
				if( dd > d[u] ) continue;
				REP( i, SIZE(gr[u]) ){
					if( gr[u][i].temp <= mid && dd+gr[u][i].dist < d[gr[u][i].v] ){
						parent[ gr[u][i].v ] = u;
						d[ gr[u][i].v ] = dd+gr[u][i].dist;
						q.push( MP( -d[gr[u][i].v ], gr[u][i].v ) );
					}
				}
			}
			if( d[t] < INF ){
				REP( i, N ) pans[i] = parent[i];
				dis = d[t];
				hi = mid-1;
				tmp = mid;
			} else {
				lo = mid+1;
			}
		}
		stack< int > pth;
		while( t != s ){
			pth.push( t );
			t = pans[t];
		}
		cout << s+1;
		while( !pth.empty() ){
			cout << " " << pth.top()+1; pth.pop();
		}
		cout << "\n" << dis/10 << "." << dis%10 << " " << tmp/10 << "." << tmp%10 << "\n";
		
	}
	
	return 0;
}




















