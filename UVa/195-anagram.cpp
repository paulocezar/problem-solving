#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 1005

using namespace std;

int value['z'+1];

int compF( const void* a, const void* b ){
	return value[(*(char*)a)] - value[(*(char*)b)];
}

class compare {
	public:
	bool operator()( char a, char b ){
		return ( value[a] < value[b] );
	}
};

int main(){

	int i, j, n, sz, k = 0;
	char line[MAXN];
	compare comp;

	for( i = 'A', j = 'a'; i <= 'Z'; i++, j++ )
	     {	value[i] = k++; value[j] = k++; }

	scanf("%d", &n ); getchar();
	while( n-- ){
		gets( line );
		sz = strlen( line );
		qsort( line, sz, sizeof( char ), compF );

		do puts( line );
		while( next_permutation( line, line+sz, comp ) );
	}

	return 0;
}
