#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 21*1024
#define MAXP 101*1024

char tnote[MAXN], out[2*MAXN], newsppr[MAXP], lnewsppr[MAXP];
int suf[MAXP];
char *note;

int comp( const void* a, const void* b ){
   return strcmp( lnewsppr+(*(int*)a), lnewsppr+(*(int*)b) );
}

inline char lower( char c ){
	if( 'A' <= c && c <= 'Z' ) return c-'A'+'a';
	return c;
}

int main(){
	
	int i, nlen, maxP;
	int clipps, t, nsz, m, hi, lo, mid;
	char c;
	
	fgets( tnote, MAXN, stdin );
	tnote[strlen(tnote)-1] = 0;
	
	nsz = 0;
	while( (c = getchar()) != EOF ){ 
		newsppr[nsz] = c;
		lnewsppr[nsz] = lower( c );
		suf[nsz] = nsz;
		nsz++;
	}
	lnewsppr[nsz] = newsppr[nsz] = 0;
	
	qsort( suf, nsz, sizeof( int ), comp );
	out[0] = 0;
	note = tnote;
	clipps = 0;
	
	while( note[0] == ' ' ) note++;
	while( note[0] ){
		nlen = strlen( note );
		maxP = -1;
		lo = 0;
		hi = nsz;
		while( hi >= lo ){
			mid = (hi + lo)/2;
			for( i = 0; i < nlen; i++ ){
				t = note[i] - lnewsppr[suf[mid]+i];
				if( t ) break;
			}
			if( (i-1) > maxP ) maxP = i-1, m = mid;
			
			if( t == 0 ) break;
			if( t < 0 ) hi = mid-1;
			else lo = mid+1;
		}
		clipps++;
		strncat( out, newsppr+suf[m], maxP+1 );
		strcat( out, "\n" );
		note += (maxP+1);
		while( note[0] == ' ' ) note++;
	}

	printf("%d\n%s", clipps, out );	

	return 0;
}
