#include <stdio.h>
#include <stdlib.h>

#define MAXN 65001

char prime[MAXN];

void chieve(){

	int i, j;
	
	for( i = 2; i < MAXN; i++ )
		prime[i] = 1;

	for( i = 4; i < MAXN; i+=2 )
		prime[i] = 0;

	for( i = 3; i < MAXN; i+=2 ){
		
		if( prime[i] ){
			for( j = i+i; j < MAXN; j+=i )
				prime[j] = 0;
		}

	}

}

long exp_mod( long *a, int n, long *mod ){
	
	long r;
	
	if( n == 1 ) return *a; 
	
	r = exp_mod( a, n / 2, mod );
	if( n & 1 ) return ( ( (  r * r ) % *mod ) * *a ) % *mod;
	
	return ( r * r ) % *mod;
}

int main(){

	char carmichael;
	long a, n;

	chieve();

	while( 1 ){

		scanf( "%ld" , &n );
		if( n == 0 ) return 0;

		if( prime[n] ) carmichael = 0;
		else carmichael = 1;
		
		for( a = 2; carmichael & a < n; a++ )
			if( exp_mod( &a, n, &n ) != a )
				carmichael = 0;

		if( carmichael ) printf( "The number %ld is a Carmichael number.\n", n );
		else printf( "%ld is normal.\n", n );

	}


	return 0;

}
