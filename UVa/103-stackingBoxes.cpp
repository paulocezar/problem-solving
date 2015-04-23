/*
 *  Problema: Stacking Boxes ( UVa 103 )
 *  Tecnica Utilizada:  DP ( Longest Path on DAG based )
 *	
 *		 Queremos empilhar o maximo de caixas possivel. So podemos empilhar
 *		uma caixa em cima de uma cuja para alguma permutacao das dimensoes,
 *		todos os valores da de baixo sejam maiores que os da de cima.
 *		Como a permutacao nao tem uma regra especifica, para facilitar e so
 *		ordenar o vetor das dimensoes em ordem crescente.
 *		 Agora, podemos ver as caixas como vertices de um grafo, e as arestas
 *		que saem de uma caixa sao direcionadas a todas as caixas cujas dimensoes
 *		sao menores. Com esse grafo definido, basta que facamos uma ordenacao 
 *		topologica, e com uma busca modificada encontremos a maior profundidade.
 *		 Para fazer isso, basta ordenar o vetor das caixas em ordem crescente, 
 *		considerando que uma caixa e menor que outra se tem todas as dimensoes menores
 *		que ela, e ir iterando das maiores para as menores, tentando aumentar o 
 *		tamanho dos caminhos..
 *
 *  Dificuldade: Medio-Facil
 *	Complexidade:
 *				O( n^2 )
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

#define MAXD 10
#define MAXN 33

using namespace std;

int dim;

struct box_t {
	int id;
	int x[MAXD];
	void ord(){
		sort( x, x+dim );
	}
	bool operator < ( const box_t &a ) const {
		for( int i = 0; i < dim; i++ )
			if( x[i] > a.x[i] ) return false;
		return true;
	}
	bool operator > ( const box_t &a ) const {
		for( int i = 0; i < dim; i++ )
			if( x[i] <= a.x[i] ) return false;
		return true;
	}
};	
	
box_t box[MAXN];
int parent[MAXN], maxProf[MAXN];
	
int main(){

	int n, i, j, maxP, u;
	ios::sync_with_stdio( false );
	
	while( cin >> n >> dim ){
		
		for( i = 0; i < n; i++ ){
			parent[i+1] = -1; maxProf[i+1] = 1;
			box[i].id = i+1;
			for( j = 0; j < dim; j++ )
				cin >> box[i].x[j];
			box[i].ord();
		}
		sort( box, box+n );
	
		maxP = 0;
		for( i = n-1; i >= 0; i-- ){
			if( maxProf[box[i].id] > maxP ) maxP = maxProf[box[i].id], u = box[i].id;
			for( j = i-1; j >= 0; j-- ){
				if( box[i] > box[j] && ( maxProf[box[j].id] < maxProf[box[i].id]+1 ) ){
					maxProf[box[j].id] = maxProf[box[i].id]+1;
					parent[box[j].id] = box[i].id;
				}
			}
		}
		
		cout << maxP << "\n" << u;
		u = parent[u];
		while( u != -1 ){
			cout << " " << u;
			u = parent[u];
		}
		cout << "\n";
	}
	
	return 0;
}
