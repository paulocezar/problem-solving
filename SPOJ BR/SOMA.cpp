#include <iostream.h>

using namespace std;

int main(){


int qtde;
int saida = 0;

	cin >> qtde;
	if ( qtde < 0 || qtde > 50 )
		return 0;

	int numeros[qtde];

	for( int counter = 0; counter < qtde; counter++ ){

	cin >> numeros[counter];
		if ( numeros[counter] > 5000 || numeros[counter] < -5000 )
			return 0;

	}

	for( int counter = 0; counter < qtde; counter++ ){

	saida += numeros[counter];

	}

        cout << saida;
	return 0;
}
