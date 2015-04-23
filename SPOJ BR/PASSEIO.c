#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_V  151

int grafo[MAX_V][MAX_V];
int profundidade[MAX_V];
int altura[MAX_V];

int compare( const void* a, const void* b ){

	return *((int*)b) - *((int*)a); 

}

void dfsVisit( int u, int  V, int prof ){
	int v;

	if( profundidade[u] >= prof )
		return;

	profundidade[u] = prof;

	for( v = 1; v <= V; v++ ){
			if( grafo[u][v] )
				dfsVisit( v, V, prof+1 );
	}

}

int dfs( int origem, int nrVertices ){
	int i;
	for( i = 0; i <= nrVertices; i++ )
		profundidade[i] = 0;

	profundidade[origem] = -1;

	dfsVisit( origem, nrVertices, 0 );

	qsort( profundidade, nrVertices+1 , sizeof( int ), compare );

	return profundidade[0];
}

int main(){

   int P, L, I, h, a, b, i, j;
   int teste = 1;

   while( 1 ){
	scanf("%d %d %d", &P, &L, &I );
	if( P == 0 ) break;

	memset( grafo, 0, sizeof( grafo ) );

	for( i = 1; i<= P; i++ )
		scanf("%d", &altura[i] );

	for( i = 0; i < L; i++ ){
		scanf("%d %d", &a, &b );
		if( altura[a] > altura[b] )
			grafo[a][b] = 1;
	}

	printf("Teste %d\n%d\n\n", teste++, dfs( I, P ) );

  }  
  return 0;
}
