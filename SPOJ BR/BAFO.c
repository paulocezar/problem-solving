#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int rodadas;
    int teste = 1;
    int aldo[1000];
    int beto[1000];
    int i;
    
    scanf("%d", &rodadas );
    while( rodadas ^ 0 ){

         for( i = 0; i < rodadas ; i++ )
              scanf("%d %d", &aldo[i], &beto[i] );
              
         for( i = 1; i < rodadas ; i++ ){
              aldo[0] += aldo[i];
              beto[0] += beto[i];
         }
         
         if( aldo[0] < beto[0] )
             printf("Teste %d\nBeto\n", teste++ );
         else
             printf("Teste %d\nAldo\n", teste++ );
           
    scanf("%d", &rodadas );
    }       
    
    return 0;
}
