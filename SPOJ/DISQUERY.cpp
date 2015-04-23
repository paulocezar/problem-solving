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

inline void read_int( int &n ) {
	n = 0;
	bool neg = false;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = true;
		c = getchar_unlocked();
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	n = (neg ? (-n) : (n));
}


struct edge_t{
	int v, c;
	edge_t( int vv = 0, int cc = 0 ) : v(vv), c(cc){}
};

#define MAXN 100001

int N, parent[MAXN], L[MAXN], dis[MAXN], dp[17][MAXN], mn[17][MAXN], mx[17][MAXN];
vector< edge_t > gr[MAXN];

int lcamn, lcamx;
int lca( int u, int v ){
	if( L[u] < L[v] ){
		u ^= v; v ^= u; u ^= v;
	}
		
	int lg;
	for( lg = 1; (1<<lg) <= L[u]; lg++ );
	lg--;
	
	for( int i = lg; i >= 0; i-- )
		if( L[u] - (1<<i) >= L[v] ){
			lcamn = min(lcamn, mn[i][u] );
			lcamx = max(lcamx, mx[i][u] );
			u = dp[i][u];
		}
		
	if( u == v ) return u;
	for( int i = lg; i >= 0; i-- )
		if( dp[i][u] != -1 && dp[i][u] != dp[i][v] ){
			lcamn = min(lcamn, mn[i][u] );
			lcamx = max(lcamx, mx[i][u] );
			
			lcamn = min(lcamn, mn[i][v] );
			lcamx = max(lcamx, mx[i][v] );

			u = dp[i][u];
			v = dp[i][v];
		}
	lcamn = min( lcamn, min(dis[u]-dis[parent[u]],dis[v]-dis[parent[u]]) );
	lcamx = max( lcamx, max(dis[u]-dis[parent[u]],dis[v]-dis[parent[u]]) );			
	return parent[u];
}

int main( int argc, char* argv[] ){
	
	int  u, v, c, k;
	
	read_int(N);
	
	FOR( i, 1, N ){ gr[i].clear(); parent[i] = -1; }
	REP( i, N-1 ){
		read_int(u);
		read_int(v);
		read_int(c);
		gr[u].PB( edge_t(v,c) );
		gr[v].PB( edge_t(u,c) );
	}
	
	parent[1] = 0; dis[1] = 0; L[1] = 0;
	queue< int > q; q.push( 1 );
	while( !q.empty() ){
		u = q.front(); q.pop();
		REP( i, SIZE(gr[u]) ){
			v = gr[u][i].v;
			c = gr[u][i].c;
			if( parent[v] == -1 ){
				parent[v] = u;
				dis[v] = dis[u]+c;
				L[v] = L[u]+1;
				q.push( v );
			}
		}
	}
	parent[1] = -1;
	
	for( int lg = 0; (1<<lg) < N; lg++ )
		FOR( i, 1, N ) dp[lg][i] = -1;
	
	FOR( i, 1, N ){
		dp[0][i] = parent[i];
		if( parent[i] != -1 ){
			mn[0][i] = dis[i]-dis[parent[i]];
			mx[0][i] = dis[i]-dis[parent[i]];
		}
	}
	
	for( int lg = 1; (1<<lg) < N; lg++ )
		FOR( i, 1, N ) if( dp[lg-1][i] != -1 ){
			dp[lg][i] = dp[lg-1][ dp[lg-1][i] ];
			mn[lg][i] = min( mn[lg-1][i], mn[lg-1][ dp[lg-1][i] ] );
			mx[lg][i] = max( mx[lg-1][i], mx[lg-1][ dp[lg-1][i] ] );
		}
	
	read_int(k);
	
	while( k-- ){
		read_int(u);
		read_int(v);
		lcamn = INF;
		lcamx = -1;
		lca(u,v);
		printf("%d %d\n", lcamn, lcamx );
	}	
	
	return 0;
}















