#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define MAXN 10010
#define MAXV 110

int main(){
    
    char used[MAXV];
    int values[MAXN];
    int n, i, j;
    char estavel;
    
    while( 1 ){
           
           scanf("%d", &n );
           if( n == 0 ) return 0;
           
           for( i = 0; i < n; i++ )
                scanf("%d", &values[i] );
                
           for( i = 0; i < MAXV; i++ )
               used[i] = 0;
           
           estavel = 1;
           for( i = 0; (i < n) && (estavel == 1 ); i++ ){
                
                for( j = (values[i]+1); j <= 100; j++ ){
                     if( used[j] == 1 ) { estavel = 0; break; }
                }
                used[values[i]] = 1;     
           }
           
           if( estavel ) printf( "sim\n" );
           else printf( "nao\n" );
               
    }
    
    
    return 0;    
}
