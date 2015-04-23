#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x3F3F3F3F

int cap[1001];

int main(){

	int n, m, k;
	int i, a, b, out;

	scanf("%d %d %d", &n, &m, &k );
	for( i = 1; i <= m; i++ )
		cap[i] = INF;

	for( i = 0; i < n; i++ ){
		scanf("%d %d", &a, &b );
		if( cap[a] > b ) cap[a] = b;
	}

	out = 0;
	for( i = 1; i <= m; i++ )
		if( cap[i] != INF ) out += cap[i];

	if( out > k ) out = k;

	printf("%d\n", out );

	return 0;
}

