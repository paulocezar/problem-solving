#include <map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof( (X).begin() )
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for( int i = a; i <= b; ++i)
#define RFOR(i, b, a) for( int i = b; i >= a; --i)
#define REP(i, N) for( int i = 0; i < N; ++i)
#define RREP(i, N) for( int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

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

#define MAXN 50
int cost[MAXN][MAXN];
int N, dist[MAXN], parent[MAXN];

struct ans_t{
	int orig, len;
	vector< int > path;
	ans_t(){ orig = len = 0; path.resize(0); }
	bool operator < ( const ans_t& a ) const {
		if( len != a.len ) return len < a.len;
		return orig < a.orig;
	}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, dest, u, v, c;
	string linha;
	
	cin >> t;
	while( t-- ){
		
		cin >> N;
		
		FOR( i, 1, N ) FOR( j, 1, N ) cin >> cost[i][j];
		
		cin >> dest;
		getline( cin, linha );
		istringstream in( linha );
		
		vector< ans_t > ans;
		while( in >> v ){
			
			ans_t vans;
			vans.orig = v;
			FOR( i, 1, N ) dist[i] = INF;
			dist[v] = 0;
			parent[v] = -1;
			
			priority_queue< pair<int,int> > q;
			q.push( MP( 0, v ) );
			
			while( !q.empty() ){
				u = q.top().second;
				c = -q.top().first; q.pop();
				
				if( u == dest ) break;
				if( dist[u] < c ) continue;
				
				FOR( nw, 1, N ) if( cost[u][nw] != -1 && ( (c + cost[u][nw]) < dist[nw] ) ){
					parent[nw] = u;
					dist[nw] = c + cost[u][nw];
					q.push( MP( -dist[nw], nw ) );
				}
			}
			
			vans.len = dist[dest];
			
			v = dest;
			while( v != -1 ){
				vans.path.PB( v );
				v = parent[v];
			}
			
			reverse( ALL(vans.path) );
			ans.PB( vans );
		}
		sort( ALL( ans ) );
		
		cout << "Org\tDest\tTime\tPath\n";
		REP( i, SIZE( ans ) ){
			cout << ans[i].orig << '\t' << dest << '\t' << ans[i].len << '\t' << ans[i].path[0];
			FOR( j, 1, SIZE(ans[i].path)-1 ) cout << '\t' << ans[i].path[j];
			cout << "\n";
		}
		if( t ) cout << "\n";
	}
	
	return 0;
}
