#include <iostream>
#include <stdlib.h>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF 0x3f3f3f3f
#define BRANCO 1
#define PRETO  2

using namespace std;

int compare( const void* a, const void* b ){

	string x = ( *(string*)a).substr( 2, (*(string*)a).size() );
	string y = ( *(string*)b).substr( 2, (*(string*)b).size() );

	int r = x.compare( y );

	if( r != 0 )
		return r;
	else
		return (*(string*)a).at(0) - (*(string*)b).at(0);
}

int main(){

	int linhas;
	int teste = 1;

	while( true ){
		scanf("%d%*c", &linhas );
		if( linhas == 0 ) break;

		map< string, int > indices;
		string nomes[102];
		set<int> grafo[102];
		char cor[102];
		int  numErdos[102];
		int indice = 1;
		indices["P. Erdos"] = 0;
		nomes[0] = "P. Erdos";

		string linha;
		for( int i = 0; i < linhas; i++ ){
			getline( cin, linha );
			string autores[11];
			int numAut = 0;
			int ini = 0;
			int fim = linha.find(',', 0);
			while( fim != string::npos ){
				autores[numAut++] = linha.substr( ini, fim-ini );
				ini = fim+2;
				fim = linha.find(',', ini );
			}
			fim = linha.size();
			autores[numAut++] = linha.substr( ini, fim-ini-1 );

			for( int j = 0; j < numAut; j++ ){
				indices[autores[j]]++;
				if( indices[autores[j]] == 1 ){
					if( autores[j].compare("P. Erdos") == 0 )
						indices[autores[j]]--;
					else {
					indices[autores[j]] = indice;
					nomes[indice++] = autores[j];
					}
				}
				else
					indices[autores[j]]--;
			}

			for( int j = 0; j < numAut; j++ ){
				for( int k = j+1; k < numAut; k++ ){
					grafo[indices[autores[j]]].insert( indices[autores[k]] );
					grafo[indices[autores[k]]].insert( indices[autores[j]] );
				}
			}

		}

		//---Inicio BFS
		for( int u = 0; u < indice; u++ ){
			cor[u] = BRANCO;
			numErdos[u] = INF;
		}

		cor[0] = PRETO;
		numErdos[0] = 0;
		queue<int> q;
		q.push( 0 );

		while( !q.empty() ){
			int u = q.front(); q.pop();
			set<int>::iterator v;
			for( v = grafo[u].begin(); v != grafo[u].end(); v++ ){
				if( cor[*v] == BRANCO ){
					cor[*v] = PRETO;
					numErdos[*v] = numErdos[u] + 1;
					q.push( *v );
				}
			}
		}

		qsort( nomes, indice, sizeof( string ), compare );

		//--- Imprimir ordenado pelo Sobrenome.
		printf("Teste %d\n", teste++ );
		for( int i = 0; i < indice; i++ ){
			if( numErdos[indices[nomes[i]]] != 0  ){
				cout << nomes[i] << ": ";
				if( numErdos[indices[nomes[i]]] == INF )
					printf("infinito\n");
				else
					printf("%d\n", numErdos[indices[nomes[i]]] );
			}
		}
		printf("\n");

	}
	return 0;
}

