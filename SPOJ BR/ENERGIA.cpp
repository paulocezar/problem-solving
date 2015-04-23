#include <iostream>
#include <list>
#define BRANCO 1
#define PRETO 0

using namespace std;

int n, numVisitados;
char cor[101];

void dfsVisit( list<int> grafo[], int u ){

	numVisitados++;
	cor[u] = PRETO;

	list<int>::iterator it;
	for( it = grafo[u].begin(); it != grafo[u].end(); it++ )
		if( cor[*it] == BRANCO )
			dfsVisit( grafo, *it );
}

void dfs( list<int> grafo[] ){

	for( int u = 1; u <= n; u++ )
		cor[u] = BRANCO;

	numVisitados = 0;

	dfsVisit( grafo, 1 );
}


int main(){

	int  l, x, y, teste = 1;

	while( 1 ){
		scanf("%d %d", &n, &l );
		if( n == 0 ) break;

		list<int> grafo[n+1];

		for( int i = 0; i < l; i++ ){
			scanf("%d %d", &x, &y );
			grafo[x].push_back( y );
			grafo[y].push_back( x );
		}

		dfs( grafo );

		printf("Teste %d\n%s\n\n", teste++, (numVisitados==n)?"normal":"falha" ); 

	}

	return 0;
}

