/*
 *  Problema: 769 - Critical Links
 *  Tecnica Utilizada:  Grafos - Pontes
 *	
 *		 O enunciado do problema deixa bem claro que devem ser encontradas
 *		todas as pontes de um grafo possivelmente desconexo.
 *  	O problema pode ser resolvido com uma busca em profundidade modificada.
 *
 *  Dificuldade: Facil-Medio
 *	Complexidade:
 *				O( V + E )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

int graph[MAXN][MAXN];
char bridge[MAXN][MAXN];
int gr[MAXN];
int parent[MAXN], lbl[MAXN], low[MAXN];

int counter, bridges;

void findBridges( int u ){

	int w, v;
	lbl[u] = counter++;
	low[u] = lbl[u];
	
	for( w = 0; w < gr[u]; w++ ){
		v = graph[u][w];
		if( lbl[v] == -1 ){
			parent[v] = u;
			findBridges( v );
			if( low[u] > low[v] ) low[u] = low[v];
			if( low[v] == lbl[v] ){
				bridge[u][v] = bridge[v][u] = 1;
				bridges++;
			}
		} else if( v != parent[u] && low[u] > lbl[v] )
			low[u] = lbl[v];
		
	}
	
}

int main(){

	int N;
	int i, j, u;
	
	while( scanf("%d", &N) != EOF ){
	
		
		for( i = 0; i < N; i++ ){
			scanf("%d (%d)", &u, &j );
			gr[u] = j;
			while( j ){
				scanf("%d", &graph[u][--j] );
			}
			lbl[i] = -1;
			for( j = i; j < N; j++ )
				bridge[i][j] = bridge[j][i] = 0;
		}
		
		
		counter = 0;
		bridges = 0;
		for( i = 0; i < N; i++ )
				if( lbl[i] == -1 )
					findBridges( i );
		
		printf("%d critical links\n", bridges);
		for( i = 0; i < N; i++ )
			for( j = i+1; j < N; j++ )
					if( bridge[i][j] )
						printf("%d - %d\n", i, j);
		puts("");
		
	}
	
	return 0;
}