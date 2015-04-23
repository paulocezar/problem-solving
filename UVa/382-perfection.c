#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n, sum,i, l;

	puts("PERFECTION OUTPUT");
	while( 1 ){

		scanf("%d", &n );
		if( n == 0 ){  puts("END OF OUTPUT"); return 0; }

		l = n / 2;
		sum = 0;
		for( i = 1; i <= l; i++ )
			if( n % i == 0 ) sum += i;
		
		if( n == sum )
		    printf("%5d  PERFECT\n", n );
		else if( n < sum )
		    printf("%5d  ABUNDANT\n", n );
		else
		    printf("%5d  DEFICIENT\n", n );
	}


	return 0;
}

