#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

int main(){
    
    int n, i, out, at1, at2, p;
    
    while( 1 ){
           
           scanf("%d", &n );
           if( n == 0 ) return 0;
           
           out = at1 = at2 = 0;
           for( i = 0; i <= n; i++ ){
              
              scanf("%d", &p );
              
              if( i % 2 ) { at1 -= p; at2 += p; }
              else { at1 += p; at2 -= p; }
              
              if( at1 > out ) out = at1;
              if( at2 > out ) out = at2;
                                
           }                  
           printf("%d\n", out );
           
    }
    
    return 0;    
}
