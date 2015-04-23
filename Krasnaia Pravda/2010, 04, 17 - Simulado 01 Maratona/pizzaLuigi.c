#include <stdio.h>
#include <stdlib.h>

long long gcd( long long a, long long b ){

	while( b ){
		a %= b;
		a ^= b ^= a ^= b;
	}

	return a;
}

int main(){
	
	long long n, a, b, g, den;
	long long out;

	while( scanf( "%lld", &n ) != EOF ){
	
		if( n & 1 )
			a = n * ( ( n-1 ) / 2 );
		else
			a = ( n/2 ) * (n-1);
		
		den = 24;
		g = gcd( n, den );
		b = n / g;
		den = den / g;

		g = gcd( n-1, den );
		b = ( b * ( (n-1) / g ) ) % 1000000000;
		den = den / g;

		g = gcd( n-2, den );
		b = ( b * ( (n-2) / g ) ) % 1000000000;
		den = den / g;

		g = gcd( n-3, den );
		b = ( b * ( (n-3) / g ) ) % 1000000000;
	
		a = ( 1 + a + b ) % 1000000000;

		printf("%09lld\n", a );
	}
	
	return 0;
}

