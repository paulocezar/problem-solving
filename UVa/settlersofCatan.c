#include <stdio.h>
#include <stdlib.h>

#define MAXV 26
#define MAXDEG 3


char used[MAXV][MAXV];
int graph[MAXV][MAXDEG];
int deg[MAXV];
int n, max;

void dfs( int u, int prof ){
     
     if( prof > max ) max = prof;
     
     int w, v;
     for( w = 0; w < deg[u]; w++ ){
          v = graph[u][w];
          if( !used[u][v] ){
              used[u][v] = used[v][u] = 1;
              dfs( v, prof + 1 );
              used[u][v] = used[v][u] = 0;
          }
     }
     
}

int main(){
    
    int m, u, v, i;
    
    while( 1 ){
           
           scanf("%d %d", &n, &m );
           if( (n+m) == 0 ) return 0;
           
           memset( deg, 0, sizeof( int ) * n );
           
           for( i = 0; i < m; i++ ){
                scanf("%d %d", &u, &v );
                graph[u][deg[u]++] = v;
                graph[v][deg[v]++] = u;
           }
           
           max = 0;
           for( u = 0; u < n; u++ )
                dfs( u, 0 );
                
           printf("%d\n", max );
           
           
    }
    
    return 0;
    
}
