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

#define MAXL 27
#define MAXD 10001

int dp[MAXL][MAXL][MAXD];

int solve( int at, int L, int S ){
	if( L == 0 ) return S == 0;
	if( at > 26 || L > 26 ) return 0;
	int& r = dp[at][L][S];
	if( r == -1 ){
		r = 0;
		r += solve( at+1, L, S );
		r += solve( at+1, L-1, S-at );
	}
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	FILL( dp, -1 );
	
	int L, S; int tc = 1;
	cin >> L >> S;
	while( L+S ){
		cout << "Case " << tc++ << ": " << solve( 1, L, S ) << "\n";
		cin >> L >> S;
	}
	return 0;
}


































