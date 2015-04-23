#include <stdio.h>
#include <stdlib.h>

int main(){

	int a, b, last_x, last_y, x, y, q;

	while( scanf("%d %d", &a, &b ) != EOF ){

		last_x = 1, last_y = 0, x = 0, y = 1;
		
		while( b ){
			q = a / b;
			a = a % b;
			a ^= b ^= a ^= b;

			last_x = last_x - q * x;
			last_y = last_y - q * y;
			last_x ^= x ^= last_x ^= x;
			last_y ^= y ^= last_y ^= y;
		}
		
		printf("%d %d %d\n", last_x, last_y, a );
	}
	return 0;

}

