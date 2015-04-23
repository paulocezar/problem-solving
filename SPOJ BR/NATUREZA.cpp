#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#define MAXN 5001

using namespace std;

int parent[MAXN], rank[MAXN], nodes[MAXN];
map< string, int > animal;

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

	int n, m;
	int i, max;
	string a, b;
	ios::sync_with_stdio( false );
	
	while( true ){

		cin >> n >> m;
		if( n+m == 0 ) return 0;
		
		for( i = 0; i < n; i++ ){
			cin >> a;
			parent[i] = i;
			rank[i] = 0;
			nodes[i] = 1;
			animal[ a ] = i;
		}

		while( m-- ){
			
			cin >> a >> b;
			fUnion( find( animal[a] ), find( animal[b] ) );

		}
		
		max = nodes[0];
		for( i = 1; i < n; i++ )
			if( nodes[i] > max ) max = nodes[i];
	
		printf("%d\n", max );
	
	}


	return 0;
}

