#include <stdio.h>
#include <stdlib.h>

int main(){
    
    long long n, out;
    
    while( scanf("%lld", &n ) != EOF ){
           out = 0;
           while( n / 5 ) out += n/5, n /= 5;
           printf("%d\n", out );
    }

    return 0;    
}
