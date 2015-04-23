#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRETO 1
#define BRANCO 0
#define MAXV 302

char deveVisitar[MAXV];
char cor[MAXV];
int grafo[MAXV][MAXV];
int grau[MAXV];

int dfs( int u ){
	
	int x = ( u == 1 ) ? 0 : 1 ;
	int w, v;
	cor[u] = PRETO;
	
	for( w = 0; w < grau[u]; w++ ){
		v = grafo[u][w];
		if( cor[v] == BRANCO ){
			x += dfs( v );
		}
	}
	
	if( x == 1 && ( deveVisitar[u] || u == 1 ) ) return 1;
	else if ( x > 1 ) return x;
	else return 0;
	
}


int main(){
	
	int C, V, X, Y, i, teste = 1;
	
	while( 1 ){
		scanf("%d %d", &C, &V );
		if( C == 0 ) break;
		
		memset( deveVisitar, C, sizeof( deveVisitar ) );
		memset( cor, 0, sizeof( cor ) );
		memset( grau, 0, sizeof( grau ) );
				
		for( i = 1; i < C; i++ ){
			scanf("%d %d", &X, &Y );
			grafo[X][grau[X]++] = Y;
			grafo[Y][grau[Y]++] = X;
		}
		
		for( i = 0 ; i < V; i++ ){
			scanf("%d", &X );
			deveVisitar[X] = 1;
		}
		
		printf("Teste %d\n%d\n\n", teste++, 2 * dfs( 1 ) );
	}
	
	return 0;
}


