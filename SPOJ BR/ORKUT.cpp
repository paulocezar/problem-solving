#include <iostream>
#include <map>
#include <list>
#include <string>
#define BRANCO 1
#define PRETO  0
#define CINZA  2
#define MAX_AMIGOS 30

using namespace std;

static char cor[MAX_AMIGOS];
static int adicionou = 0;
static list<int> adicionados;

bool dfsVisit( list<int> grafo[], int u ){

	cor[u] = CINZA;

	for( list<int>::iterator v = grafo[u].begin(); v != grafo[u].end(); v++ ){
		if( cor[*v] == BRANCO ){
			if( !dfsVisit( grafo,  *v ) )
				 return false;
		} else if ( cor[*v] == CINZA )
			return false;
	}

	adicionados.push_front( u );
	cor[u] = PRETO;
	adicionou++;
	return true;
}

void dfs( list<int> grafo[], int nrVertices ){

	for( int i = 0; i < nrVertices; i++ )
		cor[i] = BRANCO;

	for( int x = 0; x < nrVertices; x++ )
		if( cor[x] == BRANCO )
			if( !dfsVisit( grafo, x ) )
				return;
}

int main(){

	int n;
	int teste = 1;

	while( 1 ){
		scanf("%d", &n );
		if( n == 0 ) break;

		list<int> grafo[n];
		map< string, int > indices;
		string nomes[n];
		string nome, exigencia;
		bool possivel = false;
		int exigencias;
		adicionou = 0;

		for( int i = 0; i < n; i++ ){
			cin >> nome;
			indices[nome] = i;
			nomes[i] = nome;
		}

		for( int i = 0; i < n; i++ ){
			cin >> nome;
			scanf("%d", &exigencias );

			if( exigencias == 0 ){
				possivel = true;
			}
	
			for( int j = 0; j < exigencias; j++ ){
				cin >> exigencia;
				grafo[indices[exigencia]].push_back( indices[nome] );
			}
		}

		if( possivel ){

			adicionados.clear( );
			dfs( grafo, n );
				
			if ( adicionou == n ){
				printf("Teste %d\n", teste++ );
				list<int>::iterator it;
				for( it = adicionados.begin(); it != adicionados.end(); it++ ){
					if( it == adicionados.begin() )
						cout << nomes[*it];
					else
						cout << " " << nomes[*it];
				}
				printf("\n\n");
			}
			else
				printf("Teste %d\nimpossivel\n\n", teste++ );

		}
		else
		  printf("Teste %d\nimpossivel\n\n", teste++ );
	
	}

	return 0;
}

