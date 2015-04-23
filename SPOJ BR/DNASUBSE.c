#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 1010

int dp[MAXL][MAXL];
int pre[MAXL][MAXL];
char s1[MAXL], s2[MAXL];

int main(){

	int k, ss1, ss2;
	int i, j, t;

	while( 1 ){
	
		scanf("%d", &k ); getchar();
		if( k == 0 ) return 0;
		gets( s1+1 );
		gets( s2+1 );
		ss1 = strlen( s1+1 );
		ss2 = strlen( s2+1 );
		
		for( i = 1; i <= ss1; i++ ) dp[0][i] = pre[0][i] = 0;
		for( i = 1; i <= ss2; i++ ) dp[i][0] = pre[i][0] = 0;

		for( i = 1; i <= ss1; i++ ){
			for( j = 1; j <= ss2; j++ ){

				dp[i][j] = pre[i][j] = 0;

				if( dp[i][j-1] > dp[i][j] ) dp[i][j] = dp[i][j-1];
				if( dp[i-1][j] > dp[i][j] ) dp[i][j] = dp[i-1][j];
			
				if( s1[i] == s2[j] ){
					pre[i][j] = pre[i-1][j-1] + 1;
				
					if( pre[i][j] >= k ){
						for( t = k; t <= pre[i][j]; t++ ){
							if( (dp[i-t][j-t]+t) > dp[i][j] )
								dp[i][j] = dp[i-t][j-t]+t;
						}
					}
				}

			}
		}
		
		printf("%d\n", dp[ss1][ss2] );

	}

	return 0;
}

