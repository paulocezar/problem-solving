#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	long long a, d, n, x, y;

	while( 1 ){
		scanf("%lld", &n );
		if( n == 0 ) return 0;

		a = ceil( sqrt( n ) );
		d = a*a - a + 1;
		if( a & 1 )
			if( n < d ) x = a, y = a + n - d;
			else y = a, x = a - n + d;
		else if( n < d ) x = a + n - d, y = a;
		else x = a, y = a - n + d;

		printf("%lld %lld\n", x, y );

	}

	return 0;
}

