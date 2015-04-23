/*
 *  Problema: Rota Critica
 *  Tecnica Utilizada:  DFS + BFS ( Encontrar arborescencia / verificar se desliga algum vertice )
 *	
 *		 Podemos ver que existem semelhancas entre as arestas criticas do problema e pontes em grafos nao direcionados,
 * 		usando os conhecimentos de pontes, podemos concluir que, invertendo a direcao das arestas do grafo, ao encontrarmos
 *		uma arborescencia com raiz no vertice que representa a capital do estado, as arestas criticas do grafo estarao na 
 *		arborescencia ( assim como uma ponte sempre esta numa arvore geradora minima ). Assim, ao gerarmos uma arborescencia
 *		basta verificar quais arestas da arborescencia, quando tiradas do grafo, ocasionam que algum dos vertices nao possua caminho
 *		para a capital ( o que pode ser feito com um bfs partindo da capital no grafo invertido, desconsiderando a aresta removida. ).
 *      
 *  Dificuldade: Medio-Dificil
 *	Complexidade:
 *				O( N * (|V|+|E|) )
 */

#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <queue>

#define MAXN 110
#define MAXE 10010

using namespace std;

int graph[MAXN][MAXN];
int gr[MAXN];
bool critic[MAXN][MAXN];
bool visited[MAXN];
int in_arb;
int arb[MAXN][2];

string city[MAXN];
map< string, int > id;
int counter;

int edgeu[MAXE], edgev[MAXE];

void findArb( int u = 0 ){
	
	visited[u] = true;
	for( int w = 0; w < gr[u]; w++ ){
		int v = graph[u][w];
		if( !visited[v] ){
			arb[in_arb][0] = u;
			arb[in_arb][1] = v;
			in_arb++;
			findArb( v ); 
		}
	}
	
}

int main(){

	int N, M;
	int i, j, u, v;
	string cu, cv;
	bool nenhuma;
	queue< int > q;
	
	ios::sync_with_stdio( false );
	
	while( true ){
	
		cin >> N >> M;
		if( N+M == 0 ) return 0;
		
		for( i = 0; i < N; i++ ){
			cin >> city[i];
			id[city[i]] = i;
			visited[i] = false;
			gr[i] = 0;
			for( j = i; j < N; j++ )
				critic[i][j] = critic[j][i] = false;
		}
		
		for( i = 0; i < M; i++ ){
			cin >> cu >> cv;
			u = id[cu]; v = id[cv];
			graph[v][gr[v]++] = u;
			edgeu[i] = u; edgev[i] = v;
		}
		
		in_arb = 0;
		findArb();

		nenhuma = true;
		for( i = 0; i < in_arb; i++ ){
					
			for( u = 0; u < N; u++ ) visited[u] = false;
			counter = 0;
			q.push( 0 );
			visited[0] = true;
			bool flag = true;
			
			while( !q.empty() ){
				
				u = q.front(); q.pop();
				counter++;
				
				for( int w = 0; w < gr[u]; w++ ){
					v = graph[u][w];
					if( arb[i][0] == u && arb[i][1] == v && flag ) { flag = false; continue; }
					if( !visited[v] ){
						visited[v] = true;
						q.push( v );
					}
				}
				
			}
			
			if( counter != N ){
				nenhuma = false;
				critic[arb[i][1]][arb[i][0]] = true;
			}
			
		}
		
		if( nenhuma ) cout << "Nenhuma\n";
		else {
			for( i = 0; i < M; i++ ){
				if( critic[edgeu[i]][edgev[i]] ){ 
					cout << city[edgeu[i]] << " " << city[edgev[i]] << "\n";
				}
			}
		}
		cout << endl;
	
	}
	
	return 0;
}