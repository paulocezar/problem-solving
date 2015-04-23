#include <stdio.h>
#include <stdlib.h>

#define MAXN 1100

int flow[MAXN][MAXN];

inline int abs( int x ){ if( x < 0 ) return -x; return x; }

int main(){

	int n, ct, i, j;
	int sum, cur, dif;

	ct = 1;
	while( 1 ){
		
		scanf("%d", &n );
		if( n == 0 ) return 0;
		
		sum = 0;
		for( i = 0; i < n; i++ ){
			for( j = 0; j < n; j++ ){
				scanf("%d", &flow[i][j] );
				sum += flow[i][j];
			}
		}
		
		dif = 0;
		for( i = 0; i < n; i++ ){
			cur = 0;
			for( j = 0; j < n; j++ ){
				cur += flow[i][j];
				cur -= flow[j][i];
			}
			dif += abs( cur );
		}
		printf("%d. %d %d\n", ct++, sum, dif/2 );
	}

	return 0;
}

