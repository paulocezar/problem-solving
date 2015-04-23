#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 201
#define max(a,b) ( ((a)>(b)) ? (a) : (b) )
#define min(a,b) ( ((a)<(b)) ? (a) : (b) )

int main(){
    
    int n, i, j, k, dx, dy, scn = 1;
    int x[MAXN], y[MAXN], d[MAXN][MAXN];
    
    for( i = 1; i <= MAXN; i++ )
         d[i][i] = 0;
    
    while( 1 ){
    
           scanf("%d", &n );
           if( n == 0 ) return 0;
           
           for( i = 1; i <= n; i++ )
                scanf("%d %d", &x[i], &y[i] );
           
           for( i = 1; i < n; i++ )
                for( j = i+1; j <= n; j++ ){
                     dx = x[i]- x[j], dy = y[i]- y[j];
                     d[i][j] = d[j][i] = dx*dx + dy*dy;
                }
                
           for( k = 1; k <= n; k++ )
                for( i = 1; i <= n; i++ ){
                     if( i == k ) continue;
                     for( j = i+1; j <= n; j++ )
                          d[i][j] = d[j][i] = min( d[i][j], max( d[i][k], d[k][j] ) );
                }
           
           printf("Scenario #%d\nFrog Distance = %.03lf\n\n", scn++, sqrt( d[1][2] ) );    
    }
    
    return 0;    
}
