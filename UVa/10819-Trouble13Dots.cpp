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

#define MAXM 10001
#define MAXN 101

int p[MAXN], f[MAXN];

int M, N, dp[MAXN][MAXM][2];

int solve( int at, int waste, int used ){
	if( waste > M ) return -INF;
	if( at == N || waste == M ) return 0;
	
	int& r = dp[at][waste][used];
	if( r == -1 ){
		r = solve(at+1, waste, used);
		r = MAX( r, f[at] + solve( at+1, waste+p[at], used ) );
		if( !used && waste+p[at] > 2000 ) r = MAX( r, f[at]+solve( at+1, waste+p[at]-200, 1 ) );
	}
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	while( cin >> M >> N ){
		
		REP( i, N ) cin >> p[i] >> f[i];
		REP( i, N+1 ) REP( j, M+1 ) dp[i][j][0] = dp[i][j][1] = -1;
		cout << solve( 0, 0, 0 ) << "\n";
		
	}
	
	return 0;
}


































