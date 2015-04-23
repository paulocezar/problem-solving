#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 10005

int graph[MAXV][MAXV];
int degree[MAXV];

int list[MAXV];
char used[MAXV];

int n, ans, end;

void topologicSort( int u ){
     
     int v;
     used[u] = 1;
     
     for( v = 0; v < degree[u]; v++ )
          if( !used[graph[u][v]] ) topologicSort( graph[u][v] );
     
     list[end--] = u; 
}


void dfs( int u ){
     
     int v;
     used[u] = 0;

     for( v = 0; v < degree[u]; v++ )
          if( used[graph[u][v]] ) dfs( graph[u][v] );

}

int main(){

    int cases, m, u, v, i, x;
    
    scanf("%d", &cases );
    for( x = 1; x <= cases; x++ ){
     
           scanf("%d %d", &n, &m );
           memset( degree+1, 0, sizeof( int ) * n );
                      
           for( i = 0; i < m; i++ ){
                scanf("%d %d", &u, &v );
                graph[u][degree[u]++] = v;
           }
           
           ans = 0;
           memset( used+1, 0, sizeof( char ) * n );

           end = n-1;
           for( u = 1; u <= n; u++ )
                if( !used[u] ) topologicSort( u );
          
           for( u = 0; u < n; u++ ){
                if( used[list[u]] ){
                    ans++;
                    dfs( list[u] );
                }        
           }
          
          printf("Case %d: %d\n", x, ans );
    }    
    
    return 0;
}
