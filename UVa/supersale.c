#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001
#define MAXG 101
#define MAXW 31

int main(){
    
    int cases, n, g, i, j, nv, out;
    int w[MAXN];
    int v[MAXN];
    int cap[MAXG];
    int best[MAXN][MAXW]; 
    
    for( i = 0; i < MAXW; i++ )
         best[0][i] = 0;
         
    for( i = 1; i < MAXN; i++ )
         best[i][0] = 0;
    
    scanf("%d", &cases );
    while( cases-- ){
           
           scanf("%d", &n );
           for( i = 1; i <= n; i++ )
                scanf("%d %d", &v[i], &w[i] );  
           
           scanf("%d", &g );
           for( i = 1; i <= g; i++ )
                scanf("%d", &cap[i] );
                           
           for( i = 1; i <= n; i++ ){
                for( j = 1; j < MAXW; j++ ){
                     if( w[i] <= j ){
                         nv = best[i-1][j-w[i]] + v[i];
                         if( nv > best[i-1][j] )
                             best[i][j] = nv;
                         else
                             best[i][j] = best[i-1][j];
                     }
                     else
                         best[i][j] = best[i-1][j];
                }
           }

           out = 0;
           for( i = 1; i <= g; i++ )
                out += best[n][cap[i]];
                
           printf("%d\n", out );                     
           
    }

    return 0;    
}
