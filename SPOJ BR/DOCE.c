#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

int dp[MAX];

int solve( int *vet, int n ){
	int i;
	dp[n] = dp[n+1] = 0;	
	for( i = n-1; i >= 0; i-- )
		if( (vet[i]+dp[i+2]) > dp[i+1] )
			dp[i] = vet[i]+dp[i+2];
		else dp[i] = dp[i+1];
	return dp[0];
}

int main(){

	int n, m, i, j;
	int line[MAX], column[MAX];

	while( 1 ){

		scanf("%d %d", &n, &m );
		if( (m+n) == 0 ) return 0;

		for( i = 0; i < n; i++ ){
		 	for( j = 0; j < m; j++ )
		 		scanf("%d", &line[j] );
			column[i] = solve( line, m );
		}

		printf("%d\n", solve( column, n ) );
	
	}

	return 0;
}

