#include <stdio.h>
#include <stdlib.h>

int comp( const void* a, const void* b ){
    return *(int*)a - *(int*)b;
}

int main(){

    int cases;
    int out, median, dif, n, i;
    int r[501];
    
    scanf("%d", &cases );
    while( cases-- ){
           out = 0;
           scanf("%d", &n );
           for( i = 0; i < n; i++ )
                scanf("%d", &r[i] );       
    
           qsort( r, n, sizeof( int ), comp );
           
           i = n/2;
           if( n % 2 )
               median = r[i];
           else
               median = (r[i-1] + r[i]) / 2;
                
           for( i = 0; i < n; i++ ){
                dif = median - r[i];
                if( dif < 0 )
                    dif = -dif;
                out += dif;
           }
           
           printf("%d\n", out );
    }
    
    return 0;
}
