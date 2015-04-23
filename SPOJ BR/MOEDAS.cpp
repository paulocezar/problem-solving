#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;

int main(){

	int i, objetivo, nrMoedas, u, v, qtde;
	int quantidade[50001];
	int valores[101];

	scanf("%d", &objetivo );
	while( objetivo ){
	   scanf("%d", &nrMoedas );

	   for( i = 0; i < nrMoedas; i++ )
		scanf("%d", &valores[i] );

	   for( i = 0; i <= objetivo; i++ )
	   	quantidade[i] = INF;
	  
	  quantidade[0] = 0;
	  queue<int> fila;
	  fila.push( 0 );

	  while( !fila.empty() ){
		
		u = fila.front(); fila.pop();
		if ( u == objetivo ) break;

		qtde = quantidade[u] + 1;
		for( i = 0; i < nrMoedas; i++ ){
			v = u + valores[i];
			if( v <= 50000 && v <= objetivo ){
			   if( qtde < quantidade[v] ){
				quantidade[v] = qtde;
				fila.push( v );
			   }
			}
		}

	}

	if( quantidade[objetivo] == INF )
		printf("Impossivel\n");
	else
		printf("%d\n", quantidade[objetivo] );

	   scanf("%d", &objetivo );
	}

  return 0;
}
