/*
 *  Problema: 
 *  Tecnica Utilizada: 
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <cstring>
#include <iostream>
#include <list>

#define MAXN 100100

using namespace std;

list< int > grafo[MAXN];
bool visited[MAXN];
bool pick[MAXN];
int ans;

bool dfs( int u, int par ){
	
	bool leaf = true;
	visited[u] = true;
	
	for( list< int >::iterator v = grafo[u].begin(); v != grafo[u].end(); v++ ){
		 if( *v != par && ( !visited[*v] || !pick[*v] ) ){
			leaf = false;
			 if( dfs( *v, u ) ){
				 if( !pick[u] ){
					ans++;
					pick[u] = true;
				 }
			 }
		 }
	}
	
	if( leaf ) pick[u] = true;
	return leaf;
	
}


int main(){

	int N, i, u, v;
	
	ios::sync_with_stdio( false );
	
		cin >> N;
		
		i = 1;
		while( i < N ){
			i++;
			cin >> u >> v;
			grafo[u].push_back( v );
			grafo[v].push_back( u );
		}
		
		ans = 0;
		for( i = 1; i <= N; i++ ) visited[i] = pick[i] = false;
		for( i = 1; i <= N; i++ ) if( !pick[i] ) dfs( i, 0 );
		
		cout << ans << "\n";
		
		
	return 0;
}
