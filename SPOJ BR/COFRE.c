#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int cofreJ[101], cofreZ[101], i, depositos;
    int teste = 1;
    
    scanf("%d", &depositos );
    while( depositos ^ 0 ){
           
           cofreJ[0] = cofreZ[0] = 0;
           
           printf("Teste %d\n", teste++);
           for( i = 1; i <= depositos ; i++ )
                scanf("%d %d", &cofreJ[i], &cofreZ[i] );
                
           for( i = 1; i <= depositos; i++ ){
                cofreJ[0] += cofreJ[i];
                cofreZ[0] += cofreZ[i];
                printf("%d\n", cofreJ[0] - cofreZ[0] );
           }
           printf("\n");      
           
    scanf("%d", &depositos );
    }
    
    return 0;
}
