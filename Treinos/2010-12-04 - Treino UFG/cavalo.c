#include <stdio.h>
#include <stdlib.h>

char grid[30][30];

int linha[30];
int coluna[30];

int p, q;
int need, sum;

char solve( int i, int j ){

	if( i < 0 || j < 0 || i >= p || j >= q ) { return 0; }
	if( grid[i][j] ) { return 0; }
	
	if( sum == need ) {
		linha[sum] = i; 
		coluna[sum] = j; 
		return 1;
	}

	grid[i][j] = 1;

	sum++;
	if( solve( i-1, j-2 ) ){ sum--; linha[sum] = i; coluna[sum] = j; return 1;  }
	if( solve( i+1, j-2 ) ){ sum--; linha[sum] = i; coluna[sum] = j; return 1;  }
	if( solve( i-2, j-1 ) ){ sum--; linha[sum] = i; coluna[sum] = j; return 1;  }
	if( solve( i+2, j-1 ) ){ sum--; linha[sum] = i; coluna[sum] = j; return 1;  }

	if( solve( i-2, j+1 ) ){ sum--; linha[sum] = i; coluna[sum] = j; return 1;  }
	if( solve( i+2, j+1 ) ){ sum--; linha[sum] = i; coluna[sum] = j; return 1;  }
	if( solve( i-1, j+2 ) ){ sum--; linha[sum] = i; coluna[sum] = j; return 1;  }
	if( solve( i+1, j+2 ) ){ sum--; linha[sum] = i; coluna[sum] = j; return 1;  }
	sum--;

	grid[i][j] = 0;

	return 0;
}

int main(){

	int t, ct, i, j;
	char ok;

	scanf("%d", &t );
	
	for( ct = 1; ct <= t; ct++ ){

		scanf("%d %d", &p, &q );
		ok = 0;

		for( i = 0; i < p; i++ )
		for( j = 0; j < q; j++ )
		grid[i][j] = 0;
		
		need = p*q;

		printf("Cenario #%d:\n", ct );
		for( j = 0; j < q && !ok; j++ ){
			for( i = 0; i < p && !ok; i++ ){
				sum = 1;
				if( solve( i, j ) ){
					
					for( i = 1; i <= need; i++ ){
						putchar( (coluna[i]+'A') ); printf("%d", linha[i]+1 );
					}
					printf("\n\n");
					ok = 1;
				}
			}
		}
		
		if( !ok ) printf("Impossivel\n\n" );

	}


	return 0;
}

