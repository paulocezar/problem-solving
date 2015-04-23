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

#define MAXN 201
#define MAXC 21

int C, dp[MAXN][MAXC];
vector< int > a[MAXC];

int solve( int N, int pos ){
	if( pos == C ) return N;
	int& r = dp[N][pos];
	if( r == -1 ){
		r = INF;
		REP( i, SIZE(a[pos]) ) if( N-a[pos][i] >= 0 ) r = MIN( r, solve(N-a[pos][i], pos+1) );
	}
	return r;
}	

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t, N, K, x;
	
	cin >> t;
	while( t-- ){
		
		cin >> N >> C;
		REP( i, C ){
			cin >> K; a[i].clear();
			while( K-- ){
				cin >> x;
				a[i].pb( x );
			}
		}
		FILL( dp, -1 ); solve( N, 0 );
		if( dp[N][0] == INF ) cout << "no solution\n";
		else cout << N - dp[N][0] << "\n";	
	}
	
	return 0;
}


































