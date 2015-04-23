#include <stdio.h>
#include <stdlib.h>

int main(){

    int t, s, i, j, xor, x;
    
    scanf("%d", &t );
    while( t-- ){
           scanf("%d", &s );
           xor = 0;
           for( i = 1; i <= s; i++ ){
                scanf("%d", &x );
                if( x & 1 ) xor ^= i;
           }
           if( xor ) puts("Tom Wins");
           else puts("Hanks Wins");
    }

    return 0;    
}
