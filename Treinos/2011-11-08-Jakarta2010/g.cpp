#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 50100
#define LGMN 16

vector< int > gr[MAXN];

int N, curchain, curpos;
int treesize[MAXN], parent[MAXN], depth[MAXN];
int chain[ MAXN ], chainleader[ MAXN ], chainpos[ MAXN ];

int st[LGMN+1][ MAXN ];

void explore( int u ){
	treesize[u] = 1;
	int v;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = gr[u][i];
		if( parent[v] == -1 ){
			parent[v] = u;
			depth[v] = depth[u]+1;
			explore( v );
			treesize[u] += treesize[v];
		}
	}
}

void decompose( int u, bool light = true ){
	if( light ){
		++curchain;
		chainleader[ curchain ] = u;
	}
	
	chain[ u ] = curchain;
	chainpos[ u ] = curpos++;
	
	int v, mx = -1;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = gr[u][i];
		if( parent[v] == u && (mx == -1 || treesize[v] > treesize[mx]) ) mx = v;
	}
	if( mx != -1 ) decompose( mx, false );
	
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = gr[u][i];
		if( parent[v] == u && v != mx ) decompose( v );
	}
}

int getlca( int u, int v ){
	if( depth[u] < depth[v] ) swap( u, v );
	
	int lg;
	for( lg = 1; (1<<lg) <= depth[u]; lg++ );
	lg--;
	
	for( int k = lg; k >= 0; k-- ) if( depth[u] - (1<<k) >= depth[v] )
		u = st[ k ][ u ];
	
	if( u == v ) return u;	
	for( int k = lg; k >= 0; k-- ) if( st[k][u] != -1 && (st[k][u] != st[k][v]) )
		u = st[k][u], v = st[k][v];
	return parent[u];
}

int segt[1<<(LGMN+1)];

void build( int node, int lo, int hi ){
	if( lo == hi ) segt[node] = 0;
	else {
		int ls = (node<<1)+1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		segt[node] = 0;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
	}
}

int vertex;
int query( int node, int lo, int hi ){
	if( lo == hi ) return segt[node];
	else{
		int ls = (node<<1)+1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		
		segt[ls] += segt[node];
		segt[rs] += segt[node];
		segt[node] = 0;
		
		if( lo <= vertex && vertex <= mid ) return query( ls, lo, mid );
		return query( rs, mid+1, hi );
	}
}

int from, to, inc;
void update( int node, int lo, int hi ){
	if( hi < from || lo > to ) return;
	
	if( from <= lo && hi <= to ){
		segt[node] += inc;
	} else {
		int ls = (node<<1)+1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		segt[ls] += segt[node];
		segt[rs] += segt[node];
		segt[node] = 0;
		update( ls, lo, mid );
		update( rs, mid+1, hi );
	}
}


void update( int u, int v ){
	
	while( true ){	
			
		if( chain[u] == chain[v] ){
			from = chainpos[ v ];
			to = chainpos[ u ];
			update( 0, 0, N-1 );
			return;
		} else {
			
			if( chainleader[ chain[u] ] == u ){
				from = chainpos[ u ];
				to = from;
				update(0,0,N-1);
				u = parent[u];
			} else {
				from = chainpos[ chainleader[ chain[u] ] ]+1;
				to = chainpos[ u ];
				if( from <= to ) update(0,0,N-1);
				u = chainleader[ chain[u] ];
			}
		}
		
		
	}	
	
}

int main(){
	ios::sync_with_stdio(false);
	
	int t, u, v, lca, Q;
	
	cin >> t;
	for( int tc = 1; tc <= t; tc++ ){
		
		cin >> N;
		for( int i = 0; i < N; i++ ){
			gr[i].clear(); parent[i] = -1;
		}
		
		for( int i = 0; i < N-1; i++ ){
			cin >> u >> v;
			gr[u].push_back( v );
			gr[v].push_back( u );
		}
		
		parent[0] = 0; depth[0] = 0;
		explore( 0 );
		
		curchain = -1;
		curpos = 0;
		decompose( 0 );
		
		build( 0, 0, N-1 );
		
		parent[0] = -1;
		for( int i = 0; (1<<i) < N; i++ ) for( int j = 0; j < N; j++ ) st[i][j] = -1;
		for( int j = 0; j < N; j++ ) st[ 0 ][ j ] = parent[j];
		
		for( int i = 1; (1<<i) < N; i++ ) for( int j = 0; j < N; j++ ) if( st[i-1][j] != -1 ){
			st[i][j] = st[ i-1 ][ st[i-1][j] ];
		}
		
		cin >> Q;
		while( Q-- ){
			cin >> u >> v >> inc;
			lca = getlca( u, v );
			//cout << u << " .. " << v << " -- " << lca << endl;
			update( u, lca );
			update( v, lca );
			inc = -inc;
			update( lca, lca );		
		}
		cout << "Case #" << tc << ":\n";
		for( int i = 0; i < N; i++ ){
			vertex = chainpos[ i ];
			cout << query(0,0,N-1) << "\n";
		}
	}
	
	return 0;
}

