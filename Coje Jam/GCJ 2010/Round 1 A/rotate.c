#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 55

int n, k;
char grid[MAXN][MAXN];
char red, blue;

char line( int i, int j, char color ){
	int count = 0;
	while( j < n && color == grid[i][j] && count < k ) count++, j++;
	if( count == k ) return 1;
	return 0;
}

char up( int i, int j, char color ){
	int count = 0;
	while( i >= 0 && color == grid[i][j] && count < k ) count++, i--;
	if( count == k ) return 1;
	return 0;
}


char left( int i, int j, char color ){
	int count = 0;
	while( i >= 0 && j >=0 && color == grid[i][j] && count < k ) count++, i--, j--;
	if( count == k ) return 1;
	return 0;
}

char right( int i, int j, char color ){
	int count = 0;
	while( i >= 0 && j < n && color == grid[i][j] && count < k ) count++, i--, j++;
	if( count == k ) return 1;
	return 0;
}

int main(){

	int i, j, x, ct, t;
	int next[MAXN];
	char tGrid[MAXN][MAXN];

	scanf("%d", &t );

	for( ct = 1; ct <= t; ct++ ){
		scanf("%d %d", &n, &k ); getchar();
		
		memset( next, 0, sizeof( int ) * n );
		red = blue = 0;

		for( i = 0; i < n; i++ ){
			for( j = 0; j < n; j++ )
				tGrid[i][j] = getchar(), grid[i][j] = '.';
			getchar();
		}
		
		for( i = n-1; i >= 0; i-- ){
			for( j = n-1; j >= 0; j-- ){
				if( tGrid[i][j] == '.' ) continue;
				x = n-i-1;
				grid[n-next[x]-1][x] = tGrid[i][j];
				next[x]++;
			}
		}
		
		for( i = n-1; i >= 0 && ( !red || !blue ); i-- ){
			 for( j = 0; j < n && ( !red || !blue ); j++ ){
			 		if( grid[i][j] == '.' ) continue;
					if( !red && line( i, j, 'R' ) ) red = 1;
					if( !blue && line( i, j, 'B' ) ) blue = 1;
			 		if( !red && up( i, j, 'R' ) ) red = 1;
					if( !blue && up( i, j, 'B' ) ) blue = 1;
					if( !red && left( i, j, 'R' ) ) red = 1;
					if( !blue && left( i, j, 'B' ) ) blue = 1;
					if( !red && right( i, j, 'R' ) ) red = 1;
					if( !blue && right( i, j, 'B' ) ) blue = 1;
			 }
		}

		if( red && blue ) printf("Case #%d: Both\n", ct );
		else if( red ) printf("Case #%d: Red\n", ct );
		else if( blue ) printf("Case #%d: Blue\n", ct );
		else printf("Case #%d: Neither\n", ct );

	}

	return 0;
}

