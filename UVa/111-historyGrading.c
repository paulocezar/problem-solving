/*
 *  Problema: History Grading ( UVa 111 )
 *  Tecnica Utilizada:  DP - LCS
 *	
 *		O i-esimo inteiro representa a posicao do inteiro i na ordenacao.
 *		Com isso montamos duas sequencias X e Y, e a nota da ordenacao e  | LCS( x, y ) |
 *
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( X * N ^ 2 )
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 25

int x[MAXN], y[MAXN];
int lcs[MAXN][MAXN];

int main(){

	int n, a;
	int i, j;
	
	scanf("%d", &n );
	for( i = 1; i <= n; i++ )	{
		scanf("%d", &a ); x[a] = i;
	}
	
	while( scanf("%d", &a ) != EOF ){
		y[a] = 1;
		for( i = 2; i <= n; i++ ){
			scanf("%d", &a ); y[a] = i; 
		}
		for( i = 0; i <= n; i++ ) lcs[i][0] = lcs[0][i] = 0;
		
		for( i = 1; i <= n; i++ ){
			for( j = 1; j <= n; j++ ){
				if( x[i] == y[j] ){
					lcs[i][j] = lcs[i-1][j-1] + 1;
				} else if( lcs[i-1][j] > lcs[i][j-1] ) lcs[i][j] = lcs[i-1][j];
				else lcs[i][j] = lcs[i][j-1];
			}
		}
		printf("%d\n", lcs[n][n] );
	}
	
	return 0;
}
