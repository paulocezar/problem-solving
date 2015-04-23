#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define INF 0x3f3f3f3f

int main(){

    int sorteado[MAX];    
    int min;
    int N, C, K, x, i;
    
    scanf("%d %d %d", &N, &C, &K );
    while( N ){
    
           memset( sorteado, 0, sizeof(sorteado) );
           min = INF;
           
           for( i = N*C; i > 0; i-- ){
                scanf("%d", &x );
                sorteado[x]++;
           }
           
           for( i = 1; i <= K; i++ )
                if( sorteado[i] < min )
                    min = sorteado[i];
                    
           x = 0;
           for( i = 1; i <= K; i++ )
                if( sorteado[i] == min ){
                    if( x )
                        printf(" ");
                printf("%d", i );
                x = 1;
           }
                
           printf("\n");
    
    
    scanf("%d %d %d", &N, &C, &K );
    }    
    
    return 0;
}
