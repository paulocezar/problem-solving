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

#define MAXS 302
#define MAXM 41

int eCoin[MAXM][2];
int dp[MAXS][MAXS];
int m;

int solve( int i, int j ){
	
	
	if( i == 0 && j == 0 ) return 0;
	
	int& r = dp[i][j];
	if( r == -1 ){
		
		r = INF;
		
		int ni, nj;
		REP( coin, m ){
			ni = i-eCoin[coin][0];
			nj = j-eCoin[coin][1];
			
			if( ni >= 0 && nj >= 0 ) r = MIN( r, 1+solve( ni, nj ) );
			
		}
		
	}
	
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int n, s;
	
	cin >> n;
	while( n-- ){
		
		cin >> m >> s;
		
		REP( i, s+1 ) FILL( dp[i], -1 );
		REP( i, m ) cin >> eCoin[i][0] >> eCoin[i][1];
		
		int ans = INF;
		
		REP( i, s+1 ) REP( j, s+1 ) if( i*i + j*j == s*s )
			ans = MIN( ans, solve( i, j ) );
		
		if( ans == INF ) cout << "not possible\n";
		else cout << ans << "\n";
		
	}
		
	return 0;
}
