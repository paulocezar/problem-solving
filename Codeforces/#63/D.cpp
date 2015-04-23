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

map< int, map< int, bool > > mem;
int N, D;
int ds[33][2];

bool play( int x, int y ){
	
	if( SQR(x) + SQR(y) > D ) return true;
	if( mem[x].find( y ) != mem[x].end() ) return mem[x][y];
	
	REP( i, N ) if( !play( x+ds[i][0], y+ds[i][1] ) ) return (mem[x][y] = true);
	return (mem[x][y] = false);
	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	int x, y;
	cin >> x >> y >> N >> D;
	D = SQR( D );
	
	REP( i, N ) cin >> ds[i][0] >> ds[i][1];
	
	if( play(x, y) ) cout << "Anton\n";
	else cout << "Dasha\n";
	
	return 0;
}
