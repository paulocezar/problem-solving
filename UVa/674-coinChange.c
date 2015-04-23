#include <stdio.h>
#include <stdlib.h>

#define MAX 7490

int main(){

	unsigned int changes[MAX] = {  0 };
	int coins[] = { 1, 5, 10, 25, 50 };
	int n, i, j, coin;

	changes[0] = 1;

	for( i = 0; i < 5; i++ ){
	     coin = coins[i];
	     for( j = 1; j < MAX; j++ )
		if( (j - coin) >= 0 ) changes[j] += changes[j-coin];
	}

	while( scanf("%d", &n ) != EOF ) printf("%u\n", changes[n] );  		

	return 0;
}

