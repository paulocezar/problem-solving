#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int n, m, st = 1;
	int i, v;
	int bit[7];
	char result[1<<7];
	char num[8];
	char xis[4];

	while( 1 ){

		scanf("%d", &n );
		if( n == 0 ) return 0;
		getchar();
		printf("S-Tree #%d:\n", st++ );

		for( i = 0; i < n; i++ ){
			scanf("%s", xis );
			bit[i] = xis[1]-'0'-1;
		}
		scanf("%s", result );

		scanf("%d", &m );
		while( m-- ){
			scanf("%s", num );
			v = 0;
			for( i = 0; i < n; i++ ){
				v <<= 1;
				if( num[ bit[i] ] == '1' ) v |= 1;
			}
			printf("%c", result[v] );
		}
		printf("\n\n");
	}

	return 0;
}

