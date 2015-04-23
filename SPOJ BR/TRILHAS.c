#include <stdio.h>
#include <stdlib.h>
#define INF 0x3F3F3F3F

int main(){

 int numTrilhas;
 register int menor = INF;
 register int melhor;
 register int i, j;
 register int desnivel;
 int marcacoes[1001];
 int precisa = 1;
 int pontos;

 scanf("%d", &numTrilhas );

 for( i = 1; i <= numTrilhas; i++ ){

	desnivel = 0;
	scanf("%d", &pontos );
	for( j = 0; j < pontos; j++ ){
		scanf("%d", &marcacoes[j] );

		if( j && precisa )
		   if( marcacoes[j] > marcacoes[j-1] )
			desnivel += ( marcacoes[j] - marcacoes[j-1] );

        }
	
	if( desnivel == 0 && precisa ){
		precisa = 0;
		melhor = i;
		menor = 0;
	}

	if( desnivel < menor ){
		menor = desnivel;
		melhor = i;
	}

	if( precisa ){
		desnivel = 0;
		for( j = pontos-1; j >= 1; j-- ){
			if( marcacoes[j] < marcacoes[j-1] )
				desnivel += ( marcacoes[j-1] - marcacoes[j] );
		}

		if( desnivel == 0 ){
			precisa = 0;
			melhor = i;
		}

		if( desnivel < menor ){
			menor = desnivel;
			melhor = i;
		}
	}

 }

 printf("%d", melhor );

 return 0;
}

