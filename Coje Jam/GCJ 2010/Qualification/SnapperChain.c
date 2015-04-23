#include <stdio.h>
#include <stdlib.h>

int main(){

	int t, n, k, on, ncase = 1;

	scanf("%d", &t );
	while( t-- ){
		scanf("%d %d", &n, &k );
		on = ( 1<<n ) - 1;
		if( ( k % (1<<n) ) == on ) printf("Case #%d: ON\n", ncase++ );
		else printf("Case #%d: OFF\n", ncase++ );
	}

	return 0;
}


