#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int a, l, count;
    unsigned int ini;
    int x = 1;
    
    while( 1 ){
           scanf("%d %d", &a, &l );
           if( a < 0 || l < 0 ) return 0;
           ini = (unsigned int )a;
           
           count = 1;
           while( ini != 1 ){
               
               if( ini & 1u ){
                   ini = 3*ini + 1;
                   if( ini > l ) break;
               }
               else
                   ini /= 2;
               
               count++;
           }
           printf("Case %d: A = %d, limit = %d, number of terms = %d\n", x++, a, l, count );
              
    }

    
}
