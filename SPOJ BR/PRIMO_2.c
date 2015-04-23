#include <stdio.h>
#include <math.h>
#define FALSE 0
#define TRUE 1

int main() {

int n, i, aux, achou = FALSE;

	scanf("%d", &n);

		if ( n < 0 )
			n *= -1;
	
	aux = (int) sqrt(n);

	for( i = 2; i<= aux && achou == FALSE; i++){
		if ( n % i == 0 )
			achou == TRUE;
	}

	if( achou == FALSE )
		printf("nao");
	else
		printf("sim");

	return 0;
}
