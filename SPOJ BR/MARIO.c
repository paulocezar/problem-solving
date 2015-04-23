#include <stdio.h>
#include <stdlib.h>

#define INF 0x4fffffff

int main(){

    int livres[100001];
    int n, l, i, li, precisa, x, min;
    
    while( 1 ){
         
           scanf("%d %d", &n, &l );
           if( (n + l) == 0 ) break;
           
           for( i = 0; i < l; i++ )
                scanf("%d", &livres[i] );
           livres[l--] = INF;           
           li = livres[l] - n +1;
           
           x = 0;
           min = INF;
           
           for( i = 0; livres[i] <= li; i++ ){
                precisa = livres[i] + n - 1;
                
                while( livres[x+1] <= precisa ) x++;
                
                precisa = n - x + i - 1;
                if( precisa < min ) min = precisa;
                
           }
           
           printf("%d\n", min );
          
    }
    
    return 0;
}
