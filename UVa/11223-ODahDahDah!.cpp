/*
 *  Problema:
 *  Tecnica Utilizada:  
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <map> 
#include <set> 
#include <list>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	map< string, char > code;
	code[".-"] = 'A';	code[".---"] =	'J';   code["..."]	= 'S';	code[".----"] = '1';	code[".-.-.-"] = '.';	code["---..."] = ':';
	code["-..."] = 'B';	code["-.-"] = 'K';	   code["-"] = 'T'; 	code["..---"] = '2';	code["--..--"] = ',';	code["-.-.-."] = ';';
	code["-.-."] = 'C';	code[".-.."] = 'L';	   code["..-"] = 'U';	code["...--"] = '3';	code["..--.."] = '?';	code["-...-"] =  '=';	
	code["-.."] = 'D';	code["--"] = 'M';	   code["...-"] = 'V';	code["....-"] = '4';	code[".----."] = '\'';	code[".-.-."] =  '+';	
	code["."] = 'E';	code["-."] = 'N';	   code[".--"] = 'W';	code["....."] = '5';	code["-.-.--"] = '!';	code["-....-"] = '-';
	code["..-."] = 'F';	code["---"] = 'O';	   code["-..-"] = 'X';	code["-...."] = '6';	code["-..-."] = '/';	code["..--.-"] = '_';	
	code["--."] = 'G';	code[".--."] = 'P';	   code["-.--"] = 'Y';	code["--..."] = '7';	code["-.--."] = '(';	code[".-..-."] = '"';	
	code["...."] = 'H';	code["--.-"] = 'Q';	   code["--.."] = 'Z';	code["---.."] = '8';	code["-.--.-"] = ')';	code[".--.-."] = '@';	
	code[".."] = 'I';	code[".-."] = 'R';	   code["-----"] = '0';	code["----."] = '9';	code[".-..."] = '&';	
	
	int t;
	cin >> t; cin.ignore();
	
	string message;
	FOR( tc, 1, t+1 ){
		getline( cin, message );
		cout << "Message #" << tc << "\n";
		
		int from = 0; int to = 0;
		while( from < SIZE(message) ){	
			
			while( to < SIZE(message) && message[to] != ' ' ) to++;
			cout << code[ message.substr( from, to-from ) ];
			from = to+1;
			if( from < SIZE(message) && message[from] == ' ' ){ cout << ' '; from++; }
			to = from+1;
		}
		cout << "\n";
		if( tc+1 <= t ) cout << "\n";
	}
	
	return 0;
}


































