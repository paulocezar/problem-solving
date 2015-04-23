#include <stdio.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f

int main(){
    
    int n, max, soma, num;
    
    scanf("%d", &n );
    while( n ){
    
           max = -INF;
           soma = 0;
           
           while( n ){
           
           scanf("%d", &num );
           soma += num;
           
           if( soma > max ) max = soma;
           if( soma < 0   ) soma = 0;
           
           n--;
           }
           
           
           if( soma > 0 )
               printf("The maximum winning streak is %d.\n", max );
           else
               printf("Losing streak.\n");
   
        scanf("%d", &n );
    }
    
    return 0;
}
