#include <stdio.h>
#include <stdlib.h>

int main () {
        
    FILE *fin  = fopen ("input.txt", "r");
    FILE *fout = fopen ("output.txt", "w");
    
	int n, a, i, dif;
	char c;
	
    fscanf (fin, "%d", &n );

	a = -1, dif = 500;
	for( i = 1; i <= n; i++ ){
		fscanf(fin, "%c", &c );
		if( c == '1' ){
			if( a == -1 ) a = i;
			else if( dif == 500 ) { dif = i-a; a = i; }
			else {
				if( i-a != dif ){
					break;
				}
				a = i;
			}
		}
	}
	if( i > n ) fprintf (fout, "YES\n" );	else fprintf (fout, "NO\n" );

    return 0;
}

