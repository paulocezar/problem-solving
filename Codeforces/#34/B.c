#include <stdio.h>
#include <stdlib.h>

int comp( const void *a, const void *b ){
	return *(int*)a - *(int*)b;
}

int main(){

	int n, g, m, i;
	int a[110];

	scanf("%d %d", &n, &m );
	for( i = 0; i < n; i++ )
		scanf("%d", &a[i] );
	qsort( a, n, sizeof( int ), comp );
	i = 0;
	g = 0;
	while( a[i]<0 && m ){
		m--;
		g += a[i];
		i++;
	}
	printf("%d\n", -g );
	
	return 0;
}

