#include <stdio.h>
#include <stdlib.h>

int main(){

    unsigned long long f[13];
    int i, k, x;
    unsigned long long n, out, den;
    
    f[0] = 1ull;
    for( i = 1; i < 13; i++ )
         f[i] = ( (unsigned long long)i ) * f[i-1];   
    
    while( scanf("%llu %d", &n, &k ) != EOF ){
    
           den = 1llu;
           for( i = 0; i < k; i++ ){
                scanf("%d", &x );
                den *= f[x];
           }
           out = f[n] / den;
           
           printf("%llu\n", out );           
           
    }
    
    return 0;
}
