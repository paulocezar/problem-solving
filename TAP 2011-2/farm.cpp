#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int e[10], we[10];

struct fakeedge_t{
	int u, v, pen;
	fakeedge_t( int uu = 0, int vv = 0, int pp = 0 ) :
			u(min(uu,vv)), v(max(uu,vv)), pen(pp) {}
	bool operator < (const fakeedge_t& e) const {
		if( u != e.u ) return u < e.u;
		if( v != e.v ) return v < e.v;
		return pen < e.pen;
	}
	bool operator == (const fakeedge_t& e ) const {
		return ((u == e.u) && (v == e.v));
	}
};

struct edge_t{
	int u, v, w;
	edge_t( int uu = 0, int vv = 0, int ww = 0 ) :
		u(uu), v(vv), w(ww) {}
	bool operator < (const edge_t& e ) const{
		if( w != e.w ) return w < e.w;
		if( u != e.u ) return u < e.u;
		return v < e.v;
	}
};

int cost[1010][1010];

#define MAXN 111
int pa[MAXN], rk[MAXN];

int find( int u ){
	int pu = pa[u];
	while( pu != pa[pu] ) pu = pa[pu];
	int aux;
	while( u != pu ){
		aux = pa[u];
		pa[u] = pu;
		u = aux;
	}
	return pu;
}

int fUnion( int x, int y ){
	int px = find(x);
	int py = find(y);
	if( px == py ) return 0;
	if( rk[px] < rk[py] ) swap( px, py );
	pa[py] = px;
	if( rk[px] == rk[py] ) rk[px]++;
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	
	int t, n, ep, u, v;
	cin >> t;
	while( t-- ){
		cin >> n;
		vector< fakeedge_t > fakeedge;
		for( int i = 0; i < n; i++ ){
			pa[i] = i; rk[n] = 0;
			cin >> ep;
			for( int j = 0; j < ep; j++ )
					cin >> e[j];
			for( int j = 0; j < ep; j++ )
					cin >> we[j];
			for( int j = 0; j < ep; j++ ){
				u = e[j]; v = e[(((j+1)<ep)?(j+1):(0))];
				cost[u][v] = cost[v][u] = we[j];
				fakeedge.push_back( fakeedge_t( u, v, i ) );
			}
		}
		pa[n] = n; rk[n] = 0;

		sort( fakeedge.begin(), fakeedge.end() );
		vector< edge_t > edge;
		for( size_t i = 0, sz = fakeedge.size(); i < sz; i++ ){
			if( fakeedge[i] == fakeedge[i+1] ){
				edge.push_back( 
						edge_t( 
								fakeedge[i].pen, 
								fakeedge[i+1].pen,
								cost[fakeedge[i].u][fakeedge[i].v]  )
							);
				i++;
			} else { 
				edge.push_back( 
						edge_t( fakeedge[i].pen,
								n,
								cost[fakeedge[i].u][fakeedge[i].v]  )
							  );
			}
		}

		sort( edge.begin(), edge.end() );
		int ans = 0, used = 0;
		for( size_t i = 0, sz = edge.size(); i < sz; i++ ){
			if( fUnion( edge[i].u, edge[i].v ) ){
				ans += edge[i].w;
				used++;
			}
			if( used == n-1 && pa[n] == n ) break;
			if( used == n ) break;
		}
		cout << ans << "\n";
	}

	return 0;
}

