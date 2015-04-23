#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 25

char graph[MAXN][MAXN];
int route[MAXN];
char used[MAXN];
char reach[MAXN];
int point, dest, N, count;

void dfs( int u ){

     int v;
     
     if( u == dest ){
         count++;
         for( v = 0; v < point-1; v++ )
              printf("%d ", route[v] );
         printf("%d\n", dest );
         return;
     }
     
     if( !reach[u] ) return;
     
     
     for( v = 1; v <= N; v++ ){
          if( graph[u][v] && !used[v] ){
              used[v] = 1;
              route[point++] = v;
              dfs( v );
              point--;
              used[v] = 0;
          }
     }
     
}

void compute(){

    memset( reach, 0, sizeof( reach ) );
    int queue[MAXN];
    int ini, fim, u, v;
    
    ini = fim = 0;
    queue[fim++] = dest;
    reach[dest] = 1;
           
    while( ini != fim ){
    
           u = queue[ini++];
           
           for( v = 1; v <= N; v++ ){
                if( graph[u][v] && !reach[v] ){
                    queue[fim++] = v;
                    reach[v] = 1;
                }
           }
    }
    

}

int main(){

    int u, v;
    int ncase = 1;
    
    while( scanf("%d", &dest ) != EOF && dest ){
           
           for( u = 1; u <= MAXN; u++ )
                for( v = u; v <= MAXN; v++ )
                      graph[u][v] = graph[v][u] = 0;
           
           N = 1;
           while( 1 ){
                  scanf("%d %d", &u, &v );
                  if( u+v == 0 ) break;
                  if( u > N ) N = u;
                  if( v > N ) N = v;
                  graph[u][v] = graph[v][u] = 1;
           }
           
           compute();
           
           count = point = 0;
           route[point++] = 1;
           memset( used, 0, sizeof( used ) );
           used[1] = 1;
           printf("CASE %d:\n", ncase++ );
           dfs( 1 );
           printf("There are %d routes from the firestation to streetcorner %d.\n", count, dest );
           
    }
    return 0;
}

