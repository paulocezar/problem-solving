#include <stdio.h>
#include <stdlib.h>

#define MAXN 501

int main(){

	int t, n, ct;
	int out[MAXN];
	
	out[1] = 0;
	out[2] = 1;
	out[3] = 2;
	for( t = 4; t < MAXN; t++ )
		out[t] = ( out[t-1] + out[t-2] ) % 100003;

	scanf("%d", &t );
	for( ct = 1; ct <= t; ct++ ){
		scanf("%d", &n );
		printf("Case #%d: %d\n", ct, out[n] );
	}	

	return 0;
}

