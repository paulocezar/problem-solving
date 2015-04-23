#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATCH 0
#define INSERT 1
#define DELETE 2

int cost[25][25];
int parent[25][25];
char a[25], b[25];

int indx;

void print_path( int i, int j ){

	if( parent[i][j] == -1 ) return;

	if( parent[i][j] == MATCH ){
		print_path( i-1, j-1 );
		if( a[i] != b[j] ){
			printf("C%c%02d", b[j], indx );
		}
		indx++;
	}
	else if( parent[i][j] == INSERT ){
		print_path( i, j-1 );
		printf( "I%c%02d", b[j], indx );
		indx++;
	}
	else{
		print_path( i-1, j );
		printf( "D%c%02d", a[i], indx );
	}

}

int main(){

	int i, j, sa, sb;
	int sub, ins, rem;

	for( i = 1; i < 25; i++ )
		cost[i][0] = i, parent[i][0] = DELETE;
	for( i = 1; i < 25; i++ )
		cost[0][i] = i, parent[0][i] = INSERT;
	parent[0][0] = -1;

	while( 1 ){
	
		scanf("%s", a+1 );
		if( a[1] == '#' ) return 0;
		scanf("%s", b+1 );

		sa = strlen( a+1 );
		sb = strlen( b+1 );
		
		for( i = 1; i <= sa; i++ ){
			for( j = 1; j <= sb; j++ ){

				sub = cost[i-1][j-1];
				if( a[i] != b[j] ) sub++;

				ins = cost[i][j-1] + 1;
				rem = cost[i-1][j] + 1;

				cost[i][j] = sub;
				parent[i][j] = MATCH;
			
				if( ins < cost[i][j] ) {
					cost[i][j] = ins;
					parent[i][j] = INSERT;
				}

				if( rem < cost[i][j] ){
					cost[i][j] = rem;
					parent[i][j] = DELETE;
				}

			}
		}
		indx = 1;
		print_path( sa, sb );
		printf("E\n");
	}

	return 0;
}
