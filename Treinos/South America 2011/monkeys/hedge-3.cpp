#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXR 10100
#define MAXC 100100

vector< int > gr[MAXR];
int uu[MAXC], vv[MAXC];

int low[MAXR], lbl[MAXR], parent[MAXR];
int dfsnum;
set< pair<int,int> > brid;

void dfs( int u ){
	int v;
	low[u] = lbl[u] = dfsnum++;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = gr[u][i];
		if( lbl[v] == -1 ){
			parent[v] = u;
			dfs( v );
			
			if( low[v] > lbl[u] )
				brid.insert( make_pair(min(u,v), max(u,v)) );
				
			low[u] = min( low[u], low[v] );
			
		} else if( v != parent[u] ) low[u] = min( low[u], lbl[v] );		
	}
}

int pa[MAXR], rk[MAXR];
int find( int u ){
	int pp = u, ax;
	while( pp != pa[pp] ) pp = pa[pp];
	while( u != pp ){
		ax = pa[u];
		pa[u] = pp;
		u = ax;
	}
	return pp;
}

void fUnion( int x, int y ){
	int px = find( x );
	int py = find( y );
	if( px == py ) return;
	if( rk[px] < rk[py] ) swap(px,py);
	pa[py] = px;
	if( rk[px] == rk[py] ) rk[px]++;
}

int main(){
	ios::sync_with_stdio(false);
	
	int R, C, Q, u, v;
	
	cin >> R >> C >> Q;
	while( (R+C+Q) ){
	
		for( int i = 1; i <= R; i++ ){
			gr[i].clear();
			pa[i] = i;
			rk[i] = 0;
			lbl[i] = -1;
			low[i] = -1;
			parent[i] = -1;
		}
		
		for( int i = 0; i < C; i++ ){
			cin >> uu[i] >> vv[i];
			
			gr[ uu[i] ].push_back( vv[i] );
			gr[ vv[i] ].push_back( uu[i] );
		}
		
		dfsnum = 0;
		brid.clear();
		for( int i = 1; i <= R; i++ ) if( lbl[i] == -1 ) dfs( i );
		
		
		for( int i = 0; i < C; i++ ){
			u = min( uu[i], vv[i] );
			v = max( uu[i], vv[i] );
			if( brid.find( make_pair(u,v) ) != brid.end() )
				fUnion( u, v ); 
		}
		
		for( int i = 0; i < Q; i++ ){
			cin >> u >> v;

			if( find(u) != find(v) ) cout << "N\n";
			else cout << "Y\n";
		}		
		
		cout << "-\n";
		cin >> R >> C >> Q;			
	}
	return 0;
}

