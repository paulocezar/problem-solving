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
#include <utility>

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

int N;
char ans[4][101];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );

	cin >> N;
	
	if( N&1 ){
		
		int color = 0;
		
		REP( i, N/2 ){
			ans[0][2*i] = ans[0][2*i+1] = color;
			color++; if( color == 26 ) color = 0;
		}
		
		if( N > 1 ) while( color == ans[0][N-2] ){ color++; if(color==26) color = 0; }
		ans[0][N-1] = ans[1][N-1] = color;
		color++; if( color == 26 ) color = 0;
		
		RREP( i, N/2 ){
			while( color == ans[0][2*i] || color == ans[0][2*i+1] ){ color++; if( color == 26 ) color = 0; }
			ans[1][2*i] = ans[1][2*i+1] = color;
			color++; if(color==26) color = 0;
		}
		
		while( color == ans[1][0] ){ color++; if(color==26) color = 0; }
		
		ans[2][0] = ans[3][0] = color;
		color++; if( color == 26 ) color = 0;
		
		REP( i, N/2 ){
			while( color == ans[1][2*i+1] || color == ans[1][2*i+2] ){ color++; if( color == 26 ) color = 0; }
			ans[2][2*i+1] = ans[2][2*i+2] = color;
			color++; if(color==26) color = 0;
		}

		REP( i, N/2 ){
			while( color == ans[2][2*i+1] || color == ans[2][2*i+2] || color == ans[3][2*i] ){ color++; if( color == 26 ) color = 0; }
			ans[3][2*i+1] = ans[3][2*i+2] = color;
			color++; if( color == 26 ) color = 0;
		}

		REP( i, 4 ) { REP( j, N ) cout << char(ans[i][j]+'a'); cout << "\n"; }
		
		
	} else {
		
		int color = 0;
		
		REP( i, N/2 ){
			ans[0][2*i] = ans[0][2*i+1] = color;
			color++; if( color == 26 ) color = 0;
		}
		
		while( color == ans[0][0] ){ color++; if(color==26) color = 0; }
		ans[1][0] = ans[2][0] = color;
		color++; if( color == 26 ) color = 0;
		
		REP( i, N/2-1 ){
			while( color == ans[0][2*i+1] || color == ans[0][2*i+2] ){ color++; if( color == 26 ) color = 0; }
			ans[1][2*i+1] = ans[1][2*i+2] = color;
			color++; if(color==26) color=0;
		}
		REP( i, N/2-1 ){
			while( color == ans[1][2*i+1] || color == ans[1][2*i+2] ){ color++; if( color == 26 ) color = 0; }
			ans[2][2*i+1] = ans[2][2*i+2] = color;
			color++; if(color==26)color=0;
		}
		
		while( color == ans[1][N-2] || color == ans[2][N-2] || color == ans[0][N-1] ){ color++; if( color == 26 ) color = 0;}
		ans[1][N-1] = ans[2][N-1] = color;
		color++; if(color==26)color=0;
		
		REP( i, N/2 ){
			while( color == ans[2][2*i] || color == ans[2][2*i+1] ){ color++; if( color == 26 ) color = 0; }
			ans[3][2*i] = ans[3][2*i+1] = color;
			color++; if( color == 26 ) color = 0;
		}

		REP( i, 4 ) { REP( j, N ) cout << char(ans[i][j]+'a'); cout << "\n"; }
		
	}
	
 	return 0;
}






















