/*
 *  Problema: 
 *  Tecnica Utilizada: 
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char line[1100];
	char first;
	int i;

	while( 1 ){
		
		gets( line );
		if( !line[0] ) continue;
		if( line[0] == '*' ) return 0;

		i = 0;
		while( line[i] == ' ' ) i++;
		first = line[i];
		if( first < 'a' ) first += (  'a' - 'A' );

		while( line[i] ){
			if( line[i-1] == ' ' ){
				if( line[i] >= 'a' ){
					if( line[i] != first ) break;
				} else if( (line[i]+'a'-'A') != first ) break;
			}
			i++;
		}
		if( !line[i] ) puts("Y");
		else puts("N");

	}

	return 0;
}

