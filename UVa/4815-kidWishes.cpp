/*
 *  Problema: 
 *  Tecnica Utilizada: 
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

#define MAXV 200100
#define MAXE 100100

using namespace std;

set< int > graph[MAXV];
int parent[MAXV];
bool visited[MAXV];
int vis;

bool cycle( int u ){

	vis++; visited[u] = true;
	
	for( set<int>::iterator v = graph[u].begin(); v!= graph[u].end(); v++ ){
		if( !visited[*v] ) { 
			parent[*v] = u;
			cycle( *v );
		} else if( *v != parent[u] ) return true;
	}
	
	return false;
}

int main(){
	
	int K, W, V, a, b;
	bool degree;
	ios::sync_with_stdio( false );
	
	while( true ){
		
		cin >> K >> W;
		if( (K+W) == 0 ) return 0;
		
		if( W ){
			
			map< int, int > compressed;
			V = 0;
			while( W-- ){
				cin >> a >> b;
				if( compressed.find(a) == compressed.end() ) { compressed[a] = V; graph[V].clear(); V++; }
				if( compressed.find(b) == compressed.end() ) { compressed[b] = V; graph[V].clear(); V++; }
				a = compressed[a];
				b = compressed[b];
				graph[a].insert( b );
				graph[b].insert( a );
			}
			
			degree = true;
			for( a = 0; a < V; a++ ){
				if( graph[a].size() > 2 ) { degree = false; break; }
				visited[a] = false; parent[a] = a;
			}
		
			if( degree ){
				string ans;
				for( a = 0; a < V; a++ ){
					if( !visited[a] ){
						vis = 0;
						if( cycle( a ) ){
							if( vis == K ) { ans = "Y\n"; break; }
							else { ans = "N\n"; break; }
						} else ans = "Y\n";
					}
				}
				
				cout << ans;
				
			} else cout << "N\n";
		
		} else cout << "Y\n";
		
	}

	return 0;
}
