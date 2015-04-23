#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MAXM 200000

struct edge_t{
	int u, v, c;
	bool operator < (const edge_t& a) const {
		if( c != a.c ) return c < a.c;
		if( u != a.u ) return u < a.u;
		return v < a.v;
	} 
};

int m, n;
edge_t edge[MAXM];
int pa[MAXM], rk[MAXM];

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

int main(){
	ios::sync_with_stdio(false);
	
	while( cin >> m >> n && (m+n) ){
		for( int i = 0; i < m; i++ ) pa[i] = i, rk[i] = 0;
		for( int i = 0; i < n; i++ ) cin >> edge[i].u >> edge[i].v >> edge[i].c;
		int total = 0;
		int intree = 0;
		sort( edge, edge+n );
		for( int i = 0; i < n; i++ ){
			total += edge[i].c;
			if( fUnion(edge[i].u, edge[i].v) )
				intree += edge[i].c;
		}
		cout << total-intree << "\n";
	}

	return 0;
}

