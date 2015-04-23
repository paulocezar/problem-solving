/*
 *  Problema: Aeroporto ( SPOJ-BR )
 *  Tecnica Utilizada:  AD-HOC
 *                       -- Conta quantos voos chegam/partem de cada aeroporto
 *                          e imprime todos que tiverem o maior valor..
 *  Dificuldade: n00b
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int aeroportos[101];
    int aeroportosTeste;
    int voos, i, x, y;
    int teste = 1;
    
    scanf("%d %d", &aeroportosTeste, &voos );
    while( voos ^ 0 && aeroportosTeste ^ 0 ){
           
           for( i = 1; i <= aeroportosTeste; i++ ) 
                  aeroportos[i] = 0;
                  
           for( i = 0; i < voos; i++ ){ 
                  scanf("%d %d", &x, &y );
                  aeroportos[x]++;
                  aeroportos[y]++;        
           }
           
           x = 0;
           for( i = 1; i <= aeroportosTeste; i++ )
                if( aeroportos[i] > x )
                    x = aeroportos[i];
                    
           printf("Teste %d\n", teste++ );
           y = 0;
           for( i = 1; i <= aeroportosTeste; i++ )
                if( aeroportos[i] == x ){
                    if( y ^ 0 )
                    printf(" ");
                    printf("%d", i );
                    y = 1;
                }
                
           printf("\n");                  
    
    scanf("%d %d", &aeroportosTeste, &voos );    
    }
    
    return 0;    
}
