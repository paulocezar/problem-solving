#include <stdio.h>
#include <stdlib.h>

int custo[15][15];
int best[1<<15];

int main(){

	int t, ct, n, i, j;
	int prev, mask, smask;

	scanf("%d", &t );
	for( ct = 1; ct <= t; ct++ ){

		scanf("%d", &n );
		for( i = 0; i < n; i++ )
			for( j = 0; j < n; j++ )
				scanf("%d", &custo[i][j] );
	
		smask = 1<<n;
		best[0] = 0;
		for( mask = 1; mask < smask; mask++ ){

			best[mask] = 1<<30;
			
			
			for( i = 0; i < n; i++ ){
				
				if( !( mask & (1<<i) ) ) continue;

				prev = best[ mask ^ (1<<i) ];

				for( j = 0; j < n; j++ ){
					if( mask & (1<<j) ){
						prev += custo[i][j];
					}
				}
				
				if( prev < best[mask] ) best[mask] = prev;
			
			}

		}
		
		printf("Cenario #%d:\nVoce foi sobretaxado em apenas R$%d.\n\n", ct, best[smask-1] );

	}

	return 0;
}

