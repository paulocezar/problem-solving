#include <stdio.h>
#include <stdlib.h>

 int main(){

 int m, n, i, j, f=0;
 char c;

 scanf("%d %d", &m, &n );

 while( m>0 && n>0 ){

	f++;
	if( f != 1 ) printf("\n");
	int field[m+2][n+2];

	for( i = 0; i<m+2; i++)
		for( j = 0; j<n+2; j++ )
			field[i][j] = 48;

	for( i = 1; i<m+1; i++){
		scanf("%c", &c);
		for( j = 1; j<n+1; j++ ){
			scanf("%c", &c);
			if( c == 42 ) {

				field[i][j] = 42;
				
				if( field[i-1][j-1] != 42 ) field[i-1][j-1]++;
				if( field[i-1][j] != 42 ) field[i-1][j]++;
				if( field[i-1][j+1] != 42 ) field[i-1][j+1]++;
				if( field[i][j-1] != 42 ) field[i][j-1]++;
				if( field[i][j+1] != 42 ) field[i][j+1]++;
				if( field[i+1][j-1] != 42 ) field[i+1][j-1]++;
				if( field[i+1][j] != 42 ) field[i+1][j]++;
				if( field[i+1][j+1] != 42 ) field[i+1][j+1]++;

			}

		}


	}

	printf("Field #%d:\n",f);
	for( i = 1; i<m+1; i++){
		for( j = 1; j<n+1; j++ )
			printf("%c", field[i][j]);
		printf("\n");
	}



	scanf("%d %d", &m, &n );
 }

 return 0;

}
