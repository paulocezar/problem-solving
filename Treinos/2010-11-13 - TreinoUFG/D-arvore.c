#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

	int sc, scenarios;
	int a, b, esq, dir, v;

	scanf("%d", &scenarios );
	for( sc = 1; sc <= scenarios; sc++ ){
		
		scanf("%d %d", &a, &b );
		esq = dir = 0;
		
		while( a != b ){

			if( a > b ){
				v = (a-1)/b;
				esq += v;
				a -= (v*b);
			} else {
				v = (b-1)/a;
				dir += v;
				b -= (v*a);
			}
		
		}
		
		printf("Cenario #%d:\n%d %d\n\n", sc, esq, dir );

	}

	return 0;
}


