#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int comb[10][5][2];
    char senha[10][6];
    int n, i, j, k, teste = 1;
    
    scanf("%d", &n);
    
    while( n ^ 0 ){
           
       printf("Teste %d\n", teste++ );
           
       for( i = 0; i < n; i++ ) {
            
             for( j = 0; j < 5; j++ )
	              scanf("%d %d", &comb[i][j][0], &comb[i][j][1]);
             for( k = 0; k < 6; k++ )
                  scanf(" %c", &senha[i][k]);
                  
       }
             
       for( i = 0; i < 6; i++ ){
         
         int eq = 1;
         int x = comb[0][senha[0][i]-'A'][0];
         int y = comb[0][senha[0][i]-'A'][1];
         
         if( i != 0 ) printf(" ");
         
         for( j = 1; j < n; j++ )
              if( x != comb[j][senha[j][i]-'A'][0] &&
                    x != comb[j][senha[j][i]-'A'][1] ){
                 printf("%d", y);
                 eq = 0;
                 break;
              } 
         
         if( eq )
             printf("%d", x);        
         

       }
       printf("\n\n");
    
    scanf("%d", &n);
    }
    
    return 0;
    
}
