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

#define MAXN 5001
#define MAXK 1010

int dp[MAXN][MAXK];
int l[MAXN];
int total;

int solve( int n, int k ){
	
	int& r = dp[n][k];
	
	if( k == 0 ) r = 0;
	if( (total-n) < 3*k ) r = INF;
	
	if( r == -1 ){
		
		r = INF;
		r = MIN( solve( n+1, k )  , solve( n+2, k-1 ) + SQR( l[n]-l[n+1] )  );
		
	}
	
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t, n, k;
	cin >> t;
	while( t-- ){
		cin >> k >> n;
		k += 8;
		REP( i, n ) cin >> l[i];
		
		REP( i, n+1 ) REP( j, k+1 ) dp[i][j] = -1;
		
		total = n;
		cout << solve( 0, k ) << "\n";
		
	}
	
	return 0;
}
