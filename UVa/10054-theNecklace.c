#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int grafo[55][55];
int grau[55];
char visited[55];
int stk[1111];
int pstk;

void findtour( int u ){
	int v;
	for( v = 1; v < 51; v++ ) if( grafo[u][v] ){
		grafo[u][v]--;
		grafo[v][u]--;
		findtour( v );
	}
	stk[pstk++] = u;
}

int main(){

	int t, test, u, v, i;
	int fila[55];
	int ini, fim;
	int nv;

	scanf("%d", &t );
	for( test = 1; test <= t; test++ ){
	
		scanf("%d", &n );
		memset( grau, 0, sizeof( grau ) );
		memset( grafo, 0, sizeof( grafo ) );
		memset( visited, 0, sizeof( visited ) );
		
		for( i = 0; i < n; i++ ){
			scanf("%d %d", &u, &v );
			grafo[u][v]++;
			grafo[v][u]++;
			grau[u]++;
			grau[v]++;
		}
		
		nv = 0;
		for( u = 1; u < 51; u++ )
			if( grau[u] % 2 ){ printf("Case #%d\nsome beads may be lost\n\n", test ); goto hell; } 
			else if( grau[u] ) nv++;

		ini = fim = 0;
		for( u = 1; u < 51; u++ ) if( grau[u] ) break;
		
		visited[u] = 1;		
		fila[fim++] = u;
		
		while ( ini != fim ) {
			u = fila[ini++];
			for( v = 1; v < 51; v++ ){
				if( grafo[u][v] && !visited[v] ){
					visited[v] = 1;
					fila[fim++] = v;
				}
			}
		}
		
		for( u = 1; u < 51; u++ ){
			if( grau[u] && !visited[u] ){
				printf("Case #%d\nsome beads may be lost\n\n", test ); goto hell;
			}
		}
		
		
		printf("Case #%d\n", test );
		
		pstk = 0;
		for( u = 1; u < 51; u++ ) if( grau[u] & 1 ){ findtour( u ); break; }
		if( pstk == 0 ){
			for( u = 1; u < 51; u++ ) if( grau[u] ){ findtour( u ); break; }
		}
		
		for( v = 0; v < pstk-1; v++ ) printf("%d %d\n", stk[v], stk[v+1] );
		puts("");
		
		hell: u = 1;

	}

	return 0;
}

