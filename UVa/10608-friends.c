#include <stdio.h>
#include <stdlib.h>

#define MAXN 30001

int parent[MAXN], rank[MAXN], nodes[MAXN];

void init( int n ){
	int i;
	for( i = 1; i <= n; i++ ) 
		parent[i] = i, rank[i] = 0, nodes[i] = 1;
}

int find( int id ){
	int a = id, b = id;
	
	while( parent[a] != a ) a = parent[a];
	
	while( parent[b] != a ){
		id = parent[b];
		parent[b] = a;
		b = id;
	}
	return a;
}

void fUnion( int x, int y ){
	if( x == y ) return;
	
	if( rank[x] < rank[y] ){
		x ^= y; y ^= x; x ^= y;
	}
	
	if( rank[x] == rank[y] ) rank[x]++;
	parent[y] = x;
	nodes[x] += nodes[y];
}			

int main(){

	int t, n, m;
	int a, b;
	int max;
	scanf("%d", &t );

	while( t-- ){

		scanf("%d %d", &n, &m );

		init( n );

		while( m-- ){
			
			scanf("%d %d", &a, &b );
			fUnion( find( a ), find( b ) );

		}
		
		max = nodes[1];
		for( a = 2; a <= n; a++ )
			if( nodes[a] > max ) max = nodes[a];
	
		printf("%d\n", max );
	
	}


	return 0;
}

