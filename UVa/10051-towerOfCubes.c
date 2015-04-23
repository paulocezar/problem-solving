/*
 *  Problema: Tower of Cubes ( UVa 10051 )
 *  Tecnica Utilizada:  DP ( baseado em Longest Path on a DAG )
 *	
 *		A entrada pode ser visualizada como um DAG. Os vertices sao os dados
 *		e suas rotacoes, e as arestas existem de vertices mais pesados para 
 *		os mais leves, quando a cor do topo do mais pesado e igual a de baixo 
 * 		mais leve.
 *		Dado esse grafo o problema se reduz a encontrar o maior caminho nesse DAG.
 *		Isso pode ser feito fazendo uma ordenacao topologica e uma especie de busca
 *		em profundidade seguindo a ordenacao topologica. Mas, pela especificacao da 
 *		entrada o grafo pode ser apenas implicito..  
 *
 *  Dificuldade: Medio-Dificil
 *	Complexidade:
 *				O( 6*N ^ 2 )
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 510
#define MAXV 6*MAXN

int parent[MAXV];
int maxDist[MAXV];
int cube[MAXN][6];
int op[6];

int main(){

	int N, V;
	int i, max;
	int u, v, ncase = 1;

	op[0] = 1;
	op[1] = 0;
	op[2] = 3;
	op[3] = 2;
	op[4] = 5;
	op[5] = 4;
	
	while( 1 ){
		scanf("%d", &N );
		if( N == 0 ) return 0;
		
		for( i = 0; i < N; i++ )
			scanf("%d %d %d %d %d %d", &cube[i][0], &cube[i][1], &cube[i][2], &cube[i][3], &cube[i][4], &cube[i][5]  );
		
		V = 6*N;
		for( i = 0; i < V; i++ ) maxDist[i] = 1, parent[i] = -1;
		
		max = 0;
		for( u = V-1; u >= 0; u-- ){
			if( maxDist[u] > max ) max = maxDist[u];
			for( v = u/6*6-1; v >= 0; v-- ){
				if( cube[u/6][u%6] == cube[v/6][ op[v%6] ] && maxDist[v] < maxDist[u]+1 ){
					parent[v] = u;
					maxDist[v] = maxDist[u]+1;
				}
			}
		}
		
		for( u = 0; u < V; u++ ){
			if( max == maxDist[u] ) break;
		}
		
		printf("Case #%d\n%d\n", ncase++, max );
		while( u > -1 ){
			switch( u % 6 ){
				case 0: printf("%d front\n", u/6+1 ); break;
				case 1: printf("%d back\n", u/6+1 ); break;
				case 2: printf("%d left\n", u/6+1 ); break;
				case 3: printf("%d right\n", u/6+1 ); break;
				case 4: printf("%d top\n", u/6+1 ); break;
				case 5: printf("%d bottom\n", u/6+1 ); break;
			}
			u = parent[u];
		}
		printf("\n");
		
	}
	
	return 0;
}
