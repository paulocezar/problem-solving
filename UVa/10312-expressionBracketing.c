#include <stdio.h>
#include <stdlib.h>

int main(){

	int n, i;
	unsigned long f[27], g[27];

	f[1] = f[2] = g[1] = g[2] = 1;

	for( n = 3; n < 27; n++ ){
		f[n] = 3 * f[n-1];
		for( i = 2; i <= n-2; i++ )
			f[n] += ( 2 * f[i] * f[n-i] );
	}

	for( n = 3; n < 27; n++ ){
		 g[n] = 2 * g[n-1];
		 for( i = 2; i <= n-2; i++ )
		 	g[n] += ( g[i] * g[n-i] );
	}

	while( scanf("%d", &n ) != EOF ) printf("%lu\n", f[n]-g[n] );

	return 0;
}

