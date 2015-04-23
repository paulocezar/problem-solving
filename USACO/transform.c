/*
ID: knightp2
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 12

int N, i, j;

char before[MAXN][MAXN];
char after[MAXN][MAXN];

char r90(){
	for( i = 0; i < N; i++ )
		for( j = 0; j < N; j++ )
			if( after[i][j] != before[N-j-1][i] ) return 0;
	return 1;
}

char r180(){
	for( i = 0; i < N; i++ )
		for( j = 0; j < N; j++ )
			if( after[i][j] != before[N-i-1][N-j-1] ) return 0;  
	return 1;
}

char r270(){
	for( i = 0; i < N; i++ )
		for( j = 0; j < N; j++ )
			if( after[i][j] != before[j][N-i-1] ) return 0;	
	return 1;
}

char nochange( ){
	int i, j;
	for( i = 0; i < N; i++ ) for( j = 0; j < N; j++ ) if( before[i][j] != after[i][j] ) return 0;
	return 1;
}

char reflection(){
	for( i = 0; i < N; i++ ) 
		for( j = 0; j < N-j-1; j++ ){
			before[i][j] ^= before[i][N-j-1];
			before[i][N-j-1] ^= before[i][j]; 
			before[i][j] ^= before[i][N-j-1];
		}
	return nochange();
}

char combination( ){
	return ( r90() || r180() || r270() );
}


int main () {
        
    FILE *fin  = fopen("transform.in", "r");
    FILE *fout = fopen("transform.out", "w");
    
	fscanf( fin, "%d", &N );

	for( i = 0; i < N; i++ ) fscanf( fin, "%s", before[i] );
	for( i = 0; i < N; i++ ) fscanf( fin, "%s", after[i] );
	
	char noth = nochange();
	
	if( r90() ) fprintf(fout, "1\n" );
	else if( r180() ) fprintf(fout, "2\n" );
	else if( r270() ) fprintf(fout, "3\n" );
	else if( reflection() ) fprintf(fout, "4\n" );
	else if( combination() ) fprintf(fout, "5\n" );
	else if( noth ) fprintf(fout, "6\n" );
	else fprintf(fout, "7\n" );
	
    return 0;
}

