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

#define MAXCAR 10000
int N, len[MAXCAR];

struct state {
	int x, y, z;
	state( int xx = 0, int yy = 0, int zz = 0 ) : x(xx), y(yy), z(zz) {}
	bool operator <( const state& a ) const {
		if( x != a.x ) return x < a.x;
		if( y != a.y ) return y < a.y;
		return z < a.z;
	}
};

string ans, aux;
set< state > seen;

void play( int at, int lft, int rgt ){
	if( !seen.insert( state(at, lft, rgt) ).second ) return;
	if( at != N && lft-len[at] >= 0 ){ aux[at] = '0'; play( at+1, lft-len[at], rgt ); }
	if( at != N && rgt-len[at] >= 0 ){ aux[at] = '1'; play( at+1, lft, rgt-len[at] ); }
	if( at > SIZE(ans) ){ ans = "";  REP( i, at ) ans += aux[i]; }
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t, length;
	cin >> t;
	while( t-- ){
		
		cin >> length; length *= 100;
	
		N = 0;
		cin >> len[N];
		
		ans = ""; aux = "";
		while( len[N] ){ N++; cin >> len[N]; aux += "-"; }
		
		seen.clear();
		play( 0, length, length );
		
		cout << SIZE(ans) << "\n";
		REP( i, SIZE(ans) ){
			if( ans[i] == '0' ) cout << "port\n";
			else cout << "starboard\n";
		}
		if( t ) cout << "\n";
	}
	
	return 0;
}


































