#include <stdio.h>
#include <stdlib.h>

int comp( const void *a, const void *b ){
	return *(int*)a - *(int*)b;
}

int main(){

	char seq[600];
	int page[110];
	int n, j, i;
	char *ptr;
	int beg, end;
	char flag;

	i = 0;
	gets( seq );
	ptr = seq; j = 0;
	while( *ptr ) {
		sscanf( ptr, "%d", &page[i] ); i++;
		while( seq[j] && seq[j] != ',' ) j++;
		if( seq[j] == ',' ) j++;
		ptr = seq + j;
	}
	n = i;
	qsort( page, n, sizeof( int ), comp );
	
	beg = end = page[0];
	flag = 0;
	for( i = 1; i < n; i++ ){
		 if( page[i] == end ) continue;
		 if( page[i] == end+1 ) end++;
		 else{
		 	if( flag ) printf(",");
			else flag = 1;

		 	if( beg != end ){
				printf("%d-%d", beg, end );
		 	} else printf("%d", beg );
			beg = end = page[i];
		 }
	}
	if( flag ) printf(",");
	if( beg != end ) printf("%d-%d\n", beg, end );
	else printf("%d\n", beg );

	return 0;
}

