#include <stdio.h>
#include <stdlib.h>

#define maxV 1001

int graph[maxV][maxV];
int viz[maxV];
int n, m, cnt;
int lbl[maxV], low[maxV];
int parnt[maxV];

char bridgeR( int u ){
 
     int i, v;
     low[u] = lbl[u] = cnt++;
     
     for( i = 0; i < viz[u]; i++ ){
          v = graph[u][i];
          if( lbl[v] == -1 ){
             parnt[v] = u;
             if( bridgeR( v ) ) return 1;
             if( low[u] > low[v] ) low[u] = low[v];
             if( low[v] == lbl[v] ) return 1;
          }
          else if( v != parnt[u] && low[u] > lbl[v] ) 
             low[u] = lbl[v];
     }

    return 0;         
}

char hasBridge(){ 

     int v;
     cnt = 0;
     
     for( v = 1; v <= n; v++ ) 
         lbl[v] = -1;
     
     for( v = 1; v <= n; v++ )
         if( lbl[v] == -1 && v == 1 ){
             parnt[v] = v;
             if( bridgeR( 1 ) ) return 1;
         } else if( lbl[v] == -1 ) return 1;
         
     return 0;
}

int main(){

    int i, a, b;
         
    while( 1 ){
           scanf("%d %d", &n, &m );
           if( (n + m) == 0 ) break; 
           
           for( i = 1; i <= n; i++ )
                viz[i] = 0;
    
           for( i = 0; i < m; i++ ){
                
                scanf("%d %d", &a, &b );
                graph[a][viz[a]++] = b;
                graph[b][viz[b]++] = a;
                                
           }
           
           if( hasBridge() ) printf("N\n");
           else printf("S\n");
    
    }

    return 0;    
}
