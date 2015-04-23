#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 101
#define SSIZE 51
#define ASIZE 4

typedef struct{
        char seq[SSIZE];
        int id;
        int sz;
} sequence;

int comp( const void* a, const void* b ){
    int r = ((sequence*)a)->sz - ((sequence*)b)->sz;
    if( r ) return r;
    return ((sequence*)a)->id - ((sequence*)b)->id;
} 

int main(){

    int m, n, ns;
    sequence sequences[MAXS];
    int i, j;
    int f[ASIZE];
    
    scanf("%d", &m );
    while( m-- ){
           scanf("%d %d", &n, &ns ); getchar();
              
           for( i = 0; i < ns; i++ ){
                gets( sequences[i].seq );
                
                f[0] = f[1] = f[2] = f[3] = 0;
                sequences[i].id = i;
                sequences[i].sz = 0;
                
                for( j = 0; j < n; j++ )
                     switch( sequences[i].seq[j] ){
                             case 'A':
                                      sequences[i].sz += ( f[1] + f[2] + f[3] );
                                      f[0]++;
                                      break;
                             case 'C':
                                      sequences[i].sz += ( f[2] + f[3] );
                                      f[1]++;
                                      break;
                             case 'G':
                                      sequences[i].sz += f[3];
                                      f[2]++;
                                      break;
                             case 'T':
                                      f[3]++;
                                      break; 
                     }
                                                                                                                                              
           }
           qsort( sequences, ns, sizeof( sequence ), comp );
           for( i = 0; i < ns; i++ )
                printf("%s\n", sequences[i].seq );
                
           if( m ) puts("");
           
    }

    return 0;    
}
