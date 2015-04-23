#include <iostream>
#include <queue>
#include <string.h>
#define MAX_C 101

using namespace std;

int main(){

	int n, teste = 1;
	int grafo[MAX_C][MAX_C];
	int grau[MAX_C];

	while( 1 ){
		scanf("%d", &n );
		if( n == 0 ) break;

		if( n == 1 ){
			printf("Teste %d\n1\n\n", teste++ );
			continue;
		}

		memset( grafo, 0, sizeof( grafo ) );
		memset( grau, 0, sizeof( grau ) );

		int x, y;
		for( int i = 1; i < n; i++ ){
			scanf("%d %d", &x, &y);
			grau[x]++;
			grau[y]++;
			grafo[x][y] = grafo[y][x] = 1;
		}
		if( n == 2 ){
			printf("Teste %d\n1\n\n", teste++ );
			continue;
		}
		
		queue<int> q;
		for( int i = 1; i <= n; i++ )
			if( grau[i] == 1 )
				q.push( i );

		while( q.size() > 1 ){

			int u = q.front(); q.pop();

			for( int v = 1; v <= n; v++ )
				if( grafo[u][v] ){
					grafo[u][v] = grafo[v][u] = 0;
					grau[v]--;
					if( grau[v] == 1 )
						q.push( v );
					break;
				}

		}

		printf("Teste %d\n%d\n\n", teste++, q.front() );

	}


	return 0;
}

