/*
 *  Problema: Sums in a Triangle ( SPOJ Tutorial )
 *  Tecnica Utilizada:  PD
 *
 *	  Recorrencia simples..
 *		PD[0,0...N] = 0;
 *		PD[ i, j ] = max( PD[i-1][j]+a[i][j] , PD[i-1][j-1]+a[i][j] )
 *      
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( N^2 )
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 110

inline int max( int a, int b ){ if( a > b ) return a; return b; }

int dp[MAXN], tri[MAXN];

int main(){
	
	int t;
	int n, a;
	int out, i, linha;
	
	memset( dp, 0, sizeof( dp ) );
	scanf("%d", &t );
	while( t-- ){
	
		scanf("%d", &n );
		
		for( linha = 1; linha <= n; linha++ ){
			for( i = 1; i <= linha; i++ ){
				scanf("%d", &a );
				tri[i] = max( dp[i-1]+a, dp[i]+a );
			}
			for( i = 1; i <= linha; i++ ) dp[i] = tri[i];
		}
		
		out = 0;
		for( i = 1; i <= n; i++ ) if( dp[i] > out ) out = dp[i];
		printf("%d\n", out ); 
		
		for( i = 0; i <= n; i++ ) dp[i] = 0;
	
	}
	
	return 0;
}
