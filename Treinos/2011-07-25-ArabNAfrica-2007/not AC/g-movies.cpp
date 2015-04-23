#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector< vector< int > > gr;
vector< int > parent;

struct comp {
	bool operator()( const int& a, const int& b ) const {
		int sa = gr[a].size();
		int sb = gr[b].size();
		if( sb != sa ) return sa > sb;
		return a < b;
	}
};

int main(){

	ios::sync_with_stdio( false );
	string line, pa, ss;

	getline( cin, line );
	while( line != "0 0" ){

		int N, F;
		N = F = 0;
		int i = 0;
		while( line[i] != ' ' ) N = 10*N + (line[i++]-'0');	
		while( line[i] == ' ' ) i++;
		while( (i < int(line.size())) && (line[i] != ' ') ) F = 10*F + (line[i++]-'0');
		
		getline( cin, line );
		map< string, int > id;
		int cid = 0;
		gr.clear();
		
		while( 'a' <= line[0] && line[0] <= 'z' ){
			istringstream in( line );
			in >> pa;
			if( id.find( pa ) == id.end() ){ id[ pa ] = cid++; gr.push_back( vector<int>() ); parent.push_back( -1 ); }
			int par = id[ pa ];
			while( in >> ss ){
				if( id.find( ss ) == id.end() ){ id[ ss ] = cid++; gr.push_back( vector<int>() ); parent.push_back( -1 ); }
				int son = id[ ss ];
				gr[ par ].push_back( son );
				parent[ son ] = par;
			}
			getline( cin, line );		
		}
		
		// have fun!

	}

	return 0;
}

