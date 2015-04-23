#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 15

using namespace std;

int comp( const void* a, const void* b ){
	return *(char*)a - *(char*)b;
}

int main(){

	int n, sz;
	char line[MAX];
	
	scanf("%d", &n ); getchar();

	while( n-- ){
		gets( line );
		sz = 0;
		while( line[sz] ) sz++;
		
		qsort( line, sz, sizeof( char ), comp );

		do puts( line );
		while( next_permutation( line, line+sz ) );
		puts("");
	}

	return 0;
}

