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

#define MAXN 11
int cost[MAXN][MAXN];

#define ACT(m,b) (m & (1<<b))
#define ON(m,b) (m |= (1<<b))
#define OFF(m,b) (m ^= (1<<b))

int dp[MAXN][1<<11];
int N;

int solve( int at, int mask ){
	
	if( mask == 0 ) return cost[at][0];
	int&r = dp[at][mask];
	
	if( r == -1 ){
		r = INF;
		int ans = INF;
		REP( i, N ) if( ACT(mask,i) ){
			ans = MIN( ans, cost[at][i] + solve( i, mask ^ (1<<i) ) );
		}
		r = ans;
	}
	
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	cin >> N;
	while( N ){
		N++;
		
		FILL( dp, -1 );
		REP( i, N ) REP( j, N ) cin >> cost[i][j];
		
		REP( k, N ) REP( i, N ) REP( j, N ) cost[i][j] = MIN( cost[i][j], cost[i][k] + cost[k][j] );
		
		cout << solve( 0, (1<<N)-2 ) << "\n";
		cin >> N;
	}
	
	return 0;
}
