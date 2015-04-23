/*
 *  Problema: Brothers ( Nacional 2009 )
 *  Tecnica Utilizada:  Simulacao
 *	
 *		 Basta simular as K batalhas de acordo com a explicacao do enunciado.
 *      
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( K*R*C )
 */

#include <stdio.h>
#include <stdlib.h>

int grid[2][110][110];

int main(){

	int n, c, r, k, t;
	int i, j;
	int cur, otr;
	
	while( 1 ){
		scanf("%d %d %d %d", &n, &r, &c, &k );
		if( n+r+c+k == 0 ) return 0;
		
		for( i = 0; i < r; i++ )
			for( j = 0; j < c; j++ )
				scanf("%d", &grid[0][i][j] );
		
		
		cur = 0;
		otr = 1;
		n--;
		t = 1;
		while( k-- && t ){
		
		
			for( i = 0; i < r; i++ )
				for( j = 0; j < c; j++ )
					grid[otr][i][j] = grid[cur][i][j];
				
			t = 0;
			for( i = 0; i < r; i++ ){
				for( j = 0; j < c; j++ ){
					
					if( grid[cur][i][j] == n ){
						if( i-1 >= 0 && grid[cur][i-1][j]==0 ) grid[otr][i-1][j] = n, t++;
						if( i+1 < r && grid[cur][i+1][j]==0 )  grid[otr][i+1][j] = n, t++;
						if( j-1 >= 0 && grid[cur][i][j-1]==0 ) grid[otr][i][j-1] = n, t++;
						if( j+1 < c && grid[cur][i][j+1]==0 )  grid[otr][i][j+1] = n, t++;
					} else {
						if( i-1 >= 0 && grid[cur][i-1][j]==(grid[cur][i][j]+1) ) grid[otr][i-1][j] = grid[cur][i][j], t++;
						if( i+1 < r && grid[cur][i+1][j]==(grid[cur][i][j]+1) )  grid[otr][i+1][j] = grid[cur][i][j], t++;
						if( j-1 >= 0 && grid[cur][i][j-1]==(grid[cur][i][j]+1) ) grid[otr][i][j-1] = grid[cur][i][j], t++;
						if( j+1 < c && grid[cur][i][j+1]==(grid[cur][i][j]+1) )  grid[otr][i][j+1] = grid[cur][i][j], t++;				
					}
				}
			}
		
			cur = 1 - cur;
			otr = 1 - otr;
		}
		
		for( i = 0; i < r; i++ ){
			printf("%d", grid[cur][i][0] );
			for( j = 1; j < c; j++ )
				printf(" %d", grid[cur][i][j] );
			printf("\n");
		}
	}
	
	return 0;
}