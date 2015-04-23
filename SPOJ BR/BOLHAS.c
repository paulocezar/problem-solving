#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int out[100001];
    int n, m, x, i;
    
    while( 1 ){
           scanf("%d %d", &n, &m );
           if( (n+m) == 0 ) break;
           memset( out, 0, sizeof( int ) * n );
               
           for( i = 1; i <= m; i++ ){
                scanf("%d", &x );
                while( out[x] ) x++;
                out[x] = i;
           }
           
           printf("%d", out[0] ? out[0] : ++m );
           for( i = 1; i < n; i++ )
                printf(" %d", out[i] ? out[i] : ++m );
                
           printf("\n");
           
    }  
    
    return 0;
}
