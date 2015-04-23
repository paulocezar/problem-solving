/*
 *  Problema: Common Permutation ( Spoj Classical )
 *  Tecnica Utilizada:  ad-hoc 
 *	
 *		 Como queremos um string X, de tamanho maximo, cuja exista uma permutacao de X seja
 *		subsequencia da strings A e uma que seja subsequencia de B ( nao necessariamente uma substring ),
 *		basta contarmos o maior numero de caracteres em comum que as duas palavras tem.
 *
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( N )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1010

int occura[256], occurb[256];
char a[MAXN], b[MAXN];

int main(){
	
	int i;
	
	while( gets( a ) ){
		gets( b );
		memset( occura, 0, sizeof( occura ) );
		memset( occurb, 0, sizeof( occurb ) );
		
		for( i = 0; a[i]; i++ ) occura[a[i]]++;
		for( i = 0; b[i]; i++ ) occurb[b[i]]++;
		for( i = 'a'; i <= 'z'; i++ ){
			while( occura[i] && occurb[i] ) { 
				putchar( i );
				occura[i]--; occurb[i]--;
			}
		}
		puts("");		
	}
	return 0;
}
