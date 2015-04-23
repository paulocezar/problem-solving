#include <stdio.h>
#include <math.h>

int main() {

int n, i, aux;

	scanf("%d", &n);

		if ( n < 0 ){
			n *= -1;
        }
        
        if ( n > pow(2, 31) ){
             return 0;
        }
        
	aux = sqrt(n) + 1;
 
	if ( n == 2 || n == 3 || n == 5 || n == 7 || n == 11 ) {
		printf("sim");
        return 0;
	}

	if( n == 1 || n%2 == 0  ) {
		printf("nao");
        return 0;
	}

	for( i = 3; ( i < aux ); i+=2){
		if ( n % i == 0 ){
		printf("nao");
        return 0;
		}
	}

	printf("sim");

	return 0;
	
}
