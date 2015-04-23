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

struct crew_t{
	string name, ttl;
	int id;
	crew_t(){}
	crew_t( string nm, string tt, int iid ) : name( nm ), ttl( tt ), id( iid ) {}
	bool operator < ( const crew_t &a ) const {
		if( ttl != a.ttl){
			
			if( ttl == "rat" ) return true;
			if( a.ttl == "rat" ) return false;
			
			if( ttl == "woman" ){
				if( a.ttl != "child" ) return true;
				return id < a.id;
			}
			if( a.ttl == "woman" ){
				if( ttl != "child" ) return false;
				return id < a.id;
			}
			
			if( ttl == "child" ){
				if( a.ttl != "woman" ) return true;
				return id < a.id;
			}
			if( a.ttl == "child" ){
				if( ttl != "woman" ) return false;
				return id < a.id;
			}
			
			if( ttl == "man" ) return true;
			if( a.ttl == "man" ) return false;
			
		}
		return id < a.id;
	}
};

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int n, id;
	string name, title;
	
	cin >> n;
	id = 0;
	list< crew_t > ppl;
	
	while( n-- ){
		cin >> name >> title;
		ppl.pb( crew_t( name, title, id ) );
		id++;
	}
	ppl.sort();
	
	FORIT( it, ppl ) cout << it->name << endl;
	
	return 0;
}
