#include <stdlib.h>
#include <stdio.h>

unsigned int calculaCiclos( unsigned long x ){

		if ( x == 1 )
			return 1;
		else if( x & 1 )
			return 1 + calculaCiclos( 3*x + 1 );
		else
			return 1 + calculaCiclos( x >> 1 );
}

int main(){

	unsigned int maiorCiclo = 0;
	unsigned long a, b, i, j, aux;

	while( scanf("%lu %lu", &i, &j) != EOF ){

		a = i;
		b = j;

		if( i > j )
			a ^= b ^= a ^= b;


		for( a; a<=b; a++){
			aux = calculaCiclos(a);

			if ( aux > maiorCiclo )
				maiorCiclo = aux;
		}

		printf("%lu %lu %u\n", i, j, maiorCiclo);
		maiorCiclo = aux = 0;
	}

	return 0;

}
