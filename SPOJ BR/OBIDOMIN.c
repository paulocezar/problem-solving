#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRETO 0
#define BRANCO 1


int grafo[7][7];
int grau[7];
int cor[6];
int visitou = 0;

void visita( int u ){

	int v;

	cor[u] = PRETO;

	for( v = 0; v < 7; v++ )
		if( grafo[u][v] && cor[v] == BRANCO )
			visita( v );
}

int conexo( ){

     int v, x = 1;

     for( v = 0; x ; v++ )
	if( grau[v] > 0 ){
		visita( v );
		x = 0;
	}

     for( v = 0; v < 7; v++ )
	if( grau[v] > 0 && cor[v] == BRANCO )
		return 0;

     return 1;

}




int main(){

	int n, a, b;
	int imp;
	int teste = 1;

	while( 1 ){
		scanf("%d", &n );
		if( n == 0 ) break;

		int i, ini;

		memset( grafo, 0, sizeof( grafo ) );
		memset( grau, 0, sizeof( grau ) );
		memset( cor, 0, sizeof( cor ) );

		for( i = 0; i < n; i++ ){
			scanf("%d %d", &a, &b );
			grafo[a][b] = grafo[b][a] = 1;
			grau[a]++;
			grau[b]++;
			cor[a] = cor[b] = BRANCO;
		}

		imp = 0;
		for( i = 0; i < 7; i++ )
			imp += ( grau[i] % 2 );


		if( imp > 2 )
			printf("Teste %d\nnao\n\n", teste++ );
		else {
			if( conexo() )
				printf("Teste %d\nsim\n\n", teste++ );
			else
				printf("Teste %d\nnao\n\n", teste++ );
		}

	}
	return 0;
}

