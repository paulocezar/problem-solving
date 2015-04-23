#include <stdio.h>
#include <stdlib.h>

#define numCakes 31

int comp( const void* a, const void* b ){
    return *(int*)a - *(int*)b;
}

int main(){

    int stack[31], ordr[31], n, i, j, k;
    char c;
    
    while( scanf("%d", &stack[0] ) != EOF ){
           c = getchar();
           n = 0;
           ordr[n] = stack[n++];
           
           while( c != -1 && c != '\n' ){
                  scanf("%d", &stack[n] );
                  ordr[n] = stack[n++];
                  c = getchar();
           }
           qsort( ordr, n, sizeof( int ), comp );
           
           c = 0;
           
           printf("%d", stack[0] );
           for( i = 1; i < n; i++ )
                printf(" %d", stack[i] );
           printf("\n");
           
           for( i = n-1; i > 0; i-- ){
                if( stack[i] != ordr[i] ){
                  
                    k = 0;
                    j = i - 1;
                    while( stack[j] != ordr[i] ) j--;
                    
                    if( j ){
                        if( c )
                            printf(" %d", n-j );
                            else{ printf("%d", n-j ); c++; }
                    }
                    
                    
                    while( k < j ){
                           stack[k] ^= stack[j] ^= stack[k] ^= stack[j];
                           j--; k++;
                    }
                           
                    k = 0;
                    j = i;
                    while( k < j ){
                           stack[k] ^= stack[j] ^= stack[k] ^= stack[j];
                           j--; k++;
                    }
                    if( c )
                        printf(" %d", n-i );
                    else{ printf("%d", n-i ); c++; }
                    
                }
           }
           if( c )
               printf(" 0\n");
           else
               printf("0\n");
           
    }   
    
    return 0;
}
