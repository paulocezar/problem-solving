#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <utility>

using namespace std;

int queue[6666];
int front, back;
vector< vector< int > > g;

bool ok( string &a, string &b ){
	int x = 0;
	for( int i = 0; i < 5; i++ )
	 x += (a[i]!=b[i]);
	return (x == 1);
}

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int gr[n][n];
	bool calc[n][n];
	string wrd[n];
	bool seen[n];
	g.resize(n);

	for( int i = 0; i < n; i++ ){
		cin >> wrd[i];
		g[i].clear();	
		memset( calc[i], 0, sizeof(calc[i]) );
		memset( gr[i], 0x3F, sizeof(gr[i]) );
		calc[i][i] = 1;
		gr[i][i] = 0;
	}	
	
	for( int i = 0; i < n; i++ ) 
	for( int j = i+1; j < n; j++ )
		if( ok( wrd[i], wrd[j] ) ){
			calc[i][j] = 1, gr[i][j] = 1;
			g[i].push_back( j );
			g[j].push_back( i );	
		}
int u, v;	
	while( cin >> u >> v && (u+v) ){
		u--, v--;
		if( !calc[u][v] ){
			front = back = 0;
			queue[back++] = u;
			memset( seen, 0, sizeof(seen) );
			seen[u] = true;
			while( front != back ){
				int x = queue[front++];
				for( size_t i = 0, sz = g[x].size(); i < sz; i++ ){
					int y = g[x][i];
					if( !seen[y] ){
						gr[u][y] = gr[u][x]+1;
						seen[y] = true;
						queue[back++] = y;
					}
				}
			}
			for( int i = 0; i < n; i++ )
				calc[u][i] = 1;
		}
		if( gr[u][v] == 0x3F3F3F3F ) cout << "Desconexo\n";
		else cout << gr[u][v] << "\n";
	}

	return 0;
}

