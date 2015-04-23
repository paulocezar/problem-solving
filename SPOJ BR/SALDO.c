#include <stdio.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f

int main(){
    
    int n, max, total, x, y, i, teste = 1;
    int ini, fim, menorIni;
    
    scanf("%d", &n );
    while( n ){
    
           max = -INF;
           total = 0;
           fim = 0;
           menorIni = 0;
           ini = 1;
           
           for( i = 1; i <= n; i++ ){
           
              scanf("%d %d", &x, &y );
              total += ( x - y );

              if( total < 0 ) {
                  total = 0;
                  ini = i+1;
              }   
              else if( total > max   ){
                   max = total;
                   fim = i;
                   menorIni = ini;
              }
              else if( total == max ){
                   if( ( i - ini ) > ( fim - menorIni ) ){
                       fim = i;
                       menorIni = ini;
                   }
              }
           }
           
           if( total == max ){
               if( ( fim - menorIni ) < ( i - 1 - ini ) ){
                    fim = i-1;
                    menorIni = ini;
               }
           }
           
           if( max > 0 )
               printf("Teste %d\n%d %d\n\n", teste++, menorIni, fim );
           else
               printf("Teste %d\nnenhum\n\n", teste++);
   
        scanf("%d", &n );
    }
    
    return 0;
}
