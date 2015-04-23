#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 21*1024
#define MAXP 101*1024

int t[MAXN];
int beg[MAXN];
int len[MAXN];

char tnote[MAXN], line[MAXP], newsppr[MAXP];
char lnewsppr[MAXP];
char *note;

char lower( char c ){
	if( 'A' <= c && c <= 'Z' ) return c-'A'+'a';
	return c;
}

int main(){
	
	int clipp, pos, cnd, nlen, prefSize, prefIni, i, k;
	
	fgets( tnote, MAXN, stdin );
	tnote[strlen(tnote)-1] = 0;
	
	newsppr[0] = 0;
	while( fgets( line, MAXP, stdin ) ) strcat( newsppr, line );
	
	line[0] = 0;
	clipp = 0;

	note = tnote;
	while( note[0] == ' ' ) note++;	
	while( note[0] ){
		
		nlen = strlen( note );
		pos = 2;
		cnd = 0;
		
		t[0] = -1;
		
		for( i = 1; i < nlen; i++ ){
			k = t[i-1];
			while( k >= 0 )
				if( note[k] == note[i-1] ) break;
				else k = t[k];
			t[i] = k+1;
		}
		
		prefSize = 0; prefIni = 0;
		for( i = k = 0; newsppr[i]; ){
			if( k == -1 ){ i++; k = 0; }
			else if( note[k] == lower( newsppr[i] ) ){
				i++; k++;
				if( k >= prefSize ){ prefSize = k; prefIni = i-k; if( prefSize >= nlen ) break; }
			} else k = t[k];
		}
				
		beg[clipp] = prefIni;
		len[clipp++] = prefSize;
		
		if( prefSize < nlen ){
			note += prefSize;
			while( note[0] == ' ' ) note++;
		} else note[0] = 0;
		
	}
	
	printf("%d\n", clipp );
	for( i = 0; i < clipp; i++){
		for( k = 0; k < len[i]; k++ ){
			putchar( newsppr[beg[i]+k] );
		}
		puts("");
	}

	return 0;
}
