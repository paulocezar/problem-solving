#include <stdio.h>
#include <stdlib.h>

#define MAXN 51

int main(){

    int cases, n, swaps, i, j;
    int vet[MAXN];
    
    scanf("%d", &cases );
    while( cases-- ){
           scanf("%d", &n );
           
           for( i = 0; i < n; i++ )
                scanf("%d", &vet[i] );
                
           swaps = 0;
           for( i = 1; i < n; i++ ){
                j = i;
                while( j && vet[j] < vet[j-1] ){
                       vet[j] ^= vet[j-1] ^= vet[j] ^= vet[j-1];
                       swaps++;
                       j--;
                }
           }
           
           printf("Optimal train swapping takes %d swaps.\n", swaps );
    
    }    
    
    return 0;
}
