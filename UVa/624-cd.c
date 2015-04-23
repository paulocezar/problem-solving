#include <stdio.h>
#include <stdlib.h>

#define MAXT 22
#define MAXN 20001

int main(){

    int track[MAXT];
    int best[MAXT][MAXN];
    char used[MAXT];
    int n, t;
    int i, j, nv;
    
    while( scanf("%d", &n ) != EOF ){
           
           scanf("%d", &t );
           for( i = 1; i <= t; i++ )
                scanf("%d", &track[i] );
    
           for( i = 0; i <= n; i++ )
                best[0][i] = 0;
                
           for( i = 1; i <= t; i++ ){               
                
                best[i][0] = 0;
                for( j = 1; j <= n; j++ ){
                     
                    if( track[i] > j )
                        best[i][j] = best[i-1][j];
                    else{
                         nv = best[i-1][j-track[i]] + track[i];
                         if( nv > best[i-1][j] )
                             best[i][j] = nv;
                         else best[i][j] = best[i-1][j];
                    }
                          
                }    
           }
           
           j = n;
           for( i = t; i > 0; i-- )
                if( best[i][j] == best[i-1][j] )
                    used[i] = 0;
                else {
                    used[i] = 1;
                    j = j - track[i];
                }

           for( i = 1; i <= t; i++ )
                if( used[i] ) printf("%d ", track[i] );
           printf("sum:%d\n", best[t][n] );
                
    
    }

    return 0;    
}
