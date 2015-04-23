#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int t;
    int n, ones, a, i;
    
    scanf("%d", &t );
    while( t-- ){
           
           scanf("%d", &n );

           ones = 0;
           for( i = 1; i <= n; i++ ){
                scanf("%d", &a );
                if( a >= i ) ones++;
           }       
           
           if( ones & 1 ) puts("ALICE");
           else puts("BOB");
           
           
    }
    
    return 0;    
}
