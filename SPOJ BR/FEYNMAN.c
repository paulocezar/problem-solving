#include <stdio.h>
#include <stdlib.h>
#define MAX 101

int main(){
    
    int vetor[MAX];
    int i, num;
    
    vetor[0] = 0;
    for( i = 1; i < MAX; i++ )
         vetor[i] = vetor[i-1] + (i*i) ;
         
    scanf("%d", &num );
    i = 0;
    while( num ^ 0 ){
           if( i )
               printf("\n");       
           printf("%d", vetor[num] );
           i = 1;
    scanf("%d", &num );
    }
    
    
    return 0;
}
