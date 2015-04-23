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
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <cstring>
#include <list>

#define MAXN 110
#define INF 0x3F3F3F3F

using namespace std;

int cost[MAXN][MAXN];
int dist[2][MAXN];
int graph[MAXN][MAXN];
int gr[MAXN];

int main(){
	
	int T, N, M;
	int u, v, c, i, j, p, ans;
	
	ios::sync_with_stdio( false );
	
	cin >> T;
	while( T-- ){
	
		cin >> N >> M;
		
		for( u = 1; u <= N; u++ ){
			gr[u] = 0;
			for( v = u; v <= N; v++ )
				cost[u][v] = cost[v][u] = INF;
		}
		
		while( M-- ){
			
			cin >> u >> v >> c;
			if( c < cost[u][v] ){
				if( cost[u][v] == INF ) { graph[u][gr[u]++] = v; graph[v][gr[v]++] = u; }
				cost[u][v] = cost[v][u] = c;
			}
			
		}
		
		priority_queue< pair< int, pair< int, int> > > q;
		ans = INF;
		
		for( u = 1; u <= N; u++ ){ 
			
			for( v = 1; v <= N; v++ ) dist[0][v] = dist[1][v] = INF;
			q.push( make_pair( 0, make_pair( u, 1 ) ) );
			dist[1][u] = 0;
				
			while( !q.empty() ){
				
				c = -q.top().first;
				v = q.top().second.first;
				p = q.top().second.second;
				q.pop();
				
				if( c > dist[p][v] ) continue;
			
				for( i = 0; i < gr[v]; i++ ){
					j = graph[v][i];
					if( dist[1-p][j] > c+cost[v][j]  ){
						dist[1-p][j] = c+cost[v][j];
						q.push( make_pair( -(c+cost[v][j]), make_pair( j, 1-p ) ) );
					}
				}
			
			}
			
			for( v = 1; v <= N; v++ )
				if( dist[1][v] + cost[v][u] < ans ) ans = dist[1][v] + cost[v][u];
			
		}
		
		if( ans == INF ) cout << "impossivel\n";
		else cout << ans << "\n";
		
	}
	
	return 0;
}
