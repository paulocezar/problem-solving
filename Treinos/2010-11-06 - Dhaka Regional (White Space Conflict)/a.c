#include <stdio.h>
#include <stdlib.h>

int main(){

	int n, i, x, zeroes, tst = 1;

	while( 1 ){
		
		scanf("%d", &n );
		if( n == 0 ) return 0;
		
		zeroes = 0;
		for( i = 0; i < n; i++ ){
			scanf("%d", &x );
			if( x == 0 ) zeroes++;
		}
		
		printf("Case %d: %d\n", tst++, n-2*zeroes );

	}

	return 0;
}

