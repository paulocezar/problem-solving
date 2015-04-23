#include <stdio.h>
#include <stdlib.h>

int graph[2100][2100];
int grau[2100];
int fila[2100];

char cor[2100];

int b, m, ini, fim;

char bipartido(){

	int u, w, v;

	for( u = 1; u <= b; u++ ){
		
		if( cor[u] == -1 ){

			ini = fim = 0;
			fila[fim++] = u;
			cor[u] = 1;

			while( ini != fim ){
				
				v = fila[ini++];
				for( w = 0; w < grau[v]; w++ ){
					if( cor[graph[v][w]] == -1 ){
						fila[fim++] = graph[v][w];
						cor[graph[v][w]] = 1 - cor[v];
					 } else if( cor[graph[v][w]] == cor[v] ) return 0;
				}

			}

		}

	}

	return 1;
}


int main(){

	int ct, i, t, u, v;

	scanf("%d", &t );
	for( ct = 1; ct <= t; ct++ ){

		scanf("%d %d", &b, &m ); 
		for( i = 1; i <= b; i++ ) { cor[i] = -1; grau[i] = 0; }

		while( m-- ){
			scanf("%d %d", &u, &v );
			graph[u][grau[u]++] = v;
			graph[v][grau[v]++] = u;
		}

		printf("Cenario #%d:\n", ct );
		if( bipartido() ) puts( "Nenhum besouro suspeito encontrado!\n" );
		else puts( "Besouro suspeito encontrado!\n" );

	}


	return 0;
}

