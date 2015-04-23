#include <stdio.h>
#include <stdlib.h>

int main(){

  int n, m, teste = 1;
  register int i, j, k;
  int direita[1000];
  int esquerda[1000];
  int acima[1000];
  int prod[1000];

  while( 1 ){

    scanf("%d %d", &n, &m );
    if( n == 0 ) break;
    
    for( i = 0; i < m; i++ ){
    	scanf("%d", &prod[i] );
        if( i == 0 )
 		    acima[i] = prod[i];
		else
			acima[i] = acima[i-1] + prod[i];
    }

    for( i = 1; i < n; i++ ){
	
	     for( j = 0; j < m; j++ ){
              scanf("%d", &prod[j] );
         }

	     esquerda[0] = acima[0] + prod[0];
	     direita[m-1] = acima[m-1] + prod[m-1];	
         for( j = 1; j < m; j++ ){
              k = m - j - 1;
              esquerda[j] = (esquerda[j-1] > acima[j])?(esquerda[j-1]+prod[j]):(acima[j]+prod[j]);
              direita[k] = (direita[k+1] > acima[k])?(direita[k+1]+prod[k]):(acima[k]+prod[k]);
         }
         
         for( j = 0; j < m; j++ )
              acima[j] = (esquerda[j] > direita[j])?esquerda[j]:direita[j] ;
              
    }
    printf("Teste %d\n%d\n\n", teste++, acima[m-1] );

  }
  return 0;
}

