#include <stdio.h>
#include <stdlib.h>

int main(){
    
   int c, f, i, w, teste = 1;;
   int custo[51];
   int valor[51];
   int mochila[51][1001];

   scanf("%d %d", &c, &f );
   while( c ){
      
      for( i = 1; i <= f; i++ )
         scanf("%d %d", &custo[i], &valor[i] );

      for( i = 0; i <= c; i++ )
         mochila[0][i] = 0;
         
      for( i = 1; i <= f; i++ ){ 
           
         mochila[i][0] = 0;
         for( w = 1; w <= c; w++ ){
              
            if( custo[i] > w )   
               mochila[i][w] = mochila[i-1][w];
            else{
               if( (valor[i] + mochila[i-1][w-custo[i]] ) > mochila[i-1][w] )
                  mochila[i][w] = valor[i] + mochila[i-1][w-custo[i]];
               else mochila[i][w] = mochila[i-1][w];
            }
            
         }
      }

      printf("Teste %d\n%d\n\n", teste++, mochila[f][c]);

      scanf("%d %d", &c, &f);
   }

   return 0;
}
