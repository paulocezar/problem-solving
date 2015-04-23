#include <stdio.h>
#include <stdlib.h>

#define MAXN 1010

int main(){

	int t, r, n, ncase = 1;
	int i, pos, first, ncycles;	
	int cycleid[MAXN];
	char init[MAXN];
	long long queue[MAXN], cycle[MAXN];
	long long out, k;

	scanf( "%d", &t );
	while( t-- ){

		scanf("%d %lld %d", &r, &k, &n);
		for( i = 0; i < n; i++ ){
			scanf("%lld", &queue[i]);
			cycle[i] = 0, init[i] = 0;
		}

		ncycles = pos = 0;

		while( !init[pos] ){
			
			first = pos;
			init[pos] = 1;
			
			cycleid[pos] = ncycles;
			while( (cycle[ncycles]+queue[pos]) <= k ){
				cycle[ncycles] += queue[pos];
				pos++;
				if( pos == n ) pos = 0;
				if( pos == first ) break;
			}
			ncycles++;

		}
		
		first = cycleid[pos]-1;
		out = 0;
		
		for( i = 0; i <= first; i++ ) out += cycle[i];

		first = ( r - cycleid[pos] ) / ( ncycles - cycleid[pos] );
		for( i = cycleid[pos]; i < ncycles; i++ ) out += ( first * cycle[i] );
		
		first = ( r - cycleid[pos] ) % ( ncycles - cycleid[pos] );
		for( i = cycleid[pos]; first ; i++, first-- ) out += cycle[i];

		printf("Case #%d: %lld\n", ncase++, out );
		
	}

	return 0;
}

