/*
ID: knightp2
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ofstream fout("namenumdict.out");
string N;

char mp[][3] = { {'A','B','C'}, {'D','E','F'}, {'G','H','I'}, {'J','K','L'}, {'M','N','O'}, {'P','R','S'}, {'T','U','V'}, {'W','X','Y'} };

struct node_t{
	map< char, node_t > sons;
	bool isEnd;

	node_t(){ isEnd = false; }	
		
	map< char, node_t >::iterator beg(){ return sons.begin(); }
	map< char, node_t >::iterator end(){ return sons.end(); }
	
	bool has( char c ){ return (sons.find( c ) != sons.end());  }
};

bool print;
string word;

void solve( int i, node_t& node ){
	
	if( i == N.size() && node.isEnd ){ fout << word << "\n"; print = true; return; }
	
	int cur = N[i]-'2';
	for( int l = 0; l < 3; l++ ){
		if( node.has( mp[ cur ][l] ) ){
			word[i] = mp[ cur ][l];
			solve( i+1, node.sons[ mp[ cur ][l] ] );
		}
	}
	
}

int main() {
    ifstream fin("namenum.in");
	ifstream dictin("dict.txt");
	
	node_t trie;

	int i;
	while( dictin >> word ){
		i = 0;
		node_t* cur = &trie;
		while( cur->has( word[i] ) && i < word.size() ) cur = &cur->sons[ word[i++] ];
		
		while( i < word.size() ) { 
			cur->sons[ word[i] ] = node_t(); 
			cur = &cur->sons[ word[i++] ];
		}
		cur->isEnd = true;		
	}	
	
	fin >> N;
	word = N;
	
	print = false;
	solve( 0, trie );
	if( !print ) fout << "NONE\n";
    return 0;
}
