#include <iostream>
#include <set>
#include <string>
#include <list>
#include <cstring>

using namespace std;

struct state {
	
	char grid[10][10];
	void showMe(){
		for( int i = 0; i < 8; i++ ) {
			for( int j = 0; j < 8; j++ ){
				cout << grid[i][j];	
			} cout << endl;
		} cout << endl;
	}
	
};

string sstate( const state &s ){
	string ss = "";
	for( int i = 0; i < 8; i++ ) 
		for( int j = 0; j < 8; j++ )
			ss += ( s.grid[i][j] );
	return ss;
}


int main(){
	
	int t, tst, i, j, npos;
	unsigned long long statics;
	string nstate;
 	char at; 
	bool isNew;
	ios::sync_with_stdio( false );
	
	cin >> t;
	
	for( tst = 1; tst <= t; tst++ ){
		
		state ini, aux;
		set< string > visited;
		statics = 0ULL;
		
		for( i = 0; i < 8; i++ )
			cin >> ini.grid[i];
		
		list< state > Q;
		Q.push_back( ini );
		
		while( !Q.empty() ) {
			
			ini = Q.front(); Q.pop_front();
				
			/* Gravity UP */
			aux = ini;
			isNew = false;
			for( i = 1; i < 7; i++ ){
				for( j = 0; j < 8; j++ ){
					if( 'A' <= aux.grid[i][j] && aux.grid[i][j] <= 'D' ){
						npos = i-1; at = aux.grid[i][j];
						while( npos >= 0 && (aux.grid[npos][j]== aux.grid[npos][j+1]) && (aux.grid[npos][j]=='.') ){
							aux.grid[npos][j] = aux.grid[npos][j+1] = at;
							aux.grid[npos+2][j] = aux.grid[npos+2][j+1] = '.';
							npos--;
							isNew = true;
						}
						j++;
					}
				}
			}
			if( isNew ){
				nstate = sstate( aux );
				if( visited.find( nstate ) == visited.end() ){
					visited.insert( nstate );
					Q.push_back( aux );
					statics++;
				}
			}
			/* Gravity DOWN */
			aux = ini;
			isNew = false;
			for( i = 6; i > 0; i-- ){
				for( j = 0; j < 8; j++ ){
					if( 'A' <= aux.grid[i][j] && aux.grid[i][j] <= 'D' ){
						npos = i+1; at = aux.grid[i][j];
						while( npos < 8 && (aux.grid[npos][j]== aux.grid[npos][j+1]) && (aux.grid[npos][j]=='.') ){
							aux.grid[npos][j] = aux.grid[npos][j+1] = at;
							aux.grid[npos-2][j] = aux.grid[npos-2][j+1] = '.';
							npos++;
							isNew = true;
						}
						j++;
					}
				}
			}
			if( isNew ){
				nstate = sstate( aux );
				if( visited.find( nstate ) == visited.end() ){
					visited.insert( nstate );
					Q.push_back( aux );
					statics++;
				}
			}
			
			/* Gravity LEFT */
			aux = ini;
			isNew = false;
			for( j = 1; j < 7; j++ ){
				for( i = 0; i < 8; i++ ){
					if( 'A' <= aux.grid[i][j] && aux.grid[i][j] <= 'D' ){
						npos = j-1; at = aux.grid[i][j];
						while( npos >= 0 && (aux.grid[i][npos]==aux.grid[i+1][npos]) && (aux.grid[i][npos]=='.') ){
							aux.grid[i][npos] = aux.grid[i+1][npos] = at;
							aux.grid[i][npos+2] = aux.grid[i+1][npos+2] = '.';
							npos--;
							isNew = true;
						}
						i++;
					}
				}
			}
			if( isNew ){
				nstate = sstate( aux );
				if( visited.find( nstate ) == visited.end() ){
					visited.insert( nstate );
					Q.push_back( aux );
					statics++;
				}
			}
			
			/* Gravity RIGHT */
			aux = ini;
			isNew = false;
			for( j = 6; j > 0; j-- ){
				for( i = 0; i < 8; i++ ){
					if( 'A' <= aux.grid[i][j] && aux.grid[i][j] <= 'D' ){
						npos = j+1; at = aux.grid[i][j];
						while( npos < 8 && (aux.grid[i][npos] == aux.grid[i+1][npos]) && (aux.grid[i][npos] =='.') ){
							aux.grid[i][npos] = aux.grid[i+1][npos] = at;
							aux.grid[i][npos-2] = aux.grid[i+1][npos-2] = '.';
							npos++;
							isNew = true;
						}
						i++;
					}
				}
			}
			if( isNew ){
				nstate = sstate( aux );
				if( visited.find( nstate ) == visited.end() ){
					visited.insert( nstate );
					Q.push_back( aux );
					statics++;
				}
			}
			
		} 
		
		cout << "Case " << tst << ": " << statics << "\n";
		
	}
	
	return 0;
}

