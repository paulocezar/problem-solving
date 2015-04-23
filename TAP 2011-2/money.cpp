#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MAXM 50000
#define MAXN 10001

int m, n;
int pa[MAXN], rk[MAXN], val[MAXN];

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

void fUnion( int x, int y ){
	int px = find(x);
	int py = find(y);
	if( px == py ) return;
	if( rk[px] < rk[py] ) swap(px,py);
	pa[py] = px;
	val[px] += val[py];
	if( rk[px] == rk[py] ) rk[px]++; 
}

int main(){
	ios::sync_with_stdio(false);
	
	int u,v;
	
	while( cin >> n >> m && (m+n) ){
		for( int i = 0; i < n; i++ ){
			pa[i] = i, rk[i] = 0;
			cin >> val[i];
		}
		
		for( int i = 0; i < m; i++ ){
			cin >> u >> v;
			fUnion(u,v);
		}
			
		bool possible = true;
		for( int i = 0; possible && i < n; i++ ) if( pa[i] == i ){
			if( val[i] != 0 ) possible = false;
		}
		if( !possible ) cout << "IM";
		cout << "POSSIBLE\n";
		
	}

	return 0;
}

