/*
 *  Problema: What's The Frequency, Kenneth? ( UVa 499 )
 *  Tecnica Utilizada:  ad-hoc
 *	
 *		 Simplismente ler a frase, contar os caracteres e imprimir todos que aparecem
 *		o numero maximo de vezes..
 *      
 *  Dificuldade: teeeta
 *	Complexidade:
 *				O( N )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1010

char line[MAXN];
int f[256];

int main(){

	char c;
	int i, max;
	
	while( gets( line ) ){
		for( c = 'a'; c <= 'z'; c++ ) f[c] = 0;
		for( c = 'A'; c <= 'Z'; c++ ) f[c] = 0;
		i = 0;
		while( line[i] ) f[line[i++]]++;
		max = 0;
		for( c = 'a'; c <= 'z'; c++ ) if( f[c] > max ) max = f[c];
		for( c = 'A'; c <= 'Z'; c++ ) if( f[c] > max ) max = f[c];
		
		for( c = 'A'; c <= 'Z'; c++ ) if( f[c] == max ) putchar( c );
		for( c = 'a'; c <= 'z'; c++ ) if( f[c] == max ) putchar( c );
		printf(" %d\n", max );
	}

	return 0;
}
