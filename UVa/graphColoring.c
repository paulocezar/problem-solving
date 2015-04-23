#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 101
#define BRANCO 0
#define PRETO 1

int graph[MAXV][MAXV];
int degree[MAXV];
char color[MAXV];
char answer[MAXV];
int n, m, max;

char mayPaint( int u ){
     int i, v;
     for( i = 0; i < degree[u]; i++ ){
          v = graph[u][i];
          if( color[v] == PRETO )
              return 0;
     }
     return 1;
}

void backtrack( int u, int painted ){
     
     int i, v;
     if( u > n ){
         if( painted > max ){
             max = painted;
             memcpy( answer, color, sizeof( char ) * ( n+1 ) );
         }
         return;
     }
     
     if( painted+(n-u)+1 <= max ) return;
     
     if( mayPaint( u ) ){
         color[u] = PRETO;
         backtrack( u + 1, painted+1 );
         color[u] = BRANCO;
     }
     
     backtrack( u+1, painted );
     
}

int main(){
    
    int cases, i, u, v;
    char f;
    
    scanf("%d", &cases );
    while( cases-- ){
           
           scanf("%d %d", &n, &m );
    
           memset( degree+1, 0, sizeof( int ) * n );
           memset( color+1, 0, sizeof( char ) * n );
           
           for( i = 0; i < m; i++ ){
                scanf("%d %d", &u, &v );
                graph[u][degree[u]++] = v;
                graph[v][degree[v]++] = u;
           }
           
           max = -1;
           backtrack( 1, 0 );
           
           printf("%d\n", max );  f = 0;
           for( u = 1; u <= n; u++ )
                if( answer[u] ){
                    if( f ) printf(" %d", u );
                    else { f++; printf("%d", u ); }
                }
           printf("\n");
                
    }

    return 0;    
}
