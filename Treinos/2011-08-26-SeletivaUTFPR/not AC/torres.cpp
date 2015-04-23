#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 15

vector< int > gr[2*MAXN];
int m[2*MAXN], m1[MAXN*MAXN];
int v[2*MAXN];

int dfs( int u ){
	if( u < 0 ) return 1;
	if( v[u] ) return 0;
	v[u] = 1;
	for( int i = 0, sz = int(gr[u].size()); i < sz; i++ ){
		if( dfs( m1[ gr[u][i] ] ) ){
			m[u] = gr[u][i];
			m1[gr[u][i]] = u;
			return 1;
		}
	}
	return 0;
} 

int dfsExp( int u ){
	memset( v, 0, sizeof(v) );
	return dfs( u );
}

int bipMatch(){
	int ans = 0;
	memset( m, -1, sizeof(m) );
	memset( m1, -1, sizeof(m1) );
	int aug = 0;
	do{
		ans += aug;
		aug = 0;
		bool first = true;
		for( int i = 0; i < 2*MAXN; i++ )
			if( m[i] < 0 ){
				if( first ) aug += dfsExp( i );
				else aug += dfs(i);
				first = false;
			}
	} while( aug );
	return ans;
}

int main(){
	
	ios::sync_with_stdio( false );
	
	string grid[15];
	cin >> grid[0];
	while( grid[0] != "FIM" ){
		
		for( int i = 1; i < MAXN; i++ ) cin >> grid[i]; 
		for( int i = 0; i < 2*MAXN; i++ ) gr[i].clear();
		
		int id = 0;
		for( int i = 0; i < 15; i++ )
			for( int j = 0; j < 15; j++ ){
				if( grid[i][j] == '#' ){
					gr[i].push_back( id );
					gr[15+j].push_back( id );
				}
				id++;
			}
					
		cout << bipMatch() << "\n";
		cin >> grid[0];
	}
	
	return 0;
}
