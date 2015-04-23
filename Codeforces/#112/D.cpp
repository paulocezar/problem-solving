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


inline int next_int() {
	int n = 0, neg = 1;
	char c = getchar();
	if( c == EOF ) exit(0);
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar();
		if( c == EOF ) break;
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar();
	}
	return neg*n;
}

#define MAXN 100100

int N;
vector< pair<int,int> > gr[MAXN];

int eid[MAXN];
int edg[MAXN];

int segt[1<<18];

int depth[MAXN], parent[MAXN], treesz[MAXN];
int chain[MAXN], chainpos[MAXN], chainleader[MAXN];

int cur_chain, pos;

void explore( int u ){
	int v;
	treesz[u] = 1;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = gr[u][i].first;	
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
		v = gr[u][i].first;
		if( parent[ v ] == u && (mx == -1 || treesz[mx] < treesz[v]) )
			mx = v, ind = i;
	}
	
	if( mx != -1 ){
		eid[ gr[u][ind].second ] = pos-1;
		decompose( mx, false );
	}
	
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = gr[u][i].first;
		if( parent[ v ] == u && v != mx ){
			eid[ gr[u][i].second ] = pos-1;
			decompose( v );
		}
	}		
}

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

int from, to;
void update( int node, int lo, int hi ){
	if( lo == hi && lo == from ){
		edg[lo] = !edg[lo];
		segt[node] = !segt[node];
	} else {
		int ls = (node<<1) + 1;
		int rs = ls + 1;
		int mid = (lo+hi)>>1;
		if( lo <= from && from <= mid) update( ls, lo, mid );
		if( mid+1 <= from && from <= hi ) update( rs, mid+1, hi );
		segt[node] = (segt[ls] || segt[rs]);
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
	
	return ( query( ls, lo, mid ) || query( rs, mid+1, hi ) );
}

int query( int u, int v ){
	int ans = 1;
doit_again:
	if( !ans ) return 0;
	if( chain[u] == chain[v] ){
		from = chainpos[u];
		to = chainpos[v]-1;
		
		if( to >= from ) ans = ans && !query(0, 0, pos);
		
	} else {
		
		if( chainleader[ chain[v] ] == v ){
			ans = ans && !edg[ chainpos[v]-1 ];
			v = parent[v];
		} else {
			from = chainpos[ chainleader[ chain[v] ] ];
			to = chainpos[ v ]-1;
			ans = ans && !query(0, 0, pos);
			v = chainleader[ chain[v] ];
		}
		goto doit_again;
		
	}
	return ans;	
}

int main( int argc, char* argv[] ){
	
	
	N = next_int();
	FOR( i, 1, N ){ gr[i].clear(); parent[i] = -1; }
	
	int u, v;
	REP( i, N-1 ){
		u = next_int();
		v = next_int();
		gr[u].PB( MP(v,i+1) );
		gr[v].PB( MP(u,i+1) );
	}	
	
	int idmx, mx = -1;
	FOR( i, 1, N ) if( SIZE(gr[i]) > mx ){
		mx = SIZE(gr[i]);
		idmx = i;
	} 
	
	parent[idmx] = 0; depth[idmx] = 0;
	explore( idmx );
	cur_chain = -1; pos = 0;
	decompose( idmx ); parent[idmx] = idmx;
	pos--;
	
	
	int m = next_int();
	while( m-- ){
		int type = next_int();
		if( type == 1 || type == 2 ){
			u = next_int();
			from = eid[u];
			update(0,0,pos);
		} else {
			u = next_int();
			v = next_int();
			int lc = lca(u,v);
			
			if( query(lc,u) && query(lc,v) ) printf("%d\n",(depth[u]+depth[v]-2*depth[lc]));
			else puts("-1");
		}
	}
	
	return 0;
}

























