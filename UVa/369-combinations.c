#include <stdio.h>
#include <stdlib.h>

long gcd( long a, long b ){

	while( b ){
		a = a % b;
		a ^= b ^= a ^= b;
	}
	return a;

}

void div_gcd( long *a, long *b ){
	long g = gcd( *a, *b );
	*a /= g;
	*b /= g;
}

long C( int n, int k ){
	
	long num, den, nxt_num, nxt_den, i;

	num = den = 1;
	if( k < n -k ) k = n - k;

	for( i = k; i; i-- ){

		nxt_num = n-k+i;
		nxt_den = i;

		div_gcd( &nxt_num, &nxt_den );
		div_gcd( &num, &nxt_den );
		div_gcd( &nxt_num, &den );

		num *= nxt_num;
		den *= nxt_den;

	}
	return num / den;

}


int main(){

	int n, k;

	while( 1 ){
		scanf("%d %d", &n, &k );
		if( n + k == 0 ) return 0;
		printf("%d things taken %d at a time is %ld exactly.\n", n, k, C( n, k ) ); 
	}

	return 0;
}

