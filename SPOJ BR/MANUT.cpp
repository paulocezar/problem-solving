#include <iostream>
#include <set>
#define MAX_COMP 401

using namespace std;

struct vertice {

	int low;
	int num;
	int pai;
	bool visitado;
	set<int> vizinhos;

};

vertice grafo[MAX_COMP];
bool articulacao[MAX_COMP];
int xxx = 0;

void inicializa( int n ){
	for( int i = 1; i <= n; i++ ){
		grafo[i].low = 0;
		grafo[i].num = 0;
		grafo[i].pai = 0;
		grafo[i].visitado = false;
		grafo[i].vizinhos.clear();
		articulacao[i] = false;
	}
}


void encontraArt( int v ){

	grafo[v].visitado = true;
	grafo[v].low = grafo[v].num = xxx++;
	
	set<int>::iterator w;
	for( w = grafo[v].vizinhos.begin(); w != grafo[v].vizinhos.end(); w++ ){

		if( !grafo[*w].visitado ){

			grafo[*w].pai = v;
			encontraArt( *w );

			if( grafo[v].num != 1 && grafo[*w].low >=  grafo[v].num )
				articulacao[v] = true;
			if( grafo[v].num == 1 && grafo[*w].num != 2 )
				articulacao[v] = true;

			grafo[v].low = min( grafo[v].low, grafo[*w].low  );

		}
		else if( grafo[v].pai != *w )
			grafo[v].low = min( grafo[v].low, grafo[*w].num );

	}

}

int main(){


	int n, m;
	int teste = 1;

	while( 1 ){
		scanf("%d %d", &n, &m );
		if( n == 0 ) break;

		inicializa( n );
		xxx = 1;

		int a, b;
		for( int i = 0; i < m; i++ ){
			scanf("%d %d", &a, &b );
			grafo[a].vizinhos.insert( b );
			grafo[b].vizinhos.insert( a );
		}
		
		encontraArt( 1 );
	
		printf("Teste %d\n", teste++ );
		bool p = false;
		for( int i = 1; i <= n; i++ ){
			if( articulacao[i] ){
				if( p ){
					printf(" %d", i );
				}
				else{
					printf("%d", i );
					p = true;
				}
			} 
		}

		if( p )
			printf("\n\n");
		else
			printf("nenhum\n\n");		

	}

	return 0;
}

