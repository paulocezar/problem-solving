#include <iostream>
#include <list>

using namespace std;

int main(){

  int p, r, id, naRodada, teste = 1;
  int i, j;
  int comando, acao;
  list<short>::iterator ita;
  list<short>::iterator itb;

  while( 1 ){
	scanf("%d %d", &p, &r );
	if( p == 0 ) break;

	list<short> participantes;

	for( i = 0; i < p; i++ ){
		scanf("%d", &id );
		participantes.push_back( id );
	}

	for( i = 0; i < r; i++ ){
		scanf("%d", &naRodada );
		scanf("%d", &comando );

		list<short> acoes;

		for( j = 0; j < naRodada; j++ ){
			scanf("%d", &acao );
			acoes.push_back( acao );
		}

		ita = participantes.begin();
		itb = acoes.begin();
		for( j = 0; j < naRodada; j++ ){
			if( *itb ^ comando )
				ita = participantes.erase( ita );
			else
				ita++;
			itb++;
		}
	}
	
	ita = participantes.begin();
	printf("Teste %d\n%d\n", teste++, *ita );
  }

  return 0;
}

