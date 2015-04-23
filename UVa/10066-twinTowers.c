/*
 *  Problema: The Twin Towers ( UVa 10066 )
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

#define MAXN 110

int x[MAXN], y[MAXN];
int dp[MAXN][MAXN];	

int max( int a, int b ){ if( a > b ) return a; return b; }

int main(){

	int n1, n2, i, j, tt = 1;
	
	while( 1 ){
		scanf("%d %d", &n1, &n2 );
		if( n1+n2 == 0 ) return 0;
		
		dp[0][0] = 0;
		for( i = 1; i <= n1; i++ ) { scanf("%d", x+i ); dp[i][0] = 0; }		
		for( i = 1; i <= n2; i++ ) { scanf("%d", y+i ); dp[0][i] = 0; }
		
		for( i = 1; i <= n1; i++ )
			for( j = 1; j <= n2; j++ ){
				if( x[i] == y[j] ){
					dp[i][j] = dp[i-1][j-1] + 1;
				} else dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
			}
			
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", tt++, dp[n1][n2] );
	}

	return 0;
}
