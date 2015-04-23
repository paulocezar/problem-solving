/*
 *  Problema: Let me count the ways ( UVa 357 )
 *  Tecnica Utilizada:  DP ( Coin Change)
 *
 *	   Podemos subdividir o problema de encontrar o numero de maneiras de retornar N centavos usando as M primeiras moedas
 *		em, encontrar o numero de maneiras de retornar N centavos usando as M-1 primeiras moedas e o numero de maneiras de retornar
 *		N menos o valor da M-esima moeda usando as M primeiras moedas.
 *	
 *		 Recorrencia:
 *		   Seja ways[ N, M ] o numero de jeitos de obter N cents, com as M primeiras moedas
 *			e C[M] o valo da enesima moeda..
 *
 *		   ways[ N, M ] = ways[ N, M-1 ] + ways[ N-C[M], M ]
 *		O caso base para esse problema pode ser considerado.. ways[ N, 1 ] = 1, uma vez que C[1] = 1 e existe apenas um
 *		jeito de retornar qualquer valor N usando apenas moedas de 1 centavo.
 *      
 *  Dificuldade: Medio
 *	Complexidade:
 *				O( Nr.COINS * N )
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 30001

long long ways[MAXN];
int coins[4];

int main(){

	int c, x;
	
	coins[0] = 5;
	coins[1] = 10;
	coins[2] = 25;
	coins[3] = 50;
	
	for( x = 0; x < MAXN; x++ ) ways[x] = 1ll;
	for( c = 0; c < 4; c++ )
		for( x = coins[c]; x < MAXN; x++ )
			ways[x] += ways[x-coins[c]] ;

	while( scanf("%d", &x) != EOF ){
		if( ways[x] == 1ll ) printf("There is only 1 way to produce %d cents change.\n", x ); 
		else printf("There are %lld ways to produce %d cents change.\n", ways[x], x );
	} 

	return 0;
}
