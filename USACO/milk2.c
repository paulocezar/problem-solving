/*
ID: knightp2
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
        
    FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");
    int n, a, b, min, max, with, out, cont;
	char has[1000010];
	char flag;

	memset( has, 0, sizeof( has ) );
	fscanf (fin, "%d", &n );
	min = 2000000;
	max = 0;
	while( n-- ){
		fscanf (fin, "%d %d", &a, &b);
		memset( has+a, 1, sizeof(char)*(b-a) );
    	if( a < min ) min = a;
		if( b > max ) max = b;
	}

	with = out = 0;
	while( min < max ){
		flag = has[min];
		cont = 0;
		while( has[min] == flag && (min<=max) ) cont++, min++;
		if( flag && (cont > with) ) with = cont;
		if( (flag == 0) && (cont > out) ) out = cont; 
	}
	
	fprintf (fout, "%d %d\n", with, out );

    return 0;
}

