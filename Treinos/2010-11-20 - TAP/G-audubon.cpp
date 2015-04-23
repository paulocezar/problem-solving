#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <utility>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 110

using namespace std;

struct edge{
	string first;
	int second;
	int total;
	edge(){}
	edge( string a, int b, int c ) : first(a), second(b), total(c){}
};

list< edge > graph[MAXN];
int xcount[MAXN];
string sol;

void make_sol( int n, int node = 0 ){
	
	/*cout << "lookin for " << n << " at " << node << endl; */
	if( node == 100 ) return;
	if( sol != "" ) sol += "-";
	
	list< edge >::iterator w = graph[node].begin();
	while( w->total < n ){
		w++;
	}
	sol += w->first;
	int nxt = w->second;
	if( w == graph[node].begin() ) make_sol( n, nxt );
	else {
		w--;
		make_sol( n - w->total, nxt );
	}
	
}

int main(){

	ios::sync_with_stdio( false );
	string line, token, word, word2;
	int node, n, i;	
	list< edge >::iterator w;
	bool flag = false;
	
	while( getline( cin, line ) && line[0] && line[0] != '\n' ){
		
		if( flag ) cout << "\n";
		else flag = true;
		
		size_t pos;
		memset( xcount, 0, sizeof( xcount ) );
		do{
			
			pos = line.find(':');
			if( pos == string::npos ) break;
			
			if( pos == line.size()-1 ) { 
				node = (line[0]-'0')*10 + (line[1]-'0'); 
				graph[node].clear(); 
				continue;
			}
			
			istringstream in( line );
		
			while( in >> token ){
				istringstream aux( token );
				getline( aux, word, ':' );
				getline( aux, word2, ':' );
				if( word2 == "$" ) n = 100;
				else{
					istringstream rInt( word2 );
					rInt >> n;
				}
				graph[node].push_back( edge( word, n, 0 ) );

			}
		
		} while( getline( cin, line )  && line[0] && line[0] != '\n'  );
		
		if( !line[0] || line[0] == '\n' ) { cout << "\n"; continue; }
		
		xcount[100] = 1;
		for( i = node; i >= 0; i-- ){
			for( w = graph[i].begin(); w != graph[i].end(); w++ ){
				w->total = xcount[i] + xcount[w->second];
				xcount[i] += xcount[w->second];
			}
		}
		
	/*	for( i = 0; i <= node; i++ ){
			cout << i << " - " << xcount[i] << endl;
			for( w = graph[i].begin(); w != graph[i].end(); w++ ){
				cout << " " << w->first << " " << w->total << endl;
			}
			cout << endl;
		}
		*/
		
		
		do{
			istringstream rInt( line );
			rInt >> n;
			
			sol = ""; make_sol( n );
			cout << sol << "\n";
			
		} while( getline( cin, line ) && line[0] && line[0] != '\n' );
		
	}
	return 0;
}
