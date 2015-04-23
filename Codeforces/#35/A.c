#include <stdio.h>
#include <stdlib.h>

int main () {
        
    FILE *fin  = fopen ("input.txt", "r");
    FILE *fout = fopen ("output.txt", "w");
    int fst, cup[4], a, b;
	
	cup[1] = cup[2] = cup[3] = 0;
    fscanf (fin, "%d", &fst );	
	cup[fst] = 1;
    fscanf (fin, "%d %d", &a, &b );
	cup[a] ^= cup[b]; cup[b] ^= cup[a]; cup[a] ^= cup[b];
    fscanf (fin, "%d %d", &a, &b );
	cup[a] ^= cup[b]; cup[b] ^= cup[a]; cup[a] ^= cup[b];
    fscanf (fin, "%d %d", &a, &b );
	cup[a] ^= cup[b]; cup[b] ^= cup[a]; cup[a] ^= cup[b];
	
	for( fst = 1; fst < 4; fst++ ){
		if( cup[fst] ) { fprintf (fout, "%d\n", fst ); break; }
	}

    return 0;
}

