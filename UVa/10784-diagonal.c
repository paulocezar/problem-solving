#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	double N;
	int casen = 1;

	while( 1 ){

		scanf("%lf", &N );
		if( N == 0 ) return 0;

		printf("Case %d: %.0lf\n", casen++, ceil( ( 3 + sqrt( 9 + 8*N ) ) / 2 ) );

	}

	return 0;
}

