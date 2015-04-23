#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int a, n, ln, d, dif, r, x, y;
	int pos[6][2], wlk[6][2];
	
	pos[0][0] = 1, pos[0][1] = 0;
	pos[1][0] = 1, pos[1][1] = -1; 
	pos[2][0] = 0, pos[2][1] = -1;
	pos[3][0] = -1, pos[3][1] = 0;
	pos[4][0] = -1, pos[4][1] = 1;
	pos[5][0] = 0, pos[5][1] = 1;
	
	wlk[0][0] = 0, wlk[0][1] = -1;
	wlk[1][0] = -1, wlk[1][1] = 0;
	wlk[2][0] = -1, wlk[2][1] = 1;
	wlk[3][0] = 0, wlk[3][1] = 1;
	wlk[4][0] = 1, wlk[4][1] = 0;
	wlk[5][0] = 1, wlk[5][1] = -1;

	while( scanf("%d", &a ) != EOF ){

		n = (int) ceil( ( sqrt( (12.0 * (double)a) - 3.0 ) - 3.0 ) / 6.0 ); 
		d = 3 * ( n*n + n ) + 1;
	
		if( n == 0 ){ puts("0 0"); continue; }
		dif = d - a;

		ln = dif / n;
		r = dif % n;

		x = pos[ln][0] * n;
		y = pos[ln][1] * n;
		x += wlk[ln][0] * r;
		y += wlk[ln][1] * r;

		printf("%d %d\n", x, y );

	}

	return 0;
}

