/*
 *  Problema: Codigos Ambiguos
 *  Tecnica Utilizada:  Sardinas-Patterson + Dijkstra
 *	
 *		  Usando a idéia do livro 'Jewels of stringology' construimos um grafo 
 *		onde os todos sufixos das palavras do codigo sao os vertices e existem arestas 
 *		de u para v se v eh sufixo de u ou uv eh uma palavra do codigo. Nesse grafo,
 *		um caminho de um vertice inicial ( sufixos das palavras do codigo tomadas 2 a 2 ),
 *		para o vertice vazio indica que o codigo e ambiguo.
 *		  No o algoritmo S-P ( Sardinas-Patterson ) os sufixos sao gerados dinamicamente,
 *		em conjuntos, ate que um conjunto se repita ou seja vazio, indicando um ciclo
 *		( e a nao ambiguidade do codigo ) ou que a palavra vazia seja encontrada indicando
 *		que o codigo e ambiguo.
 *		  Se usarmos uma ideia parecida com a do algoritmo S-P para gerar os sufixos,
 *		iremos gerar apenas os sufixos que importam, simplificando a criacao do grafo.
 *		Considerando que o peso de uma aresta de u para v eh o tamanho de u ao executar
 *		o algoritmo de dijkstra partindo do conjunto de sufixos resultantes da analise
 *		das palavras do codigo tomadas 2 a 2; chegar no vertice que representa a
 *		palavra vazia indica que o codigo e ambiguo e a distancia percorrida e o comprimento
 *		da menor palavra com duas possiveis codificacoes, e a nao existencia de um caminho
 *		indica que o codigo nao eh ambiguo.
 *      
 *  Dificuldade: Dificil
 *	Complexidade:
 *		O( [ m + n^2 ] log n^2 ) 
 *	 Onde n eh o somatorio dos comprimentos das palavras do codigo,
 *		e m o total de palavras no codigo.
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>

#define MAXN 110

using namespace std;

typedef pair< int, string > prefix;

/* Verifica se a e prefixo de w, e coloca o sufixo resultante em c */
bool ispref( const string &a, const string &b, string &c ){
	
	int asz = a.size(), bsz = b.size();
	if( asz > bsz ) return false;
	for( int i = 0; i < asz; i++ )
		if( a[i] != b[i] ) return false;
	c = "";
	for( int i = asz; i < bsz; i++ ) c += b[i];
	return true;

}

string code[MAXN];

int main(){

	int n, i, j;
	int ss1, ss2, cost;
	string s1, s2, word;
	
	ios::sync_with_stdio( false );

	while( true ){

hell:
		cin >> n;	
		if( n == 0 ) return 0;

		map< string, int > D;
		priority_queue< prefix > Q;
		
		for( i = 0; i < n; i++ ) cin >> code[i];

		/* Analisa todas as palavras do codigo duas a duas, para gerar
			o conjunto de vertices iniciais */
		for( i = 0; i < n; i++ ){
			for( j = i+1; j < n; j++ ){
				
				s1 = code[i], s2 = code[j];
				ss1 = s1.size(), ss2 = s2.size();

				if( ss1 < ss2 ){
					
					if( ispref( s1, s2, word ) ){
						
						if( D.find( word ) == D.end() || ss1 < D[word] ){
							D[word] = ss1;
							Q.push( prefix( -ss1, word ) );
						}
					}
					
				}
				else if( ispref( s2, s1, word ) ){
					
					if( D.find( word ) == D.end() || ss2 < D[word] ){
							D[word] = ss2;
							Q.push( prefix( -ss2, word ) );
					}
				
				}
			
			}
		}
		
		/* Executa o dijkstra pra procurar a menor palavra ambigua, ou
			verificar que o codigo nao eh ambiguo. */
		while( !Q.empty() ){
			
			s1 = Q.top().second;
			cost = -Q.top().first; Q.pop();
			ss1 = s1.size();
			
			if( cost > D[s1] ) continue;
			if( s1.size() )
			{

				for( i = 0; i < n; i++ ){
					
					s2 = code[i];
					ss2 = s2.size();
					
					if( ss1 < ss2 ){
						
						if( ispref( s1, s2, word ) ){
							
							if( D.find( word ) == D.end() || (cost+ss1) < D[word] ){
								D[word] = cost+ss1;
								Q.push( prefix( -(cost+ss1), word ) );
							}
						}
						
					}
					else if( ispref( s2, s1, word ) ){
						
						if( D.find( word ) == D.end() || (cost+ss2) < D[word] ){
							D[word] = cost+ss2;
							Q.push( prefix( -(cost+ss2), word ) );
						}
						
					}
				}
				
			} else {
				cout << D[s1] << endl;
				goto hell;
			}

		}
		
		cout << "-1\n";
		
	}

	return 0;
}

