#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

int main(){
    
    int n, i, p, d;
    
    while( 1 ){
           
           scanf("%d %d %d", &n, &p, &d );
           if( n+p+d == 0 ) return 0;
           
           
           for( i = 1; i <= n; i++ ){
              
              if( ( i % p == 0 || i %10 == p ) || ( i % d == 0 || i %10 == d ) )
                  printf("Cafufa");
              else printf("%d", i );
              if( i < n ) printf(", ");
              else printf(".\n");
                
           }                  
    }
    
    return 0;    
}
