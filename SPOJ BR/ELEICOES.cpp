#include <iostream>
#include <map>

using namespace std;

int main(){

	map< long int, long int > votacao;
	map< long int, long int >::iterator apura;

	long int n, cand, votos = 0, eleito = 0;

	cin >> n;

	for ( int i = 0; i<n; i++){

	cin >> cand;
	votacao[cand]++;

	}

	apura = votacao.begin();
	while ( apura != votacao.end() ){

		if ( (*apura).second > votos ){
			votos = (*apura).second;
			eleito = (*apura).first;
		}
		
		apura++;
	}
	
	cout << eleito;

	return 0;
}
