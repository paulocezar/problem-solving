/*
 *  Problema: Et Phone Home ( Spoj BR )
 *  Tecnica Utilizada:  PD ( CYK Algorithm )
 *	
 *		 O problema consiste em verificar se uma palavra pode ser formada
 *		a usando uma determinada gramatica.
 *		 Como a gramática esta na CFN ( Chomsky Normal Form ) e possivel
 *		obter um algoritmo eficiente de programacao dinamica que resolve o problema.
 *		Podemos ter uma matriz dp[MAXN][MAXN][MAXR] ( MAXN - tamanho da maior palavra, MAXR - numero de regras )
 *		onde dp[i][j][k] indica que a substring iniciada no i-esimo caracter que termina no j-esimo caracter 
 *		pode ser gerada usando a k-esima regra.
 *		 Para preencher a matriz, marcamos dp[i][i][k] como true se a k-esima regra é da forma V_k -> s[i];
 *		e a partir disso vamos percorrendo as substrings de tamanho 2, 3, ..., n e verificamos se para a 
 *		k-esima regra, da forma V_k -> V_aV_b para alguma subdivisao da substring em questao dp[i][x][a] e dp[x+1][j][b] 
 *		sao verdadeira, o que implica em dp[i][j][k] = true.
 *
 *  Dificuldade: Dificil
 *	Complexidade: 
 *				O( R * N^3 )
 *		R - quantidade de regras, N - tamanho da string
 */

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <cstring>
#include <list>

#define MAXN 60
#define MAXR 30

using namespace std;

struct der{ 
	int x, y;
	der(){} 
	der( int a, int b ) : x(a), y(b){}  
};

bool M[MAXN][MAXN][MAXR];
bool term[256][MAXR];
int R[256];

list< der > prod[MAXR];

int main(){
	
	int i, j, l, k, r, instance = 1;
	char INI;
	string T, V, word;
	string x, to, y;
	list< der >::iterator p;
	ios::sync_with_stdio( false );
	
	while( cin >> INI ){
	
		cin >> V;	
		cin >> T;
		for( i = 0; V[i]; i++ ){
			R[V[i]] = i;
			prod[i].clear();
			for( j = 0; j < 256; j++ ) term[j][i] = false;
		}
			
		cin >> x >> to >> y;
		while( x[0] != '#' ){
		
			if( y[1] ){
				prod[R[x[0]]].push_back( der( R[y[0]], R[y[1]] ) ); 
			} else {
				term[y[0]][R[x[0]]] = true;
			}
			
			cin >> x >> to >> y;
		}
		
		cout << "Instancia " << instance++ << "\n";
		cin >> word;
		while( word[0] != '#' ){
			
			memset( M, false, sizeof( M ) );
			
			for( i = 0; word[i]; i++ )
				for( r = 0; V[r]; r++ )
					M[i][i][r] = term[word[i]][r];
			
			int sz = word.size();
			for( l = 2; l <= sz; l++ ){
				int li = sz-l;				
				for( i = 0; i <= li; i++ ){
					 j = i + l - 1;
					
					for( r = 0; V[r]; r++ ){
						bool need = true;
						for( p = prod[r].begin(); need && p != prod[r].end(); p++ ){
					
							for( k = i; k < j; k++ ){
								if( M[i][k][p->x] && M[k+1][j][p->y] ){
									M[i][j][r] = true;
									need = false;
									break;
								}
							}
							
						}
					}
					
				}
			}
			
			if( M[0][sz-1][R[INI]] ) cout << word << " e uma palavra valida\n";
			else cout << word << " nao e uma palavra valida\n";
			cin >> word;
		}
		cout << "\n";
	}
	
	return 0;
}
