#include <stdio.h>
#include <stdlib.h>

int main(){

    int regioes, teste = 1;
    int maiorX, menorY, menorU, maiorV;
    int i, x, y, u, v;
    
    
    scanf("%d", &regioes );
    
    while( regioes ){
           maiorX = -10001;
           menorY = 10001;
           menorU = 10001;
           maiorV = -10001;
           
           for( i = 0; i < regioes; i++ ){
                scanf("%d %d %d %d", &x, &y, &u, &v );
                if( x > maiorX )
                    maiorX = x;
                if( y < menorY )
                    menorY = y;
                if( u < menorU )
                    menorU = u;
                if( v > maiorV )
                    maiorV = v;
           }
           
           if( maiorX > menorU || menorY < maiorV )
               printf("Teste %d\nnenhum\n\n", teste++);
           else
               printf("Teste %d\n%d %d %d %d\n\n", teste++, maiorX, menorY, menorU, maiorV );
           
    scanf("%d", &regioes );           
    }
    
    return 0;    
}
