#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 1001

int a[MAXN], b[MAXN];

int main(){
	
	int ct, t;
	int n, i, j, out;
	
	scanf("%d", &t );
	for( ct = 1; ct <= t; ct++ ){
		
		
		scanf("%d", &n );
		out = 0;
		
		for (i = 0; i < n; i++) scanf( "%d %d", &a[i], &b[i] );
		
		for ( i = 0; i < n; i++)
			for ( j = i+1; j < n; j++ )
				if( ( a[i] > a[j] && b[i] < b[j] ) || ( a[i] < a[j] && b[i] > b[j] ) ) out++;
		
		printf("Case #%d: %d\n", ct, out );
		
	}
	
	return 0;
}
