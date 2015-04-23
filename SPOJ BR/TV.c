#include <stdio.h>
#include <stdlib.h>

int main(){
    
    short int tv[1001][1001];
    int m, n, x, y, dx, dy, teste = 1;
    int i, j, ip, jp;

    
    while( 1 ){

           scanf("%d %d", &m, &n );
           if( m == 0 ) break;
           
           dx = dy = 0;
           
           for( i = 0; i < m; i++ )
                for( j = 0; j < n; j++ )
                     scanf("%d", &tv[i][j] );
                 
           while( 1 ){
                  scanf("%d %d", &x, &y );
                  if( x == y && y == 0 ) break;
                  dx += x;
                  dy += y;
           }

           
           printf("Teste %d\n", teste++ );  
           for( i = 0; i < m; i++ ){
                ip = (m + (i+dy)%m )%m;  
                              
                for( j = 0; j < n; j++ ){
                     
                   jp = (n + (j-dx)%n )%n;
                     
                   if( j ^ 0 ) printf(" ");
                    printf("%d", tv[ip][jp] );
                     
                }
                printf("\n");
           }
           printf("\n");

    }
    
    return 0;
    
}
