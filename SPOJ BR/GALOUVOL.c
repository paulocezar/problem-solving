#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXR 110
#define MAXC 110

char grid[MAXR][MAXC];
int r, c;

void flood( int i, int j, char n ){
	
	char nxt;

	if( i < 0 || i >= r ) return;
	if( j < 0 || j >= c ) return;
	
	if( grid[i][j] == '.' ) return;
	
	if( n == 'B' ){
		if( grid[i][j] == n ) return; 
	}
	else if( grid[i][j] != '*' ) return;
	
	if( n == '(' ) nxt = ')';
	else if( n == ')' ) nxt = '(';
	else nxt = 'B';

	grid[i][j] = n;
	
	flood( i-1, j, nxt ); 
	flood( i-1, j+1, nxt );
	flood( i, j-1, nxt );
	flood( i, j+1, nxt );
	flood( i+1, j-1, nxt );
	flood( i+1, j, nxt );

}

char blocked( int i, int j ){
	if( j+1 < c && grid[i][j+1] == grid[i][j] ) return 1;
	if( i+1 < r ){
		if( j-1 > -1 && grid[i+1][j-1] == grid[i][j] ) return 1;
		if( grid[i+1][j] == grid[i][j] ) return 1;
	}
	return 0;
}

int main(){

	int i, j;

	while( 1 ){

		scanf("%d %d", &r, &c ); getchar();
		if( r+c == 0 ) return 0;

		for( i = 0; i < r; i++ )
			scanf("%s", grid[i] );
			
		for( i = 0; i < r; i++ )
			for( j = 0; j < c; j++ )
				if( grid[i][j] == 'I' ) {
					grid[i][j] = '*';
					flood( i, j, '(' );
				}

		for( i = 0; i < r; i++ )
			for( j = 0; j < c; j++ )
				if( grid[i][j] == '*' )
					grid[i][j] = 'F';

		for( i = 0; i < r; i++ )
			for( j = 0; j < c; j++ )
				if( grid[i][j] == ')' || grid[i][j] == '(' ){
					if( blocked( i, j ) ) flood( i, j, 'B');
				}

		for( i = 0; i < r; i++ )
			puts( grid[i] );

	}

	return 0;
}



