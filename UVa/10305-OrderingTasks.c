#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 110

int out[MAXV];
char grafo[MAXV][MAXV];
char nd[MAXV];
int n, top;

void dfs( u ){

     int v;
     nd[u] = 0;
     
     for( v = 1; v <= n; v++ )
          if( grafo[u][v] && nd[v] ) dfs( v );
     
     out[top--] = u;
}

int main(){
    
    int m;
    int i, u, v;
    
    while( 1 ){
    
           scanf("%d %d", &n, &m );
           if( n+m == 0 ) break;
           
           for( u = 1; u <= n; u++ ){
                for( v = u; v <= n; v++ ) grafo[u][v] = grafo[v][u] = 0;
                nd[u] = 1;
           }
           
           for( i = 0; i < m; i++ ){
                scanf("%d %d", &u, &v );
                grafo[u][v] = 1;
           }
           
           top = n-1;
           for( u = 1; u <= n; u++ )
                if( nd[u] ) dfs( u );
           
           printf("%d", out[0] );
           for( u = 1; u < n; u++ ) printf(" %d", out[u] );
           puts("");
           
    }

    return 0;
}

