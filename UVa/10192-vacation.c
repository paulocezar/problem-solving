/*
 *  Problema: Vacation ( UVa 10192 )
 *  Tecnica Utilizada:  DP ( Longest Commom Subsequence )
 *	
 *		 Mais um que quer a maior subsequencia comum..
 *
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( N1*N2 )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 110

char x[MAXN], y[MAXN];
int dp[MAXN][MAXN];	

int max( int a, int b ){ if( a > b ) return a; return b; }

int main(){

	int n1, n2, i, j, cnum = 1;
	
	while( 1 ){
		gets( x+1 );
		if( x[1] == '#' ) return 0;
		gets( y+1 );
		n1 = strlen( x+1 );
		n2 = strlen( y+1 );
		
		dp[0][0] = 0;
		for( i = 1; i <= n1; i++ ) dp[i][0] = 0; 		
		for( i = 1; i <= n2; i++ ) dp[0][i] = 0; 
		
		for( i = 1; i <= n1; i++ )
			for( j = 1; j <= n2; j++ ){
				if( x[i] == y[j] ){
					dp[i][j] = dp[i-1][j-1] + 1;
				} else dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
			}
			
		printf("Case #%d: you can visit at most %d cities.\n", cnum++, dp[n1][n2] );
	}

	return 0;
}
