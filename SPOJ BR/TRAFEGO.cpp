/*
 *  Problema: Trafego
 *  Tecnica Utilizada:  BFS no Estado de Espacos
 *
 *		  Partindo do estado inicial e movimentando todas as pecas 
 *		possiveis, nos sentidos permitidos, e todas as quantidades
 *		de casas possiveis, geramos o estado de espacos que podem 
 *		ser alcancados com um movimento valido, seguindo essa ideia com
 *		os estados gerados, criamos todos os com 2, 3, .. , n movimentos validos.
 *		  Como nao repetimos os estados, e eles sao gerados sempre em
 *		ordem crescente de quantidade de movimentos usados, a primeira ocorrencia de
 *		um estado onde eh possivel tirar a peca branca garantidamente eh a que gasta
 *		o menor numero de passos, e portanto a nossa resposta.
 *      
 *  Dificuldade: Facil-Medio
 *	Complexidade:
 *				O( SCARY )
 *
 */

#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <cstring>

/* Tipo de pecas */
#define WT 0 // branca
#define V2 1 // vertical de 2 casas
#define V3 2 // vertical de 3 casas
#define H2 3 // horizontal de 2 casas
#define H3 4 // horizontal de 3 casas

using namespace std;

struct state{
	char grid[7][7];
	int steps;
	state(){
		memset( grid, 0, sizeof( grid ) );
		steps = 0;
	}
};

/* gera a string que representa o estado. */
string sstate( const state &s ){
	string ss = "";
	for( int i = 0; i < 6; i++ ) 
		for( int j = 0; j < 6; j++ )
			ss += ( s.grid[i][j] + '0' );
	return ss;
}

/* Para armazenar o tipo do bloco */
int blocktype[30];

int main(){
	
	int puzz, puzzle;
	int i, j, x, y, block, blocks, type, ans;
	string nstate;
	ios::sync_with_stdio( false );
	
	cin >> puzz;
	for( puzzle = 1; puzzle <= puzz; puzzle++ ){
		
		state ini, aux;
		map< string, bool > visited;
		
		cin >> x >> y;
		type = V2;
		block = 1;
		ini.grid[x][y] = 1;
		ini.grid[x][y+1] =  1;
		blocktype[1] = WT;
		
		/* Le as posicoes dos blocos e gera o estado inicial */
		while( type <= H3 ){
			cin >> blocks;
			
			while( blocks-- ){
				block++;
				cin >> x >> y;
				switch( type ){
					case V3: ini.grid[x+2][y] = block;
					case V2: ini.grid[x+1][y] = ini.grid[x][y] = block;
							 break;
					case H3: ini.grid[x][y+2] = block;
					case H2: ini.grid[x][y+1] = ini.grid[x][y] = block;
							 break;
				}
				blocktype[block] = type;
			}
			type++;
		}
		
		queue< state > Q;
		Q.push( ini );
		visited[sstate( ini )] = true;
		blocks = block+1;
		bool used[blocks];
		
		while( true ){
			
			ini = Q.front(); Q.pop();
			for( block = 0; block < blocks; block++ ) used[block] = false;
			used[0] = true;
			
			/* Percorre todo o tabuleiro, procurando pecas que ainda nao foram movidas
			    e podem ser movimentadas.. 
			   Como o tabuleiro eh varrido de cima para baixo e da esquerda para a direita
			    e ao movimentar uma peca ela e marcada como usada, quando uma peca que pode
			   ser movida estamos no indice do canto superior/esquerdo */
			for( i = 0; i < 6; i++ ){
				for( j = 0; j < 6; j++ ){
				
					block = ini.grid[i][j];
					if( !used[block] ){
						
						aux = ini;
						aux.steps++;
						
						used[block] = true;
						
						switch( blocktype[ block ] ){
								
							case V2:
								x = i; y = j;
								while( (x-1) >= 0 && !ini.grid[x-1][y] ){
									aux.grid[x-1][y] = block;
									aux.grid[x+1][y] = 0;
									x--;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
								
								aux = ini; aux.steps++;
								x = i;
								while( (x+2) < 6 && !ini.grid[x+2][y] ){
									aux.grid[x][y] = 0;
									aux.grid[x+2][y] = block;
									x++;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
								break;
							case V3:
								x = i; y = j;
								while( (x-1) >= 0 && !ini.grid[x-1][y] ){
									aux.grid[x-1][y] = block;
									aux.grid[x+2][y] = 0;
									x--;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
								
								aux = ini; aux.steps++;
								x = i;
								while( (x+3) < 6 && !ini.grid[x+3][y] ){
									aux.grid[x][y] = 0;
									aux.grid[x+3][y] = block;
									x++;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
								break;
								
							case H2:
								x = i; y = j;
								while( (y-1) >= 0 && !ini.grid[x][y-1] ){
									aux.grid[x][y-1] = block;
									aux.grid[x][y+1] = 0;
									y--;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
								
								aux = ini; aux.steps++;
								y = j;
								while( (y+2) < 6 && !ini.grid[x][y+2] ){
									aux.grid[x][y] = 0;
									aux.grid[x][y+2] = block;
									y++;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
								break;
							case H3:
								x = i; y = j;
								while( (y-1) >= 0 && !ini.grid[x][y-1] ){
									aux.grid[x][y-1] = block;
									aux.grid[x][y+2] = 0;
									y--;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
								
								aux = ini; aux.steps++;
								y = j;
								while( (y+3) < 6 && !ini.grid[x][y+3] ){
									aux.grid[x][y] = 0;
									aux.grid[x][y+3] = block;
									y++;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
								break;
							case WT:
								x = i; y = j;
								while( (y-1) >= 0 && !ini.grid[x][y-1] ){
									
									aux.grid[x][y-1] = block;
									aux.grid[x][y+1] = 0;
									y--;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
								y = j;
								aux = ini; aux.steps++;
								while( (y+2) <= 6 ){
									if( (y+2) < 6 && ini.grid[x][y+2] ) break;
									if( y+2 >= 6 ) { ans = aux.steps; goto hell; }
									aux.grid[x][y] = 0;
									aux.grid[x][y+2] = block;
									y++;
									nstate = sstate( aux );
									if( visited.find( nstate ) == visited.end() ){
										visited[nstate] = true;
										Q.push( aux );
									}
								}
									
								break;
						}
					
					}
					
				}
			}
			
		
		}
	hell:
		cout << "The minimal number of moves to solve puzzle " << puzzle << " is " << ans << ".\n";		
	}
	
	return 0;
}

