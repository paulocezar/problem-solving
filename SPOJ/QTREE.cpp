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

#define MAXN 10100

inline int next_int() {
	int n = 0, neg = 1;
	char c = getchar_unlocked();
	if( c == EOF ) exit(0);
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
		if( c == EOF ) exit(0);
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return neg*n;
}

struct edge_t {
	int u, v, c, ax;
	edge_t( int uu = 0, int vv = 0, int cc = 0 ) : u(uu), v(vv), c(cc) { ax = -1; };
};

int N;
vector< int > gr[MAXN];
edge_t edge[MAXN];
int eax[MAXN];

int segt[1<<15];

int depth[MAXN], parent[MAXN], treesz[MAXN];
int chain[MAXN], chainpos[MAXN], chainleader[MAXN];

int cur_chain, pos;

void explore( int u ){
	int v;
	treesz[u] = 1;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = edge[ gr[u][i] ].u + edge[ gr[u][i] ].v - u;
		if( parent[ v ] == -1 ){
			parent[ v ] = u;
			depth[ v ] = depth[ u ]+1;
			explore( v );
			treesz[ u ] += treesz[ v ];
		}
	}
}

void decompose( int u, bool light = true ){
	if( light ){
		++cur_chain;
		chainleader[ cur_chain ] = u;
	}
	
	chain[ u ] = cur_chain;
	chainpos[ u ] = pos++;
	
	int v, ind = -1, mx = -1;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = edge[ gr[u][i] ].u + edge[ gr[u][i] ].v - u;
		if( parent[ v ] == u && (mx == -1 || treesz[mx] < treesz[v]) )
			mx = v, ind = i;
	}
	
	if( mx != -1 ){
		eax[ pos-1 ] = gr[u][ind];
		edge[ gr[u][ind] ].ax = pos-1;
		decompose( mx, false );
	}
	
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = edge[ gr[u][i] ].u + edge[ gr[u][i] ].v - u;
		if( parent[ v ] == u && v != mx ){
			eax[ pos-1 ] = gr[u][i];
			edge[ gr[u][i] ].ax = pos-1;
			decompose( v );
		}
	}		
}

namespace heavy_light{
	int lca( int u, int v ){
		while( chain[u] != chain[v] ){
			if( depth[ chainleader[chain[u]] ] < depth[ chainleader[chain[v]] ] )
				v = parent[ chainleader[ chain[v] ] ];
			else
				u = parent[ chainleader[ chain[u] ] ];
		}
		if( depth[u] < depth[v] ) return u;
		return v;
	}
}

void build( int node, int lo, int hi ){
	if( lo == hi ){
		segt[node] = edge[ eax[lo] ].c;
	} else {
		int ls = (node<<1) + 1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
		segt[node] = max( segt[ls], segt[rs] );
	}
}

int from, to;
void update( int node, int lo, int hi ){
	if( lo == hi && lo == from ){
		edge[ eax[lo] ].c = to;
		segt[node] = to;
	} else {
		int ls = (node<<1) + 1;
		int rs = ls + 1;
		int mid = (lo+hi)>>1;
		if( lo <= from && from <= mid) update( ls, lo, mid );
		if( mid+1 <= from && from <= hi ) update( rs, mid+1, hi );
		segt[node] = max( segt[ls], segt[rs] );
	}
}

int query( int node, int lo, int hi ){
	if( from <= lo && hi <= to )
		return segt[node];
	
	int ls = (node<<1) + 1;
	int rs = ls + 1;
	int mid = (lo+hi)>>1;
	if( mid+1 > to ) return query( ls, lo, mid );
	if( mid < from ) return query( rs, mid+1, hi );
	
	return max( query( ls, lo, mid ), query( rs, mid+1, hi ) );
}

int query( int u, int v ){
	int ans = -INF;
doit_again:

	if( chain[u] == chain[v] ){
		from = chainpos[u];
		to = chainpos[v]-1;
		
		if( to >= from ) ans = max( ans, query(0, 0, pos) );
	
	} else {
		
		if( chainleader[ chain[v] ] == v ){
			ans = max( ans, edge[ eax[chainpos[v]-1] ].c );
			v = parent[v];
		} else {
			from = chainpos[ chainleader[ chain[v] ] ];
			to = chainpos[ v ]-1;
			ans = max( ans, query(0, 0, pos) );
			v = chainleader[ chain[v] ];
		}
		goto doit_again;
		
	}
	return ans;	
}

int main( int argc, char* argv[] ){
	
	int t, a, b;
	char wut[10];
	
	t = next_int();
	while( t-- ){
		
		N = next_int();
		FOR( i, 1, N ){ parent[i] = -1; gr[i].clear(); }
		parent[1] = 0; depth[1] = 0;
		
		REP( i, N-1 ){
			edge[i].u = next_int();
			edge[i].v = next_int();
			edge[i].c = next_int();
			gr[ edge[i].u ].PB( i );
			gr[ edge[i].v ].PB( i );
		}
		
		explore( 1 );
		cur_chain = -1; pos = 0;
		decompose( 1 ); parent[1] = 1;
		pos--;
		
		build( 0, 0, pos );
				
	play:
		wut[0] = getchar_unlocked();
		while( 'A' > wut[0] || wut[0] > 'Z' ) wut[0] = getchar_unlocked();
		a = 0;
		do{
			wut[++a] = getchar_unlocked();
		} while( 'A' <= wut[a] && wut[a] <= 'Z' );
		
		if( wut[0] != 'D' ){
			a = next_int();
			b = next_int();
			if( wut[0] == 'Q' ){
				int lca_ft = heavy_light::lca( a, b );
				int ans = max( query( lca_ft, a ), query( lca_ft, b ) );
				printf("%d\n", ans );
			} else {
				from = edge[ a-1 ].ax;
				to = b;
				update( 0, 0, pos );
			}
			goto play;
		}
		if( t ) puts("");
	
	}
	
	return 0;
}




















