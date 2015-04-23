#include <stdio.h>
#include <stdlib.h>

int main(){

    int participantes, bilhete, i, prem, teste = 1;
    
    scanf("%d", &participantes );
    while( participantes ^ 0 ){
           prem = 0;
           for( i = 1; i <= participantes; i++ ){
                scanf("%d", &bilhete );
                if( bilhete == i && prem == 0 ){
                    printf("Teste %d\n%d\n\n", teste++, i );
                    prem = 1;
                }
           }
           
    scanf("%d", &participantes );    
    }    
    
    return 0;
}
