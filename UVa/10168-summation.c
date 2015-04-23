#include <stdio.h>
#include <stdlib.h>

#define MAXP 10000001
#define MAXF 3165

char primo[MAXP];

int main(){

	int n, i , j;
	char even;

	primo[2] = 1;
	for( i = 3; i < MAXP; i++ )
		primo[i] = i % 2;

	for( i = 3; i < MAXF; i+=2 )
		if( primo[i] ){
			j = i+i;
			while( j < MAXP ){
				primo[j] = 0;
				j += i;
			}
		}
	
	while( scanf( "%d", &n ) != EOF ){

		if( n < 8 ) { puts( "Impossible." ); continue; }
		
		if( n & 1 ) even = 0, n -= 5;
		else 	  even = 1, n -= 4;

		i = n/2;
		if( i % 2 == 0 && i != 2 ) i++;

		while( ( primo[i] + primo[n-i] ) < 2 ) i -= 2;

		if( even ) printf("2 %d 2 %d\n", i, n-i );
		else 	   printf("3 %d 2 %d\n", i, n-i );

	}

	return 0;

}

