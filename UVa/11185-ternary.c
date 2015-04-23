#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, i, j;
    char out[100];
    
    while( 1 ){
    
           scanf("%d", &n );
           if( n < 0 ) return 0;
    
           i = 0;
           out[0] = '0', out[1] = 0;       
           while( n ){
                  out[i] = n % 3 + '0';
                  n /= 3;
                  out[++i] = 0;
           }
           
           j = 0;
           if( i ) i--;
           while( j < i ){
                  out[i] ^= out[j] ^= out[i] ^= out[j];
                  j++, i--;       
           }
           
           printf("%s\n", out );
           
    }       

    return 0;    
}
