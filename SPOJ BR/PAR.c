#include <stdio.h>
#include <stdlib.h>

int main(){

    int numPartidas;
    int teste = 0;
    
    scanf("%d", &numPartidas );
    
    while( numPartidas != 0 ){
           char jogador1[12];
           char jogador2[12];
           int resultado = 0;
           int ent1, ent2;
           
           teste++;
           printf("Teste %d\n", teste );
           
           scanf("%s", jogador1 );
           scanf("%s", jogador2 );
           
           while( numPartidas != 0 ){
                  
           scanf("%d %d", &ent1, &ent2 );
           resultado = ent1;
           resultado += ent2;
           
           if( resultado % 2 == 0 )
           printf("%s\n", jogador1 );
           else
           printf("%s\n", jogador2 );      
           
           numPartidas--;
           }
           printf("\n");
           scanf("%d", &numPartidas );     
                      
    }   

    return 0;
}
