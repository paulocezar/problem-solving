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

#define MAXN 2555
vector< int > gr[MAXN];
int path[MAXN];

int ru, rv;
bool ok( int u, int v ){ return ((u != ru || v != rv) && (v != ru || u != rv)); }

int dfs( int u, int parent = -1 ){
	path[u] = u;
	int ans = 0;
	REP( i, SIZE(gr[u]) ) if( gr[u][i] != parent && ok( u, gr[u][i] ) ){
		int nd = dfs( gr[u][i], u ) + 1;
		if( nd > ans ){
			ans = nd;
			path[u] = gr[u][i];
		}
	}
	return ans;
}

int nu;
int diameter( int u ){
	int di = dfs( u );
	REP( i, di ) u = path[u];
	di = dfs( u );
	REP( i, di/2 ) u = path[u]; nu = u;
	return di;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t, u, v, bu, bv, bnu, bnv, d1, d2, cur, ans, N;
	cin >> t;
	
	while( t-- ){
		cin >> N;
		
		FOR( i, 1, N ) gr[i].clear();
		REP( i, N-1 ){ 
			cin >> u >> v;
			gr[u].PB(v ); gr[v].PB( u );
		}
		
		ans = INF, bu = 1, bv = 1;
		FOR( i, 1, N ){
			u = i;
			REP( j, SIZE(gr[u]) ) if( u < gr[u][j] ){
				v = gr[u][j];
				ru = u, rv = v;
				d1 = diameter( u ); int nnu = nu;
				d2 = diameter( v ); int nnv = nu;
				cur = MAX( d1, MAX( d2, (d1+1)/2 + (d2+1)/2 + 1 ) );
				if( cur < ans ){
					ans = cur;
					bu = u;
					bv = v;
					bnu = nnu;
					bnv = nnv;
				}
			}
		}
		cout << ans << "\n" << bu << " " << bv << "\n" << bnu << " " << bnv << "\n";
		
	}
	return 0;
}




















