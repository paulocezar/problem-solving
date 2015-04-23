/*
 *  Problema: A Bug’s Life ( Spoj Classical )
 *  Tecnica Utilizada:  BFS ( Grafo Bipartido )
 *	
 *		 Estamos querendo saber se todos os insetos podem ser classificados 
 *		como machos ou femeas, ou seja, se os insetos sao vertices, e as 
 *		relacoes arestas, queremos pintar os vertices de preto e branco 
 *		( macho e femea ) de modo que dois machos ou duas femeas nao se
 *		relacionem, em outras palavras, queremos verificar se o grafo
 *		e bipartido, o que pode ser feito usando um bfs para colorir os 
 *		vertices, se ao pintar os vizinhos de um vertice encontramos um
 *		vizinho que tem a mesma cor que o vertice atual, quer dizer que e
 *		impossivel haver uma biparticao.
 *
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( |V| + |E| )
 */


#include <stdio.h>
#include <stdlib.h>

#define MAXN 2010

int graph[MAXN][MAXN];
int color[MAXN];
int queue[MAXN];
int gr[MAXN];
int beg, end, N;

char bip(  ){
	
	int i, u, v, w;
	
	for( i = 1; i <= N; i++ ){
		if( color[i] == -1 ){
			beg = end = 0;
			queue[end++] = i;
			color[i] = 1;
			while( beg != end ){
				u = queue[beg++];
				for( w = 0; w < gr[u]; w++ ){
					v = graph[u][w];
					if( color[v] == -1 ){
						color[v] = 1-color[u];
						queue[end++] = v;
					} else if( color[v] != 1-color[u] ) return 0;
				}
			}
		}
	}
	
	return 1;
}

int main(){

	int sc, nsc, m;
	int u, v;
	
	scanf("%d", &nsc );
	for( sc = 1; sc <= nsc; sc++ ){
		scanf("%d %d", &N, &m );
		for( u = 1; u <= N; u++ )
			color[u] = -1, gr[u] = 0;
		while( m-- ){
			scanf("%d %d", &u, &v );
			graph[u][gr[u]++] = v;
			graph[v][gr[v]++] = u;
		}
		if( bip() ) printf("Scenario #%d:\nNo suspicious bugs found!\n", sc );
		else printf("Scenario #%d:\nSuspicious bugs found!\n", sc );
		 
	}
	
	return 0;
}