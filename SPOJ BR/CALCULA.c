#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int num, i = 0 ;
    int soma, input, teste = 0;
    
    scanf("%d", &num );   
    
    while( num != 0 ){
    soma = 0;
    teste++;
    
           for( i = 0 ; i < num ; i++  ){
                scanf("%d", &input);
                soma += input;

           }
           
           printf("Teste %d\n%d\n\n", teste, soma );
           
           scanf("%d", &num );
           
    }    
    
    return 0;
}
