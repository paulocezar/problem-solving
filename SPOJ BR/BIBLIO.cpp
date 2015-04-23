#include <iostream>
#include <string.h>
#define MAX_SALAS 60
#define INF 0x3f3f3f3f

using namespace std;

static int raiz[MAX_SALAS][MAX_SALAS];
static int custo[MAX_SALAS][MAX_SALAS];

int calculaCusto( int ini, int fim, int nivel ){

	if( ini > fim ) return 0;

	if( ini == fim )
		return nivel * custo[ini][ini];
	int r = raiz[ini][fim];

	int x = calculaCusto( ini, r-1, nivel+1 );
	    x += ( nivel * custo[r][r] );
	    x += calculaCusto( r+1, fim, nivel+1 );

	return x;

}


int main(){

   int frequencia[MAX_SALAS];
   int w[MAX_SALAS][MAX_SALAS];
   int numSalas, teste = 1;

   while( 1 ){
	scanf("%d", &numSalas );
	if( numSalas == 0 ) break;

	memset( raiz, 0, sizeof( raiz ) );
	memset( w, 0, sizeof( w ) );
	memset( custo, 0, sizeof( custo ) );

	for( int i = 0; i < numSalas; i++ )
		scanf("%d", &frequencia[i] );

	// Calcula os menores custos e as raizes otimas
	for( int l = 0; l < numSalas; l++ ){
		// Calcula o custo e a raiz para as arvores com 'l + 1' vertices
		for( int i = 0; i < numSalas -l; i++ ){
			int j = i + l;

			custo[i][j] = INF;
			//Somatorio das frequencias das salas de i a j ?
			w[i][j] = w[i][j-1] + frequencia[j];
		
			// Na arvore com os vertices de i a j, calcula o menor custo
			// alternando entre todas as possiveis raizes.
			for( int r = i; r <= j; r++ ){
				int t = custo[i][r-1] + custo[r+1][j] + w[i][j] ;
					if( t < custo[i][j] ){
						custo[i][j] = t;
						raiz[i][j] = r;
					}
			}
		}
	}

  	printf("Teste %d\n%d\n\n", teste++, calculaCusto( 0, numSalas-1, 0 ) );

  }

 return 0;

}

