#include <stdio.h>
#include <stdlib.h>

int main(){

	int n;
	int out, cur, x;

	while( 1 ){

		scanf("%d", &n );
		if( n == 0 ) return 0;

		cur = out = 0;
		while( n-- ){
			scanf("%d", &x );
			cur += x;
			if( cur < 0 ) cur = 0;
			if( cur > out ) out = cur;
		}

		if( out ) printf("The maximum winning streak is %d.\n", out );
		else printf("Losing streak.\n");

	}

	return 0;
}

