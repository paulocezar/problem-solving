/*
 *  Problema: Hooligan ( Nacional 2009 )
 *  Tecnica Utilizada:  Fluxo Maximo
 *
 *		  Considerando que o nosso time vai vencer todos os jogos que ele tem
 *		pela frente, queremos saber se os jogos dos outros times tem resultados
 *		validos, de modo que nenhum deles consiga mais pontos que o nosso time.
 *		
 *		  Podemos modelar o problema como sendo um grafo bipartido, onde:
 *		- Os vertices do conjunto da esquerda representam entre quais times ainda
 *		exitem partidas pendentes. Existem arestas da origem para esses vertices
 *		com capacidade 2*( Nro. de Jogos restantes entre os times ).
 *		- Os vertices do conjunto da direita representam os times, com excessao do nosso.
 *		Esses vertices tem arestas ligadas ao sorvedouro, com capacidade:
 *			( pontos[0] - pontos[time] - 1 ), ou seja, a pontuacao maxima que o time
 *		pode ganhar, de modo que ele continua tendo menos pontos que o nosso time.
 *		Se esse valor for negativo, ja podemos concluir que nosso time nao pode ganhar.
 *		As arestas do conjunto da esquerda, para o conjunto da direita vao para os
 *		times representados e tem capacidade "infinita".
 *
 *		Dado esse grafo, so precisamos encontrar o fluxo maximo, caso ele seja
 *		igual ao numero total de pontos que devem ser disputados, e possivel que
 *		o nosso time ganhe, caso contrario, nao ha resultados validos dos jogos que
 *		levem nosso time a vencer.
 *      
 *  Dificuldade: Medio-Facil
 *	Complexidade:
 *				O( ? )
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 45
#define INF 0x3F3F3F3F
#define MAXV ((MAXN*MAXN/2)+MAXN+2)

int N, M, G;
int played[MAXN][MAXN];
int points[MAXN];
int flow[MAXV][MAXV];
int graph[MAXV][MAXV];
int gr[MAXV];
char cr[MAXV];
int T, curFlow;

char has_path( int u ){

	int v, w, oldFlow;
	if( u == T ) return 1;

	cr[u] = 0;

	for( w = 0; w < gr[u]; w++ ){
		v = graph[u][w];
		if( flow[u][v] && cr[v] ){
			oldFlow = curFlow;
			if( flow[u][v] < curFlow ) curFlow = flow[u][v];
			if( has_path( v ) ){
				flow[u][v] -= curFlow;
				flow[v][u] += curFlow;
				cr[u] = 1;
				return 1;
			} else curFlow = oldFlow;
		}
	}

	cr[u] = 1;
	return 0;
}

int main(){

	int i, j, a, b, v, f, MAX;
	char c;
	
	while( 1 ){
hell:	
		scanf("%d %d %d", &N, &M, &G );
		if( N+M+G == 0 ) return 0;
	
		for( a = 0; a < N; a++ ){
			points[a] = 0;
			for( b = a; b < N; b++ )
				played[a][b] = 0;
		}
		
		for( i = 0; i < G; i++ ){
			scanf("%d %c %d", &a, &c, &b );
			played[a][b]++; played[b][a]++;
			if( c == '=' ) points[a]++, points[b]++;
			else if( c == '<' ) points[b] += 2;
		}
		
		v = 0;
		for( i = 1; i < N; i++ )
			for( j = i+1; j < N; j++ )
				if( played[i][j] != M ) v++;
		T = N+v;
					
		for( i = 0; i <= T; i++ ) gr[i] = 0, cr[i] = 1;
		
		v = 0;
		MAX = 0;
		for( i = 1; i < N; i++ )
			for( j = i+1; j < N; j++ )
				if( played[i][j] != M ){
					a = N+v;
					graph[0][gr[0]++] = a;
					graph[a][gr[a]++] = 0;
					flow[0][a] = 2*(M-played[i][j]);
					flow[a][0] = 0;
					MAX += flow[0][a];
					
					graph[a][gr[a]++] = i;
					graph[a][gr[a]++] = j;
					graph[i][gr[i]++] = a;
					graph[j][gr[j]++] = a;
					
					flow[a][i] = flow[0][a];
					flow[a][j] = flow[0][a];
					flow[i][a] = 0;
					flow[j][a] = 0;
					
					v++;
				}
				
		for( i = 1; i < N; i++ )
			points[0] += 2*( M - played[0][i] );
		
		for( i = 1; i < N; i++ ){
			graph[i][gr[i]++] = T;
			graph[T][gr[T]++] = i;
			a = points[0] - points[i] - 1;
			if( a < 0 ){
				puts("N");
				goto hell;
			}
			flow[i][T] = a;
			flow[T][i] = 0;
		}
		
		f = 0;
		curFlow = INF;
		while( has_path( 0 ) ){
			f += curFlow;
			curFlow = INF;
		}
		if( f == MAX ) puts("Y");
		else puts("N");
		
	}

	return 0;
}
