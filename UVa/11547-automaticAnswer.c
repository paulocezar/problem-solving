#include <stdio.h>
#include <stdlib.h>

int main(){
 
    int cases, n;
    
    scanf("%d", &cases );
    while( cases-- ){
           
           scanf("%d", &n );
           n = 315 * n + 36962;

           if( n < 0 ) n = -n;
                      
           if( n < 10 ) n = 0;
           else n = ( n / 10) % 10;
                      
           printf("%d\n", n ); 
                  
    }
    
    return 0;
}
