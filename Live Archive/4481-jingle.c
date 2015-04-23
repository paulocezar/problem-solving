/*
 *  Problema: Jingle Composition ( Nacional 2009 )
 *  Tecnica Utilizada:  ad-hoc
 *	
 *		 Para verificar quantas composicoes sao validas, basta a cada '/' inicializar
 *	     uma fracao f = 1/1, e para cada nota subtrair a duracao referente.. se ao encontrar
 *		 a proxima '/' f == 0, quer dizer que foi uma composicao valida, caso contrario nao.
 *      
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( N )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char comp[300];

int gcd( int a, int b ){
	while( b ){
		a %= b;
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return a;
}

int mmc( int a, int b ){
	return a*b/gcd(a,b);
}

int main(){

	int i, sz;
	int num, den, x, g;
	int ok;
	
	while( 1 ){
		gets( comp );
		if( comp[0] == '*' ) return 0;
		sz = strlen( comp );
	
		ok = 0;
		num = den = 1;
		for( i = 0; i < sz; i++ ){
			switch( comp[i] ){
				case 'W': x = mmc( den, 1 );
						  num = x/den*num - x/1;
						  den = x;
						  break;
				case 'H': x = mmc( den, 2 );
						  num = x/den*num - x/2;
						  den = x;
						  break;
				case 'Q': x = mmc( den, 4 );
						  num = x/den*num - x/4;
						  den = x;
						  break;
				case 'E': x = mmc( den, 8 );
						  num = x/den*num - x/8;
						  den = x;
						  break;
				case 'S': x = mmc( den, 16 );
						  num = x/den*num - x/16;
						  den = x;						
						  break;
				case 'T': x = mmc( den, 32 );
						  num = x/den*num - x/32;
						  den = x;						
						  break;
				case 'X': x = mmc( den, 64 );
						  num = x/den*num - x/64;
						  den = x;
						  break;
				case '/': if( num == 0 ) ok++;
						  num = den = 1;
						  break;
			}
		}
		printf("%d\n", ok );
	}
	
	return 0;
}
