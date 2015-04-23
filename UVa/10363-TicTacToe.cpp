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

string grid[3];
int has( char c ){
	REP( i, 3 ) if( grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] == c ) return 1;
	REP( i, 3 ) if( grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] == c ) return 1;
	if( grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] == c ) return 1;
	if( grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] == c ) return 1;
	return 0;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T;
	cin >> T;
	while( T-- ){
		
		REP( i, 3 ) cin >> grid[i];	
		
		int x, o;
		x = o = 0;
		REP( i, 3 ) REP( j, 3 )
			if( grid[i][j] == 'X' ) x++;
			else if( grid[i][j] == 'O' ) o++;
		
		if( o > x ) cout << "no\n";
		else if( x == o+1 && !has('O') ) cout << "yes\n";
		else if( x == o && !has('X') ) cout << "yes\n";
		else cout << "no\n";
		
	}
	
	return 0;
}
