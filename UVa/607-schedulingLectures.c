#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1100
#define INF 0x3F3F3F3F

int min( int a, int b ){ if( a < b ) return a; return b; }

int topic[MAXN];
int memo[MAXN][MAXN];
char solved[MAXN][MAXN];
int n, l, c;

/* calculate the dissatisfaction of a lecture with duration ttime. */
int dis( int ttime ){
	if( (l-ttime) == 0 ) return 0;
	if( (l-ttime) <= 10 ) return -c;
	return (l-ttime-10)*(l-ttime-10);
}

/* find the best covering of [from ... n-1] topics in 'lectures' lectures. */
int solve( int from, int lectures ){
	
	/* if have covered all topics using all lectures .. I'm done. */
	if( from == n && lectures == 0 ) return 0;
	
	/* if past all topics but there still lectures or used all lectures but still have uncovered topics */
	if( lectures == 0 || from == n ) return INF;
	
	if( solved[from][lectures] ) return memo[from][lectures];
	
	int ans = INF;
	int sum = 0;
	int i;
	
	/* create all possible lectures starting with 'from' topic and stay with the best */
	for( i = from; i < n ; i++ ){
		sum += topic[i];
		if( sum > l ) break;
		ans = min( ans, dis( sum ) + solve( i+1, lectures-1 ) );
	}
	
	solved[from][lectures] = 1;
	return ( memo[from][lectures] = ans );
	
}

int main(){

	int i, j, x, sum;
	int t = 1, lect;

	while( 1 ){
		
		scanf("%d", &n );
		if( n == 0 ) return 0;
		if( t > 1 ) printf("\n");
		
		scanf("%d %d", &l, &c );
		
		lect = 0;
		sum = 0;
		for( i = 0; i < n; i++ ){
			scanf("%d", &x );
			sum += x;
			if( sum > l ){
				lect++;
				sum = x;
			} else if( sum == l ){
				lect++;
				sum = 0;
			}
			for( j = 0; j < n+1; j++ )
				solved[i][j] = 0;
			topic[i] = x;
		}

		if( sum ) lect++;
		
		printf("Case %d:\nMinimum number of lectures: %d\nTotal dissatisfaction index: %d\n", t++, lect, solve( 0, lect ) );

	}

	return 0;
}
