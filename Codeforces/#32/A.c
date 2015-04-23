#include <stdio.h>
#include <stdlib.h>

int abs( int x ){ if( x < 0 ) return -x; return x; }

int main(){

	int n, d, i, j;
	int a[1010];
	int ways = 0;

	scanf("%d %d", &n, &d );
	for( i = 0; i < n; i++ ){
		scanf("%d", &a[i] );
		for( j = 0; j < i; j++ ){
			if( abs( a[i]-a[j] ) <= d ) ways += 2;
		}
	}
	printf("%d\n", ways );

	return 0;
}

