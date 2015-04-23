#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 200

int degree[MAXV];
int graph[MAXV][MAXV];
int queue[MAXV];
char color[MAXV];
int n, m, bgn, end;

char bicolorable( ){
 
    int u, v; 
    memset( color, 2, sizeof( char ) * n );
    
    bgn = end = 0;
    queue[end++] = 0;
    color[0] = 1;
    
    while( bgn != end ){
           u = queue[bgn++];
           for( v = 0; v < degree[u]; v++ ){
                if( color[graph[u][v]] == 2 ){
                    color[graph[u][v]] = 1 - color[u];
                    queue[end++] = graph[u][v];
                } else if( color[graph[u][v]] == color[u] )
                    return 0;
           }
    }
    
    return 1;
         
}

int main(){
    
    int i, u, v;
    
    scanf("%d", &n );
    while( n ){
           
           memset( degree, 0, sizeof( int ) * n );
           
           scanf("%d", &m );
           for( i = 0; i < m; i++ ){
                scanf("%d %d", &u, &v );
                graph[u][degree[u]++] = v;
                graph[v][degree[v]++] = u;
           }
           
           printf("%s\n", bicolorable()?"BICOLORABLE.":"NOT BICOLORABLE." );
           
           scanf("%d", &n );
    }
    
    
 
    return 0;   
}
