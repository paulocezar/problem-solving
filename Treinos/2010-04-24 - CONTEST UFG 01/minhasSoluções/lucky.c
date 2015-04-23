#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int i, t;
    long long out, pot, n;

    scanf("%d", &t );
    while( t-- ){
           scanf("%lld", &n );
           out = 0;
           pot = 5;
           while( n ){
                  out += ( n & 1 ) * pot;
                  n >>= 1;
                  pot *= 5;
           }
           printf("%lld\n", out );
    }

    return 0;    
}
