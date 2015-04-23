#include <iostream>
#include <list>
#include <queue>

using namespace std;

typedef pair< int, int > edge;
typedef pair< int, edge > vedge;

#define value first
#define from second.first
#define to second.second

int graph[300][300];
int with[300];
int N;

int main(){
	
	char trash;
	int u, v, nv, count;
	vedge cur;
	
	while( cin >> N ){
	
		count = 2;
		for( u = 1; u <= N; u++ ){
			for( v = u; v <= N; v++ )
				graph[u][v] = graph[v][u] = count++;
			graph[u][u] = 0;
		}
		
		while( scanf("%d %d", &u, &v) == 2 ){	
			graph[u][v] = graph[v][u] = 1;
		}
		
		cin >> trash;
		priority_queue< vedge > Q;
		
		for( u = 2; u <= N; u++ ){
			Q.push( vedge( graph[u-1][u], edge( u-1, u ) )  );
			with[u-1] = u;
		}
		Q.push( vedge( graph[N][1], edge( N, 1 ) ) );
 		with[N] = 1;
		
		while( !Q.empty() ){
			cur = Q.top(); Q.pop();
			if( cur.value == 1 ) break;
			u = cur.from; v = cur.to;
			if( !graph[u][v] ) continue;
			graph[u][v] = graph[v][u] = 0;
			
			for( nv = 1; nv <= N; nv++ ){
				if( graph[with[nv]][v] && graph[nv][u] && graph[u][with[nv]] ){
					Q.push( vedge( graph[with[nv]][v], edge( with[nv], v ) ) );
					Q.push( vedge( graph[u][with[nv]], edge( u, with[nv] ) ) );
					Q.push( vedge( graph[nv][u], edge( nv, u ) ) );
					with[with[nv]] = v;
					with[u] = with[nv];
					with[nv] = u;
				}
			}
		
		}	
		
		cout << 1;
		u = 1;
		while( with[u] != 1 ) { cout << " " << with[u]; u = with[u]; }
		cout << " 1\n";		
	
	}

	return 0;
}
