#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in[55], out[55];

int main(){

	int i, n, a, b, lim;

	scanf("%d", &n );

	memset( in, 0, sizeof( in ) );
	memset( out, 0, sizeof( out ) );
	lim = (n*(n-1))/2 -1;
	for( i = 0; i < lim; i++ ){
		scanf("%d %d", &a, &b );
		in[a]++;
		out[b]++;
	}

	for( i = 1; i <= n; i++ )
		if( in[i]+out[i] != n-1 ) { b = a; a = i; }
	
	if( in[a] > in[b] ) printf("%d %d", a, b);
	else printf("%d %d", b, a );


	return 0;
}

