#include <stdio.h>
#include <stdlib.h>

int main (){

int qtde;
int counter;
int saida = 0;
int *numeros;

scanf("%d", &qtde);
	if ( qtde < 0 || qtde > 50 )
		return 0;

numeros = (int*) malloc(qtde * sizeof(int));

for( counter = 0; counter < qtde; counter++ ){

	scanf("%d", &numeros[counter]);
	if ( numeros[counter] > 5000 || numeros[counter] < -5000 )
			return 0;
	else
	saida += numeros[counter];
}

printf("%d", saida);

return 0;
}
