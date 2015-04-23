/*
ID: knightp2
LANG: C
PROG: hex
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXD 100010

int main(){

	
	char hexa[MAXD];
	char bin[4*MAXD];
	char octal[2][2][2];
	char p;
	int i, j;
	int testes;

	octal[0][0][0] = '0';
	octal[0][0][1] = '1';
	octal[0][1][0] = '2';
	octal[0][1][1] = '3';
	octal[1][0][0] = '4';
	octal[1][0][1] = '5';
	octal[1][1][0] = '6';
	octal[1][1][1] = '7';

	scanf("%d", &testes ); getchar();
	while( testes-- ){
		
		scanf( "%[^\n]", hexa ); getchar();
		if( strcmp( hexa, "0" ) == 0 ){ printf( "0\n"); continue; }
		
		i = 0;
		while( hexa[i] ){
			j = 4*i;
			switch( hexa[i] ){
				case '0': bin[j] = 0,
				  bin[j+1] = 0,
				  bin[j+2] = 0,
				  bin[j+3] = 0;
				  break;
				case '1': bin[j] = 0,
				  bin[j+1] = 0,
				  bin[j+2] = 0,
				  bin[j+3] = 1;
				  break;
				case '2': bin[j] = 0,
				  bin[j+1] = 0,
				  bin[j+2] = 1,
				  bin[j+3] = 0;
				  break;
				case '3': bin[j] = 0,
				  bin[j+1] = 0,
				  bin[j+2] = 1,
				  bin[j+3] = 1;
				  break;
				case '4': bin[j] = 0,
				  bin[j+1] = 1,
				  bin[j+2] = 0,
				  bin[j+3] = 0;
				  break;
				case '5': bin[j] = 0,
				  bin[j+1] = 1,
				  bin[j+2] = 0,
				  bin[j+3] = 1;
				  break;
				case '6': bin[j] = 0,
				  bin[j+1] = 1,
				  bin[j+2] = 1,
				  bin[j+3] = 0;
				  break;
				case '7': bin[j] = 0,
				  bin[j+1] = 1,
				  bin[j+2] = 1,
				  bin[j+3] = 1;
				  break;
				case '8': bin[j] = 1,
				  bin[j+1] = 0,
				  bin[j+2] = 0,
				  bin[j+3] = 0;
				  break;
				case '9': bin[j] = 1,
				  bin[j+1] = 0,
				  bin[j+2] = 0,
				  bin[j+3] = 1;
				  break;
				case 'A': bin[j] = 1,
				  bin[j+1] = 0,
				  bin[j+2] = 1,
				  bin[j+3] = 0;
				  break;
				case 'B': bin[j] = 1,
				  bin[j+1] = 0,
				  bin[j+2] = 1,
				  bin[j+3] = 1;
				  break;
				case 'C': bin[j] = 1,
				  bin[j+1] = 1,
				  bin[j+2] = 0,
				  bin[j+3] = 0;
				  break;
				case 'D': bin[j] = 1,
				  bin[j+1] = 1,
				  bin[j+2] = 0,
				  bin[j+3] = 1;
				  break;
				case 'E': bin[j] = 1,
				  bin[j+1] = 1,
				  bin[j+2] = 1,
				  bin[j+3] = 0;
				  break;
				case 'F': bin[j] = 1,
				  bin[j+1] = 1,
				  bin[j+2] = 1,
				  bin[j+3] = 1;
				  break;
			}
			i++;
		}
		j = 4*i;
		
		p = 1;
		switch( j % 3 ){
			
			case 0: p = i = 0;
				break;
			case 1: if( octal[0][0][bin[0]] == '0' ){ p = 0; i = 1; }
					else{ p = 1; i = 1; printf( "1" ); }
					break;
			case 2: if( octal[0][bin[0]][bin[1]] == '0' ) { p = 0; i = 2; }
					else{ p = 1; i = 2; printf( "%c", octal[0][bin[0]][bin[1]] ); }
					break;
		}
		
		while( !p ){
			if( octal[bin[i]][bin[i+1]][bin[i+2]] != '0' ){
				printf( "%c", octal[bin[i]][bin[i+1]][bin[i+2]] );
				p = 1;
			}
			i+=3;
		}

		while( i < j ){
			printf( "%c", octal[bin[i]][bin[i+1]][bin[i+2]] );
			i += 3;
		}
		printf( "\n" );

	}

	return 0;
}

