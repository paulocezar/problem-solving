#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <iomanip>

typedef long long int64;

using namespace std;

#define MAXN 10000

struct edge_t{
	int u, v; int64 c;
	edge_t(int uu = 0, int vv = 0, int64 cc = 0) : u(uu), v(vv), c(cc) {} 
	bool operator < (const edge_t& a) const {
		if( c != a.c ) return c < a.c;
		if( u != a.u ) return u < a.u;
		return v < a.v;
	} 
};

int pa[MAXN], rk[MAXN];

int find( int x ){
	int p = x, ax;
	while( p != pa[p] ) p = pa[p];
	while( x != p ){
		ax = pa[x];
		pa[x] = p;
		x = ax;
	}
	return x;
}	

bool fUnion( int x, int y ){
	int px = find(x);
	int py = find(y);
	if( px == py ) return false;
	if( rk[px] < rk[py] ) swap(px,py);
	pa[py] = px;
	if( rk[px] == rk[py] ) rk[px]++; 
	return true;
}

vector< edge_t > edge;
int64 x[MAXN+1], y[MAXN];

int main(){
	ios::sync_with_stdio(false);
	
	int w, m, n;
	int64 dx, dy;
	
	cin >> w;
	while( w-- ){
		cin >> m;
		
		n = 0;
		while( cin >> x[n] && (x[n] != -1) ){
			cin >> y[n]; n++;
		}
		
		for( int i = 0; i < n; i++ ) pa[i] = i, rk[i] = 0;
		
		edge.clear();
		for( int i = 0; i < n; i++ )
			for( int j = i+1; j < n; j++ ){
				dx = x[i]-x[j];
				dy = y[i]-y[j];
				edge.push_back( edge_t( i, j, dx*dx + dy*dy ) );
			}
			
		sort( edge.begin(), edge.end() );
		int E = int( edge.size() );
		
		long long need = 0;
		for( int i = 0; i < E; i++ ){
			if( n <= m ) break;
			if( fUnion(edge[i].u, edge[i].v) ){
				need = edge[i].c;
				n--;
			}
		}
		
		cout << fixed << setprecision(0) << ceil( sqrt(need) ) << "\n";
	}

	return 0;
}

