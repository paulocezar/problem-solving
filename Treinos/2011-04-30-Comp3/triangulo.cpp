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

int64 C3( int64 n ){
	if( n < 3 ) return 0LL;
	return ( n*(n-1)*(n-2) )/6LL;
}

int64 C2( int64 n ){
	if( n < 2 ) return 0LL;
	return ( n*(n-1) )/2LL;
}

int prt[][2] = { {0,0}, {0,1}, {1,0}, {1,1} };

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T;
	cin >> T;
	while( T-- ){
		
		int n, x, y;
		cin >> n;
		int64 qtde[2][2];
		FILL( qtde, 0 );
		
		REP( i, n ){
			cin >> x >> y;
			qtde[ ABS(x)&1 ][ ABS(y)&1 ]++;
		}
		
		int64 ans = 0LL;
		REP( i, 4 )
			FOR( j, i, 4 )
				FOR( k, j, 4 )
				if((
					prt[i][0]*prt[j][1] + 
					prt[j][0]*prt[k][1] + 
					prt[k][0]*prt[i][1] -
					prt[k][0]*prt[j][1] -
					prt[i][0]*prt[k][1] -
					prt[j][0]*prt[i][1]) % 2 == 0
				){
						
					if( i == j && j == k ) ans += C3( qtde[prt[i][0]][prt[i][1]] );
					else if( i == j ) ans += C2( qtde[prt[i][0]][prt[i][1]] )*qtde[prt[k][0]][prt[k][1]];
					else if( i == k ) ans += C2( qtde[prt[i][0]][prt[i][1]] )*qtde[prt[j][0]][prt[j][1]];
					else if( j == k ) ans += C2( qtde[prt[j][0]][prt[j][1]] )*qtde[prt[i][0]][prt[i][1]];
					else ans += qtde[prt[i][0]][prt[i][1]]*qtde[prt[j][0]][prt[j][1]]*qtde[prt[k][0]][prt[k][1]];
											
				}
		
		cout << ans << "\n\n";
		
	}
	
	return 0;
}
