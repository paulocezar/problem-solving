/*
 *  Problema: BLAST ( Spoj Classical )
 *  Tecnica Utilizada:  DP ( Recorrencia )
 *	
 *		A recorrencia e simples..
 *			seja C[i][j] a diferenca entre X[i] e Y[j] .. e SP a diferenca entre o espaco e os demais caracteres..
 *			
 *			DP[i][j] = min(  DP[i-1][j-1]+C[i][j], DP[i-1][j]+SP, DP[i][j-1]+SP  )	
 *			   e 
 *			DP[i][j] = i*SP + j*SP se i ou j == 0
 *
 *		Ou seja, a expansao de menor custo envolvendo os caracteres ate X[i] e Y[j],
 *		seja a melhor opcao entre, deixar os caracteres X[i] e Y[j] na mesma posicao,
 *		colocar um espaco na string Y para casar com X[i] ou colocar um espaco na string X 
 *		para casar com Y[j].
 *		Obs.: a funcao solve(i,j) aplica a recorrencia diretamente, usando memoization (top-down) e
 *		tem um tempo de execucao pouco mais de duas vezes maior que o modo como a solucao esta 
 * 		sendo calculada usando uma matriz ( bottom-up ).
 *
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( |X| * |Y| )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2010
#define INF 0x3F3F3F3F

int memo[MAXN][MAXN];
char x[MAXN], y[MAXN];
int sp;

inline int min( int a, int b ){ if( a < b ) return a; return b; }
inline int abs( int x ){ if( x < 0 ) return -x; return x; }

int solve( int i, int j ){
	
	if( i < 0 ) return sp*(j+1);
	if( j < 0 ) return sp*(i+1);
	
	if( memo[i][j] != -1 ) return memo[i][j];
	return memo[i][j] = min( solve(i-1, j-1)+abs(x[i]-y[j]), min( solve( i-1, j )+sp, solve(i, j-1)+sp )  );
	
}

int main(){
	
	
	int len1, len2;
	int i, j;
	
	gets( x+1 );
	gets( y+1 );
	scanf("%d", &sp );
	len1 = strlen( x+1 );
	len2 = strlen( y+1 );
	
	for( i = 0; i <= len1; i++ ) memo[i][0] = sp*i;
	for( j = 0; j <= len2; j++ ) memo[0][j] = sp*j;
	
	for( i = 1; i <= len1; i++ )
		for( j = 1; j <= len2; j++ )
			memo[i][j] = min( memo[i-1][j-1]+abs(x[i]-y[j]), min( memo[i-1][j], memo[i][j-1] )+sp );
			
	printf("%d\n", memo[len1][len2] );
		
	return 0;
}