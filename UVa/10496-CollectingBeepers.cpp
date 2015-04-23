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

int N, x[MAXN+1], y[MAXN+1];
int dp[MAXN][1<<MAXN];

int solve( int at, int mask ){
	if( mask == 0 ) return ABS(x[0]-x[at])+ABS(y[0]-y[at]);
	int& r = dp[at][mask];
	if( r == -1 ){
		r = INF;
		REP( i, N ) if( mask & (1<<i) ){
			r = MIN( r, ABS(x[at]-x[i+1])+ABS(y[at]-y[i+1])+solve(i+1, mask ^ (1<<i) ) );
		}
	}
	return r;
}	

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
	
	cin >> t;
	while( t-- ){
		cin >> x[0] >> y[0];
		cin >> x[0] >> y[0];
		cin >> N;
		memset( dp[0], -1, sizeof(int)*(1<<N) );
		FOR( i, 1, N+1 ){
			cin >> x[i] >> y[i];
			memset( dp[i], -1, sizeof(int)*(1<<N) );
		}
		cout << "The shortest path has length " << solve( 0, (1<<N)-1 ) << "\n";
	}
	
	return 0;
}


































