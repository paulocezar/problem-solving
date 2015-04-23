#include <iostream>
#include <queue>
#include <utility>
#include <list>

#define MAXV 501
#define INF 0x4FFFFFFF

using namespace std;

int peso[MAXV][MAXV];
int grafo[MAXV][MAXV];
int parents[MAXV][MAXV];

int nparents[MAXV];
int grau[MAXV];

int D[MAXV];

int n, s, t;

void dijkstra(){
     int u, v, w;
     int dist;
     
     for( u = 0; u < n; u++ ){
          nparents[u] = 0;
          D[u] = INF;
     }
     
     D[s] = 0;
     priority_queue< pair< int, int >, vector< pair< int, int> >, greater< pair< int, int > > >Q;
     Q.push( make_pair( D[s], s ) );
     
     while( !Q.empty() ){
            
            u = Q.top().second;
            dist = Q.top().first;
            Q.pop();
          
            if( dist <= D[u] ){
                for( w = 0; w < grau[u]; w++ ){
                     v = grafo[u][w];

                     if( peso[u][v] ){
                         if( dist + peso[u][v] < D[v] ){
                             
                             D[v] = dist + peso[u][v];
                             
                             nparents[v] = 0;
                             parents[v][nparents[v]++] = u;
                             Q.push( make_pair( D[v], v ) );
                             
                         }
                         else if( dist + peso[u][v] == D[v] ){
                              parents[v][nparents[v]++] = u;
                         }
                     }
                }
            }
            
     }
     
}

int resolve(){
    
    int u, v, w;

		
    dijkstra();
    if( D[t] == INF )
        return -1;
        
    list< int > rmvQ;
    rmvQ.push_back( t );
    
    while( !rmvQ.empty() ){
           
        u = rmvQ.front();
		rmvQ.pop_front();
        
        for( w = 0; w != nparents[u]; w++){
               v = parents[u][w];
               rmvQ.push_back( v );
               peso[v][u] = 0;
        }
        
        nparents[u] = 0;

	}
    
    dijkstra();
    if( D[t] == INF )
        return -1;
    else
        return D[t];
}


int main(){
    
	int m, i, u, v, w;

	while( 1 ){

        scanf("%d %d", &n, &m );
        if( n == 0 ) break;     

		for( u = 0; u < n; u++)
			grau[u] = 0;
		

		scanf("%d %d", &s, &t);
		for( i = 0; i < m; i++ ){
			scanf("%d %d %d", &u, &v, &w );
            grafo[u][grau[u]++] = v;
            peso[u][v] = w;
		}

		w = resolve();

		printf("%d\n", w );
	}
	
	return 0;
}
