#include <stdio.h>
#include <stdlib.h>

#define MAXN 110

int c[MAXN];
int comp( const void *a, const void *b ){
	return *(int*)a - *(int*)b;
}

int main () {
        
    FILE *fin  = fopen ("input.txt", "r");
    FILE *fout = fopen ("output.txt", "w");
    
	int n, X, i, out;
    
	fscanf (fin, "%d %d", &n, &X);

	for( i = 0; i < n; i++ ){
		fscanf (fin, "%d", &c[i] );
		c[i] *= (n-i);
	}	
	
	qsort( c, n, sizeof( int ), comp );
	
	out = 0;
	for( i = 0; i < n && X > 0; i++ ){
		X -= c[i];
		if( X >= 0 ) out++;
	}
	
    fprintf (fout, "%d\n", out );

    return 0;
}

