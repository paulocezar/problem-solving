#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min( int a, int b ){ if( a < b ) return a; return b; }

char name[ 2000 ];
int cost[ 2000 ];
int zero[ 2000 ];

int main(){

	int t, i, sz, ans;
	int z, ini, moves;

	scanf("%d", &t );
	while( t-- ){
	
		scanf("%s", name );
		
		i = 0;
		sz = 0;
		ans = 0;
		z = 0;

		while( name[i] ){
			cost[i] = min( name[i]-'A', 'Z'-name[i]+1  ) ;
			ans += cost[i];
			if( cost[i] == 0 ) zero[z++] = i;
			i++;
			sz++;
		}
		
		moves = sz-1;
		if( z ){
			ini = zero[0];
			for( i = 1; i < z; i++ ){
			 	if( zero[i] != zero[i-1]+1) {
					
					moves = min( moves, 2*((ini-1)>0?(ini-1):0) + (sz-zero[i-1]-1)  );
					moves = min( moves, 2*(sz-zero[i-1]-1) + ((ini-1)>0?(ini-1):0)  );
					
					ini = zero[i];
				}
			}
			moves = min( moves, 2*((ini-1)>0?(ini-1):0) + (sz-zero[z-1]-1)  );
			moves = min( moves, 2*(sz-zero[z-1]-1) + ((ini-1)>0?(ini-1):0)  );
			
		}
		
		ans += moves;
		if( ans < 0 ) ans = 0;
		printf("%d\n", ans );

	}

	return 0;
}

