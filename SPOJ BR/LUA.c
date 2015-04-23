#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int temperaturas[10000];
    int medicoes, intervalo, teste, min, max;
    
    scanf("%d %d", &medicoes, &intervalo );
    
    while( ( medicoes ^ 0 ) && ( intervalo ^ 0 ) ){
           int i, j, x = 0;
           teste ++;
           
           for( i = 0; i < medicoes; i++ )
                scanf("%d", &temperaturas[i] );
           
          for( i = 0; i < intervalo; i++ )
                     x += temperaturas[i];
          
          j = x / intervalo;
          min = j;
          max = j;
           
           for( ; i < medicoes ; i++ ){
                x = x - temperaturas[i-intervalo];
                x = x + temperaturas[i];

                j = x / intervalo;
                
                if( j > max )
                    max = j;
                if( j < min )
                    min = j;
           }
           
           printf("Teste %d\n%d %d\n\n", teste, min, max);
           
           scanf("%d %d", &medicoes, &intervalo );
    } 
    
    
    return 0;
}
