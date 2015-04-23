#include <stdio.h>
#include <stdlib.h>

int main(){

    int t;
    long long n;
   
    scanf("%d", &t );
    while( t-- ){
      scanf("%lld", &n );
      printf("%lld\n", (2ll*n*n*n + 5ll*n*n + 3ll*n)/8ll - ( (n+1ll)/2ll )/4ll ); 
    }
    return 0;
        
}
