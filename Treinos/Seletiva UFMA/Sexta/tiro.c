#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

long long gcd( long long a, long long b ){
    while( b ){
           a %= b;
           a ^= b;
           b ^= a;
           a ^= b;
    }
    return a;
}

long long mmc( long long a, long long b ){
    return ( a / gcd( a, b ) ) * b;
}

int main(){
 
    int n, i;
    long long a, out;
    
    while( 1 ){
           
           scanf("%d", &n );
           if( n == 0 ) return 0;
           
           out = 1ll;
           for( i = 0; i < n; i++ ){
                scanf("%lld", &a );
                out = mmc( out, a );
           }
           printf("%lld\n", out );
           
    }
    return 0;
    
}
