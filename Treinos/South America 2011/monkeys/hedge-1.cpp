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

bool seen[MAXR];
int reach[MAXR];

int s, t;

void dfs( int u, int pr ){
	
	int v;
	seen[u] = true;
	if( u == t ) return;
	
	int acum = 0;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
			v = gr[u][i];
			if( v != pr ){
				if( !seen[v] ){
					dfs( v, u );
					acum += reach[v];
				} else acum += reach[v];
			}
	}
	reach[u] = acum;
		
}

int main(){
	ios::sync_with_stdio(false);
	
	int R, C, Q, u, v;
	
	memset( seen, false, sizeof(seen) );
	
	cin >> R >> C >> Q;
	while( (R+C+Q) ){
	
		for( int i = 1; i <= R; i++ ) gr[i].clear();
		
	
		for( int i = 0; i < C; i++ ){
			cin >> u >> v;
			gr[ u ].push_back( v );
			gr[ v ].push_back( u );
		}
		
		for( int i = 0; i < Q; i++ ){
			cin >> s >> t;

			for( int j = 1; j <= R; j++ ){ seen[j] = false; reach[j] = 0; }
			
			seen[t] = true;
			reach[t] = 1;
			dfs( s, -1 );
			
			
			if( reach[ s ] != 1 ) cout << "N\n";
			else cout << "Y\n";
		}		
		
		cout << "-\n";
		cin >> R >> C >> Q;			
	}
	return 0;
}

