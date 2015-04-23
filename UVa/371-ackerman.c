#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF 0x0F3F3F3F

int nsize[INF];

int size( long n ){
 
    if( n >= INF ){
        if( n & 1 ) return 1 + size( 3*n + 1 );
        else  return 1 + size( n / 2 );
    }
    
    if( nsize[n] )
        return nsize[n];
    
    if( n & 1 ) nsize[n] = 1 + size( 3*n + 1 );
        else    nsize[n] = 1 + size( n / 2 ); 
        
    return nsize[n];
    
}


int main(){
    
    int a, b;
    int i, ini, max, x;

    nsize[1] = 1;
    
    while( 1 ){
           scanf("%d %d", &a, &b );
           if( (a+b)==0 ) return 0;
           
           if( a > b ) a ^= b ^= a ^= b;
     
           max = 0;
           for( i = a; i <= b; i++ ){
                if( i & 1 )
                x = size( 3*i + 1 );
                else
                x = size( i / 2 );
                if( x > max ) max = x, ini = i;
           }
           
           printf("Between %d and %d, %d generates the longest sequence of %d values.\n", a, b, ini, max ); 
                 
    }
    
    return 0;    
}
