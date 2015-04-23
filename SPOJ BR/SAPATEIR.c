/*
 *  Problema: O Problema do Sapateiro Viajante
 *  Tecnica Utilizada:  Teoria dos Grafos ( Circuito Euleriano + Arestas de Corte )
 *	
 *		  Representando o grafo como sendo as confederacoes, e as arestas entre 
 *		confederacoes como sendo as cidades que pertencem a mais de uma confederacao
 *		reduzimos o problema a encontrar um circuito euleriano no grafo.
 *		  Caso haja um ciclo no grafo, qualquer cidade serve para o inicio,
 *		como queremos a menor delas, a resposta e zero.
 *		  Se nao houver ciclo, a cidade inicial esta em uma das confederacoes
 *		de grau impar, e sera a menor cuja aresta que ela representa nao e uma
 *		ponte ou onde a confederacao tem apenas uma cidade.
 *      
 *  Dificuldade: Dificil
 *	Complexidade:
 *				O( V + E )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 510
#define MAXC 110

int conf[MAXN][2];
int grau[MAXC];
int grafo[MAXC][MAXC];
char ponte[MAXC][MAXC];
int lbl[MAXC], low[MAXC], parent[MAXC];
int el[MAXC];
int NEED, n, visitou;

void buscaPontes( int u ){
	int w, v;
	lbl[u] = visitou++;
	low[u] = lbl[u];
	for( w = 0; w < grau[u]; w++ ){
		
		v = grafo[u][w];
		if( lbl[v] == -1 ){
			parent[v] = u;
			buscaPontes( v );
			if( low[u] > low[v] ) low[u] = low[v];
			if( low[v] == lbl[v] ){
				ponte[u][v] = ponte[v][u] = 1;
			}
		}
		else if( v != parent[u] && low[u] > lbl[v] ){
			low[u] = lbl[v];
		} else if( parent[v] == u ){
			/* Se tem multiplas arestas, nao e ponte. */
			ponte[u][v] = ponte[v][u] = 0;
		}

	}
	
}

char conexo( int orig ){
	visitou = 0;
	buscaPontes( orig );
	if( visitou == NEED ) return 1;
	return 0;
}


int main(){

	int c, i, k, u, odd;	
	int empt;
	int orig;
	
	while( 1 ){
	
		scanf("%d %d", &n, &c );
		if( n+c == 0 ) return 0;
	
		for( i = 0; i < c; i++ ){
			grau[i] = 0;
			lbl[i] = -1;
			el[i] = 0;
			for( k = 0; k < c; k++ ) ponte[i][k] = 0;
		}
		for( i = 0; i < n; i++ ) conf[i][0] = conf[i][1] = -1;
		
		/* Faz a leitura e monta o grafo */
		empt = 0;
		for( i = 0; i < c; i++ ){
			scanf("%d", &k );
			/* Ignora confederacoes vazias */
			if( k == 0 ) empt++;
			el[i] = k;
			while( k ){
				orig = i;
				k--;
				scanf("%d", &u );
				if( conf[u][0] == -1 ) conf[u][0] = i;
				else { 
					conf[u][1] = i; 
					grafo[i][grau[i]++] = conf[u][0]; 
					grafo[conf[u][0]][grau[conf[u][0]]++] = i;
				}
			}
		}
		
		odd = 0;
		for( i = 0; i < c; i++ ) odd += (grau[i] % 2);
		
		/* Para verificar se e conexo, so precisa ser levado em conta
		  confederacoes nao vazias. Verifica se e conexo usando dfs para
		 ja calcular as pontes. */
		NEED = c - empt;
		if( !conexo(orig) ) puts("-1");
		else if( odd == 0 ) puts("0");
		else if ( odd > 2 ) puts("-1");
		else{
			
			/* Procurando a menor cidade que nao representa uma ponte 
			   ou esta em uma cidade isolada.. */
			for( i = 0; i < n; i++ ){
				
				if( conf[i][1] != -1 ){
					if( (grau[conf[i][0]]%2 || grau[conf[i][1]]%2)
					      && !ponte[conf[i][0]][conf[i][1]] ){
							printf("%d\n", i );
							break;
					}
					if( (el[conf[i][0]] == 1 && grau[conf[i][0]] == 1) 
					     || ( el[conf[i][1]] == 1 && grau[conf[i][1]] == 1) ){
						printf("%d\n", i );
						break;
					}
					
				}
				else if( grau[conf[i][0]]%2 ){
					if( grau[conf[i][0]] == 1 ){
						printf("%d\n", i );
						break;
				
					}
				}
			}
		}
		
	}

	return 0;
}
