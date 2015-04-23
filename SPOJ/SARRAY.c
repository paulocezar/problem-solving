#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 101000

char line[MAXN];
int suff[MAXN];

int comp( const void *a, const void *b ){
    return strcmp( line+(*(int*)a), line+(*(int*)b) );
}

int main(){

    int i;
    
    gets( line );
    for( i = 0; line[i]; i++ )
         suff[i] = i;
    
    qsort( suff, i, sizeof( int ), comp );
    
    for( i = 0; line[i]; i++ )
         printf("%d\n", suff[i] );

    return 0;    
}
