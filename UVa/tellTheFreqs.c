#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZE 1002

int frequency[256];

int comp( const void* a, const void* b ){
    int r = frequency[*(int*)a] - frequency[*(int*)b];
    if( r ) return r;
    
    return *(int*)b - *(int*)a;
}

int main(){

    char line[LSIZE];
    char* ptr;
    int nltrs, i;
    int out[256];
    char p = 0;
    
    while( gets( line ) ){
           
           if( p ) puts("");
           else p++;
           
           ptr = line;
           nltrs = 0;
           memset( frequency, 0, sizeof( frequency ) );
           
           while( *ptr ){
                  if( frequency[*ptr] == 0 )
                      out[nltrs++] = *ptr;
                  frequency[*ptr]++;
                  ptr++;   
           }
           
           qsort( out, nltrs, sizeof( int ), comp );
           for( i = 0; i < nltrs; i++ )
                printf("%d %d\n", out[i], frequency[out[i]] );
                
    }
    
    return 0;
}
