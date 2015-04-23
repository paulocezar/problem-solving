#include <stdio.h>
#include <stdlib.h>

#define MAXV 10005

int graph[MAXV][MAXV];
int degree[MAXV];
int list[MAXV];
char used[MAXV];
int answer;

void dfs( int u ){

     int v;
     used[u] = 1;
     answer++;
     
     for(  v = 0; v < degree[u]; v++ )
           if( !used[graph[u][v]] ) dfs( graph[u][v] );
           
}   
     

int main(){
    
    int cases, i, n, m, l, u, v;
    
    scanf("%d", &cases );
    while( cases-- ){
           scanf("%d %d %d", &n, &m, &l );
 
           for( i = 1; i <= n; i++ )
                degree[i] = used[i] = 0;
                
           for( i = 0; i < m; i++ ){
                scanf("%d %d", &u, &v );
                graph[u][degree[u]++] = v;
           }
           
           for( i = 0; i < l; i++ )
                scanf("%d", &list[i] );
           
           answer = 0;
           for( i= 0; i < l; i++ )
                if( !used[list[i]] ) dfs( list[i] );
                               
           printf("%d\n", answer );
                               
    }

    return 0;    
}
