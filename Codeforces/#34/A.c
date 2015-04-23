#include <stdio.h>
#include <stdlib.h>

int main(){

	int n, i, dif, min;
	int sold[110];

	scanf("%d", &n );
	for( i = 0; i < n; i++ )
		scanf("%d", &sold[i] );
	
	min = 99999;
	for( i = 0; i < n-1; i++ ){
		dif = sold[i] - sold[i+1];
		if( dif < 0 ) dif = -dif;
		if( dif < min ) min = dif;
	}
	dif = sold[0] - sold[n-1];
	if( dif < 0 ) dif = -dif;
	if( dif < min ){
		printf("%d %d\n", 1, n );
	} else {

		for( i = 0; i < n-1; i++ ){
			dif = sold[i] - sold[i+1]; if( dif<0 ) dif = -dif;
			if( dif == min ){
				printf("%d %d\n", i+1, i+2 );
				break;
			}
		}
	}

	return 0;
}

