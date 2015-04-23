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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string lower;
void low( string& s ){
	lower = "";
	REP( i, SIZE(s) ) if( s[i]>='a' && s[i]<='z') lower += s[i];
	else lower += (s[i]-'A'+'a');
	//cout << "low: " << lower << endl;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	map< string, int > occ;
	vector< string > words;
	string word;
	
	cin >> word;
	while( word[0] != '#' ){
	
		words.pb( word );
		
		low( word );
		
		sort( lower.begin(), lower.end() ); 
		occ[ lower ]++;
		
		cin >> word;
	}
	
	sort( words.begin(), words.end() );
	REP( i, SIZE(words) ){
		low( words[i] );
		sort( lower.begin(), lower.end() );
		if( occ[lower] == 1 ) cout << words[i] << "\n";
	}
	
	return 0;
}
