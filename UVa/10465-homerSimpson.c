#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main(){

	int m, n, t, i;
	int best[MAX];
	int beers[MAX];

	while( scanf("%d %d %d", &m, &n, &t ) != EOF ){

		best[0] = 0;
		beers[0] = 0;

		for( i = 1; i <= t; i++ ){
			
			if( i-m >= 0 ){
			
				if( i-n >= 0 ){
					
					if(	beers[i-m] < beers[i-n] ){
						best[i] = best[i-m] + 1;
						beers[i] = beers[i-m];
					}
					else{
						if( beers[i-m] == beers[i-n] ){
							
							if( best[i-m] > best[i-n] ){
								best[i] = best[i-m] + 1;
								beers[i] = beers[i-m];
							} else {
								best[i] = best[i-n] + 1;
								beers[i] = beers[i-n];
							}
							
						} else {
							best[i] = best[i-n] + 1;
							beers[i] = beers[i-n];
						}
					}
				
				} else best[i] = best[i-m] + 1, beers[i] = beers[i-m];;
			
			}
			else if( i-n >= 0 ){
				best[i] = best[i-n] + 1;
				beers[i] = beers[i-n];
			}
			else best[i] = 0, beers[i] = i;
		
		}

		printf("%d", best[t] );
		if( beers[t] ) printf(" %d", beers[t] );
		printf("\n");

	}


	return 0;
}

