/*
 *  Problema: Cutting Sticks ( UVa 10003 )
 *  Tecnica Utilizada: DP ( Recorrencia + Memoization )  
 *	
 *		 Cada corte feito gera dois subproblemas, e a partir disso
 *		podemos definir uma recorrencia.
 *		 Inicialmente temos um bastao de madeira com extremidades 0 e l,
 *		e Cut[ 1 ... N ] cortes necessarios, se fizermos o j-esimo
 *      corte, temos que contar o tamanho do bastao ( l - 0 ) e o custo 
 *		de cortar os bastoes  
 *		 1 - extremidades : 0 -  Cut[j]  /  Cortes necessarios : Cut[ 1 ... j-1 ]
 *		 2 - extremidades : Cut[j] - l   /  Cortes necessarios : Cut[ j+1 ... N ]
 *
 * 		Portanto para resolver o problema, fazemos todos os cortes possiveis, gerando
 *		e resolvendo os subproblemas com uso de memoization para nao refazer calculos.
 *		 Se solve( a, b, i, j ) que calcular o custo de fazer os cortes de i a j, num bastao
 *		com extremidades a e b, solve( a, b, i, j ) pode ser recursivamente como:
 *
 *		  solve( a, b, i, j ) = min(  solve( a, cut[k], i, k-1 ) + solve( cut[k], b, k+1, j ) + b-a )
 *												para todo k em [ i, j ] 
 *		  e os casos base sao, 0 quando i > j, e b-a quando i == j;										
 *
 *  Dificuldade: Medio
 *	Complexidade:
 *				O(  )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
#define INF 0x3F3F3F3F
#define MAXN 55
#define MAXL 1001

int min( int a, int b ){ if( a < b ) return a; return b; }

int cut[MAXN];
int memo[MAXN][MAXN];

int solve( int a, int b, int i, int j ){
	
	if( i > j ) return 0;
	if( memo[i][j] != -1 ) return memo[i][j];
	if( i == j ) return memo[i][j] = b-a;
	
	int k, r;
	r = INF;
	for( k = i; k <= j; k++ ){
		r = min( r, solve( a, cut[k], i, k-1 )+solve( cut[k], b, k+1, j ) + b-a  );
	}
	return memo[i][j] = r;
}

int main(){

	int l, n, i, j;
	
	while( 1 ){
		scanf("%d", &l );
		if( l == 0 ) return 0;
		scanf("%d", &n );
		for( i = 0; i < n; i++ ){
			scanf("%d", cut+i );
			for( j = 0; j < n; j++ ) memo[i][j] = -1;
		}
		printf("The minimum cutting is %d.\n", solve( 0, l, 0, n-1 ) );
	}
	
	return 0;
}
