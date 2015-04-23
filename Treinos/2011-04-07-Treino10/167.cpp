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

int sol[96][8];
int ln[8];
int cur_sol;

void bt( int col, int used ){
	
	if( col == 8 ){
		REP( i, 8 ) sol[cur_sol][i] = ln[i];
		cur_sol++;
		return;
	}
	
	
	REP( line, 8 )if( !(used&(1<<line)) ){
		
		bool ok = true;
		REP( j, col ) if( ABS(line-ln[j]) == ABS(col-j) ){ ok = false; break; }
		
		ln[col] = line;
		if( ok ) bt( col+1, used | (1<<line) );
	}
	
}


int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	cur_sol = 0;
	bt( 0, 0 );
	
	
	int t;
	int board[8][8];
	
	cin >> t;
	while( t-- ){
		
		REP( i, 8 ) REP( j, 8 ) cin >> board[i][j];
		
		int max = 0;
		REP( i, cur_sol ){
			
			int cur = 0;
			REP( j, 8 ) cur += board[ sol[i][j] ][j];
			max = MAX( max, cur );
		}
		
		cout << setw(5) << max << "\n";
		
	}
	
	return 0;
}
