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

struct edge_t {
	int u, v, ax;
	edge_t( int uu = 0, int vv = 0, int aa = -1 ) : u(uu), v(vv), ax(aa){}
};

#define MAXN 100100

int N;
vector< int > gr[MAXN];
edge_t edge[MAXN];
int eax[MAXN];

int bit[MAXN];

int depth[MAXN], parent[MAXN], treesz[MAXN];
int chain[MAXN], chainpos[MAXN], chainleader[MAXN];

int cur_chain, pos;

void up( int idx, int val ){
	idx++;
	while( idx <= N ){
		bit[idx] += val;
		idx += (idx&-idx);
	}
}

int get( int idx ){
	idx++;
	int res = 0;
	while( idx > 0 ){
		res += bit[idx];
		idx -= (idx&-idx);
	}
	return res;
}

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

void update( int u, int v ){
	int from, to;
doit_again:

	if( chain[u] == chain[v] ){
		from = chainpos[u];
		to = chainpos[v]-1;
		
		if( to >= from ){
			
			up( from, +1 );
			up( to+1, -1 );
		}
		
	} else {
		
		if( chainleader[ chain[v] ] == v ){
			from = chainpos[v]-1;
			to = chainpos[v]-1;
			
			up( from, +1 );
			up( to+1, -1 );
			
			v = parent[v];
		} else {
			from = chainpos[ chainleader[ chain[v] ] ];
			to = chainpos[ v ]-1;
			
			up( from, +1 );
			up( to+1, -1 );
			
			v = chainleader[ chain[v] ];
		}
		goto doit_again;
		
	}
	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	cin >> N;
	FOR( i, 1, N ){ parent[i] = -1; gr[i].clear(); }
	parent[1] = 0, depth[1] = 0;
	
	REP( i, N-1 ){
		cin >> edge[i].u >> edge[i].v;
		gr[ edge[i].u ].PB( i );
		gr[ edge[i].v ].PB( i );
	}
	
	explore(1);
	cur_chain = -1; pos = 0;
	decompose(1); parent[1] = 1;
	pos--;
	
	int k;
	cin >> k;
	while( k-- ){
		int u, v;
		cin >> u >> v;
		int lca_ft = lca(u,v);
		
		update(lca_ft,u);
		update(lca_ft,v);
	}
	
	REP( i, N-1 ){ if( i ) cout << " "; cout << get(edge[i].ax); }
	cout << "\n";
	
	return 0;
}

























