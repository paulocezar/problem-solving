#include <stdio.h>
#include <stdlib.h>

#define MAXN 5

long long gcd( long long a, long long b ){
	while( b ){
		a = a % b;
		a ^= b ^= a ^= b;
	}
	return a;
}

int main(){

	long long t[MAXN];
	long long dif[MAXN];
	long long out, mdc;
	int c, n, d, i, j, ncase = 1;

	
	scanf("%d", &c );
	while( c-- ){
		scanf("%d", &n );
		for( i = 0; i < n; i++ )
			scanf("%lld", &t[i] );
		
		d = 0;
		for( i = 0; i < n; i++ )
			for( j = i+1; j < n; j++ ){
				dif[d] = t[i] - t[j];
				if( dif[d] < 0 ) dif[d] = -dif[d];
				d++;
			}

		if( n == 2 ) mdc = dif[0];
		else mdc = gcd( dif[0], dif[1] );
		
		for( i = 2; i < n; i++ )
			mdc = gcd( mdc, dif[i] );
	
		out = -t[0];
		while( out < 0 ) out += mdc;

		printf("Case #%d: %lld\n", ncase++, out % mdc );

	}
	return 0;
}

