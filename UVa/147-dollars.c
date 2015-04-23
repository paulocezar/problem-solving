#include <stdio.h>
#include <stdlib.h>

long long ways[30001] = { 0 };
int coins[11] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5  };

int main(){

	int d, c;
	int i, j;
	int n = 30000;

	d = 11;
	ways[0] = 1;
	for( i = 0; i < d; i++ ){
		c = coins[i];
		for( j = c; j <= n; j++ ){
			ways[j] += ways[j-c];
		}
	}

	while( 1 ){

		scanf("%d.%d", &d, &c );
		if( d+c == 0 ) return 0;

		n = 100*d + c;

		printf("%3d.%02d%17lld\n", d, c, ways[n] );

	}


	return 0;
}
