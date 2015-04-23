#include <stdio.h>
#include <stdlib.h>

#define MAXN 110


int main(){

	int n, i, j, k;
	int a[MAXN];

	scanf("%d", &n );
	for( i = 1; i <= n; i++ ) scanf("%d", &a[i] );
	
	for( i = 1; i <= n; i++ ){
		
		for( j = 1; j <= n; j++ ){
			if( i == j ) continue;
			for( k = 1; k <= n; k++ ){
				if( j == k ) continue;
				if( a[i] == (a[j]+a[k]) ){
					printf("%d %d %d", i, j, k );
					return 0;
				}
			}
		}
	
	}

	printf("-1");

	return 0;
}

