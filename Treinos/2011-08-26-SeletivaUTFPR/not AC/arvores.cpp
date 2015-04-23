#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;

string gr1[27], gr2[27], g1, g2;

set< char > gg1, gg2;

int pos, sz;
void build1( int u ){
	gg1.insert( char(u+'A') );
	bool fl = false;
	if( g1[pos] == '(' ){
		pos++;
		gr1[g1[pos]-'A'] += char(u+'A');
		gr1[u] += g1[pos];
		pos++;
		build1( g1[pos-1]-'A' );
		fl = true;
	}
		
	while( fl && g1[pos] == ',' ){
		pos++;
		gr1[g1[pos]-'A'] += char(u+'A');
		gr1[u] += g1[pos];
		pos++;
		build1( g1[pos-1]-'A' );
		
	}
	if( fl ) pos++;
	return;
}

void build2( int u ){
	gg2.insert( char(u+'A') );
	bool fl = false;
	if( g2[pos] == '(' ){
		pos++;
		gr2[g2[pos]-'A'] += char(u+'A');
		gr2[u] += g2[pos];
		pos++;
		build2( g2[pos-1]-'A' );
		fl = true;
	}
		
	while( fl && g2[pos] == ',' ){
		pos++;
		gr2[g2[pos]-'A'] += char(u+'A');
		gr2[u] += g2[pos];
		pos++;
		build2( g2[pos-1]-'A' );	
	}
	if( fl ) pos++;
	return;
}

int main(){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		for( int i = 0; i < 27; i++ ){ gr1[i] = ""; gr2[i] = ""; }
		cin >> g1;
		cin >> g2;
		
		gg1.clear(); gg2.clear();
		
		pos = 1;
		build1( g1[0]-'A' );
		
		pos = 1;
		build2( g2[0]-'A' );
		
	
		bool eq = false;
		if( gg1 == gg2 ){
			
			for( int i = 0; i < 27; i++ ){
				
				if( gr1[i].size() != gr2[i].size() ) goto hell;
				
				for( int j = 0, sz = int(gr1[i].size()); j < sz; j++ ){
					bool flg = true;
					for( int k = 0; k < sz; k++ )
						if( gr1[i][(j+k)%sz] != gr2[i][k] ){
							flg =false;
							break;
						}
					if( flg ) goto nxt;
				}
				break;
				nxt:
				i = i;
			}
			eq = true;
			
		}
	hell:	
		if( eq ) cout << "iguais\n";
		else cout << "diferentes\n";
		
	}
	
	return 0;
}
