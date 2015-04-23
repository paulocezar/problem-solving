#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

	int sc, scenarios;
	char matr[10];
	int f, fat[3] = { 9, 3, 7 };
	int i, sum, mult, pos;

	scanf("%d", &scenarios ); getchar();
	for( sc = 1; sc <= scenarios; sc++ ){

		gets( matr );
		f = 0;
		if( matr[6] ) i = 6;
		else i = 5;
	
		sum = 0;
		while( i >= 0 ){

			if( matr[i] != '?' ){
				sum += fat[f++]*( matr[i]-'0' );
			} else mult = fat[f++], pos = i;
			i--; 
			f = f % 3;
		}

		for( i = 0; i < 10; i++ )
			if( ( ( mult*i + sum ) % 10 ) == 0 ) break;
		
		matr[pos] = i+'0';

		
		printf("Cenario #%d:\n%s\n\n", sc, matr );

	}

	return 0;
}


