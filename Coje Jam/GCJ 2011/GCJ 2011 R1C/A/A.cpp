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

#define MAXR 55

int R, C;
string grid[MAXR];

bool solve(){
	
	REP( i, R ){
		REP( j, C ){
			if( grid[i][j] == '#' ){
				if( i+1 >= R || j+1 >= C || grid[i+1][j] != '#' || grid[i][j+1] != '#' || grid[i+1][j+1] != '#'  ) return false;
				grid[i][j] = '/'; grid[i][j+1] = '\\';
				grid[i+1][j] = '\\'; grid[i+1][j+1] = '/';
			}
		}
	}
	
	return true;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T;
	cin >> T;
	FOR( tc, 1, T+1 ){
		
		cin >> R >> C;
		REP( i, R ) cin >> grid[i];
		
		cout << "Case #" << tc << ":\n";
		if( solve() ){
			REP( i, R ) cout << grid[i] << "\n";
		} else cout << "Impossible\n";
		
	}
	
	return 0;
}


































