/*
 *  Problema: Game of Sum ( UVa 10891 )
 *  Tecnica Utilizada:  DP ( mini-max / recorrencia + memoization )
 *	
 *		 Monta-se uma recorrencia onde um jogador faz todos os movimentos
 *		validos na sua vez, e pra cada possibilidade de soma que ele consegue,
 *		subtrai-se o resultado do jogo restante, ou seja, no inicio temos o jogador
 *		com a sequencia completa, 1 ... N, ele pode pegar 1 elemento da esquerda
 *		assim, a diferenca sera A[1]-jogo( 2 ... N ); o valor que ele somou menos
 *		o valor do jogo resultante da escolha do segundo jogador. Se o segundo jogador por
 *	    exemplo pegar o elemento da direita, o resultado de jogo( 2 ... N ) sera
 *		A[N]-jogo( 2...N-1 ) e assim, jogo( 1 .. N ) = A[1]-(A[N]-jogo(2...N-1))
 *		= A[1]-A[N]+jogo( 2...N-1 ) , ou seja, jogo( 1...N ) = primeiro jogador escolhe
 *		A[1], segundo jogador escolhe A[N], e agora o jogador 1 joga novamente, tendo os
 *		elementos de 2 ... N-1 para escolher.
 *		 Usando essa ideia, permitindo que cada jogador tire quantos elementos quiser, de 
 *		qualquer uma das extremidades, montamos uma recorrencia que resolve o problema. 
 *
 *		Recorrencia:  Seja sum[i][j] = A[i]+A[i+1]+...+A[j]
 *		jogo( i, j ) = max( sum[i][i+k]-jogo( i+k+1, j )  ,  sum[j-k-1][j]-jogo( i, j-k-1 )  ), k = 0 ... ( j-i+1 ) 
 *		se i <= j; caso contrario, jogo( i, j ) = 0;
 *
 *  Dificuldade: Facil-Medio
 *	Complexidade:
 *				O( ? )
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 110
#define INF 0x3F3F3F3F 

int max( int a, int b ){ if( a > b ) return a; return b; }

int memo[MAXN][MAXN];
int a[MAXN], sum[MAXN];
char mem[MAXN][MAXN];

int solve( int i, int j ){
	
	if( i > j ) return 0;
	if( mem[i][j] ) return memo[i][j];
	int r = -INF;
	int k, sz = j-i+1;
	
	for( k = 0; k < sz; k++ ){
		r = max( r, max( (sum[i+k]-sum[i-1])-solve( i+k+1, j ), (sum[j]-sum[j-k-1])-solve( i, j-k-1 ) ) );
	}
	mem[i][j] = 1;
	return memo[i][j] = r;
	
}

int main(){

	int n;
	int i, j;
	
	while( 1 ){
		scanf("%d", &n );
		if( n == 0 ) return 0;
		
		for( i = 1; i <= n; i++ )
			for( j = i; j <= n; j++ )
				mem[i][j] = mem[j][i] = 0;
				
		sum[0] = 0;
		for( i = 1; i <= n; i++ ){
			scanf("%d", &a[i] ); sum[i] = a[i] + sum[i-1];
		}
		
		printf("%d\n", solve( 1, n ) );
		
	}

	return 0;
}
