#include <iostream>
#include <queue>
#include <utility>

#define MAXV 101
#define INF 0x4FFFFFFF

using namespace std;

int fluxo[MAXV][MAXV];
int custo[MAXV][MAXV];

int parent[MAXV];
int Dist[MAXV];

int n, m;
int d, k;

int grafo[MAXV][MAXV];
int grau[MAXV];

int capacidade( int u, int v ){
    if( u == 0 || v == 0 )
        return d - fluxo[u][v];
    else
        return k - fluxo[u][v];
}

int dijkstra(){

    int u, v, w, aDist;
    
	for( u = 1; u <= n; u++){
		Dist[u] = INF;
		parent[u] = -1;
	}

	Dist[0] = 0;

	priority_queue< pair< int, int >, vector< pair< int, int> >, greater< pair< int, int> > > Q;
	Q.push( pair<int, int>( 0, 0 ) );

	while( !Q.empty() ){
           
		u = Q.top().second;
		aDist = Q.top().first;
		Q.pop();

        if( u == n ) break;

        if( aDist <= Dist[u] ){
        		for( w = 0; w != grau[u]; w++ ){
                     v = grafo[u][w];
			         if( capacidade( u, v ) > 0 ){
                         if( aDist + custo[u][v] < Dist[v] ){
                             Dist[v] = aDist + custo[u][v];
                             parent[v] = u;
                             
                             Q.push( make_pair( Dist[v], v ) );
                         }
                     }
                }
        }        
    }
    
    if( parent[n] == -1 )
        return -1;
        
    w = INF;
    u = n;
    
    while( u != 0 ){
           v = parent[u];
           
           if( capacidade( v, u ) < w )
               w = capacidade( v, u );
           
           u = v;
    }

    return w;
}

int main(){

	int instancia = 1;
    int i, u, v, w;
    int maxFlow, total;
    
    grau[0] = 0;
    grafo[0][grau[0]++] = 1;
    
	while( scanf("%d %d", &n, &m) != EOF ){

		for( u = 1; u <= n; u++ ){
            grau[u] = 0; 
			for( v = 1; v <= n; v++ )
				fluxo[u][v] = 0;
		}

        grafo[1][grau[1]++] = 0;
		for( i = 0; i < m; i++ ){

			scanf("%d %d %d", &u, &v, &w );

            grafo[u][grau[u]++] = v;
            grafo[v][grau[v]++] = u;
            
			custo[u][v] = w;
			custo[v][u] = w;
		}
        fluxo[1][0] = fluxo[0][1] = 0;
        
		scanf("%d %d", &d, &k );

		maxFlow = 0;
		while( 1 ){

            if( maxFlow == d ) break;
			w = dijkstra();

			if( w == -1 )
                break;
     
			v = n;
			while( v != 0 ){

				u = parent[v];

				fluxo[u][v] += w;
				fluxo[v][u] -= w;

				v = u;
			}

			maxFlow += w;
		}

		printf("Instancia %d\n", instancia++);
		if( maxFlow != d )
			printf("impossivel\n\n");
		else{
            total = 0;
            for( u = 1; u <= n; u++ )
                 for( v = 1; v <= n; v++)
                      if( fluxo[u][v] > 0 )  
                          total += fluxo[u][v] * custo[u][v];
            printf("%d\n\n", total );
        }

	}
	return 0;
}
