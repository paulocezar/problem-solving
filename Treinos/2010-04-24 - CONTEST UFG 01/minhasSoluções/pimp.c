#include <stdio.h>
#include <stdlib.h>

int main(){

	int t, tests;
	int n, s, S, cur, i, j;
	int cost[15][15];
	int best[1<<14];

	scanf("%d", &tests );

	for( t = 1; t <= tests; t++ ){

		scanf("%d", &n );
		for( i = 0; i < n; i++ )
			for( j = 0; j < n; j++ )
				scanf("%d", &cost[i][j] );

		best[0] = 0;
		best[1] = cost[0][0];
		best[2] = cost[1][1];

		S = 1 << n;
		for( s = 3; s < S; s++ ){
			
			best[s] = 1 << 30;
			for( i = 0; i < n; i++ ) if( s & 1<<i ){
				
				cur = best[s ^ 1<<i];
				for( j = 0; j < n; j++ ) if( s & 1<<j ){
					cur += cost[j][i];
				}
				best[s] = ( cur < best[s] )?cur:best[s];
			}

		}
		printf("Teste #%d:\nVoce foi oficialmente pimpado por apenas R$ %d.\n\n", t, best[S-1] );
	}

	return 0;
}

