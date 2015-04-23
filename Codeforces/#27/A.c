#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char used[3001];

int main(){

	int n, t;
	int nxt;

	scanf("%d", &n );
	memset( used, 0, sizeof( used ) );

	nxt = 1;
	while( n-- ){
		scanf("%d", &t );
		used[t] = 1;
		while( used[nxt] ) nxt++;
	}

	printf("%d", nxt );

	return 0;

}
