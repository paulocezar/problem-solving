#include <stdio.h>
#include <stdlib.h>

#define MAXN 2010

int grafo[MAXN][MAXN], grafo_r[MAXN][MAXN];
int grau[MAXN], grau_r[MAXN];
int order[MAXN], ttop, N;
char v[MAXN];

void dfs( int u ){
     
     int w;
     v[u] = 1;
     
     for( w = 0; w < grau[u]; w++ ) if( !v[grafo[u][w]] )
          dfs( grafo[u][w] );
     
     ttop--;
     order[ttop] = u;
}

void dfs_r( int u ){
     int w;
     v[u] = 1;
     for( w = 0; w < grau_r[u]; w++ )
          if( !v[grafo_r[u][w]] ) dfs_r( grafo_r[u][w] );
}

void top() {
     int i;
     ttop = N;
     for( i = 1; i <= N; i++ ) v[i] = 0;
     for( i = 1; i <= N; i++ ) if( !v[i] ) dfs(i);
}

int solve(){
    
    int i, j;
    char flag = 0;
    
    top();
    for( i = 1; i <= N; i++ ) v[i] = 0;
    for( i = 0; i < N; i++ ){
         j = order[i];
         if( !v[j] ){
             if( flag ) return 0;
             flag = 1;
             dfs_r( j );
         }
    }
    return 1;
}

int main(){
    
    int m;
    int u, v, w;
    
    while( 1 ){
    
           scanf("%d %d", &N, &m );
           if( N+m == 0 ) return 0;
           
           for( u = 1; u <= N; u++ )
                grau[u] = 0, grau_r[u] = 0;
           
           while( m-- ){
                  scanf("%d %d %d", &u, &v, &w );
                  
                  grafo[u][grau[u]++] = v;
                  grafo_r[v][grau_r[v]++] = u;
                  if( w == 2 ){
                      grafo[v][grau[v]++] = u;
                      grafo_r[u][grau_r[u]++] = v;
                  }
                  
           }
           
           printf("%d\n", solve() );
           
           
           
    }

    return 0;    
}
