#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int cases, a, b, sum, x = 1;
    
    scanf("%d", &cases );
    while( cases-- ){
           scanf("%d %d", &a, &b );
                
           if( a & 1 );
           else a++;
           
           sum = 0;
           while( a <= b ){
                  sum += a;
                  a+=2;
           }
                  
           printf("Case %d: %d\n", x++, sum );
                  
    }
    
    return 0;    
}
