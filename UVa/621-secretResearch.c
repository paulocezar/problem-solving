/*
 *  Problema: Secret Research ( UVa 621 )
 *  Tecnica Utilizada:  ad-hoc
 *	
 *		Simplismente verificar se a string tem algum dos padroes falados no enunciado.
 *
 *  Dificuldade: Teeeta
 *	Complexidade:
 *				O( 1 )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char expr[100];

int main(){

	int n, sz;

	scanf("%d", &n );
	while( n-- ){
		scanf("%s", expr );
		sz = strlen( expr );
		
		if( ( ( expr[0] == '1' || expr[0] == '4' ) && !expr[1] ) || ( expr[0] == '7' && expr[1] == '8' && !expr[2] ) )
			puts("+");
		else if( sz > 2 && expr[sz-2]=='3' && expr[sz-1] == '5' )
			puts("-");
		else if( sz > 2 && expr[0] == '9' && expr[sz-1] == '4' )
			puts("*");
		else puts("?");
		
	}

	return 0;
}
