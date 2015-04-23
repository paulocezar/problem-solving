#include <stdio.h>
#include <stdlib.h>

#define abs(x) (x<0)?(-x):(x)

int main(){

	int h[55];
	int n, i;
	int sum, out;
	int set = 1;

	while( 1 ){

		scanf("%d", &n );
		if( n == 0 ) return 0;

		sum = 0;
		for( i = 0; i < n; i++ ){
			scanf("%d", h+i );
			sum += h[i];
		}
		sum /= n;

		out = 0;
		for( i = 0; i < n; i++ )
			out += abs((sum-h[i]));

		printf("Set #%d\nThe minimum number of moves is %d.\n\n", set++, out>>1 );
	}

	return 0;
}
