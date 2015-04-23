#include <stdio.h>
#include <stdlib.h>

#define MAXN 200
#define INF 0x3F3F3F3F

int dist[MAXN][MAXN];
int queue[MAXN*MAXN][2];
int m, n;

int main(){
    
    int t, i, j, d, ini, fim;
    char c;
    
    scanf("%d", &t );
    while( t-- ){
    
           scanf("%d %d", &m, &n ); getchar();
           for( i = 0; i < m; i++ ){
                for( j = 0; j < n; j++ ){
                     c = getchar();
                     if( c == '1' ) dist[i][j] = 0;
                     else dist[i][j] = INF;
                }
                getchar();
           }
           ini = fim = 0;
           for( i = 0; i < m; i++ )
                for( j = 0; j < n; j++ )
                     if( dist[i][j] == 0 ){
                         queue[fim][0] = i;
                         queue[fim][1] = j; 
                         fim++;
                     }
           
           while( ini != fim ){
                  i = queue[ini][0];
                  j = queue[ini][1];
                  ini++;
                  d = dist[i][j];
                  if( (i+1 < m) && (d+1 < dist[i+1][j]) ){
                      queue[fim][0] = i+1; queue[fim][1] = j;
                      fim++;
                      dist[i+1][j] = d+1;
                  }
                  if( (i-1 >= 0) && (d+1 < dist[i-1][j]) ){
                      queue[fim][0] = i-1; queue[fim][1] = j;
                      fim++;
                      dist[i-1][j] = d+1;
                  }
                  if( (j+1 < n) && (d+1 < dist[i][j+1]) ){
                      queue[fim][0] = i; queue[fim][1] = j+1;
                      fim++;
                      dist[i][j+1] = d+1;
                  }
                  if( (j-1 >= 0) && (d+1 < dist[i][j-1]) ){
                      queue[fim][0] = i; queue[fim][1] = j-1;
                      fim++;
                      dist[i][j-1] = d+1;
                  }
                      
           }
                     
           for( i = 0; i < m; i++ ){
                printf("%d", dist[i][0] );
                for( j = 1; j < n; j++ )
                     printf(" %d", dist[i][j] );  
                puts("");
           }    
    }

    return 0;    
}

