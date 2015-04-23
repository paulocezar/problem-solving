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

int64 dp[201][21][11];
int N, M, D, a[201];

int64 solve( int pos, int rem, int nd ){
	if( pos == N ) return ( (nd==0) && (rem==0) )?1:0;
	if( nd == 0 ) return (rem==0)?1:0;
	
	int64& r = dp[pos][rem][nd];
	if( r == -1 ){
		r = 0;
		r = solve( pos+1, rem, nd );
		int nxt = a[pos];
		while( nxt < 0 ) nxt += D;
		r += solve( pos+1, (rem+nxt) % D, nd-1 );		
	}
	
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int Q, st = 1;
	cin >> N >> Q;
	while( N+Q ){
		
		REP( i, N ) cin >> a[i];
		
		cout << "SET " << st++ << ":\n";
		FOR( qq, 1, Q+1 ){
			cin >> D >> M;
			REP( i, N+1 ) REP( j, D+1 ) REP( k, M+1 ) dp[i][j][k] = -1;
			cout << "QUERY " << qq << ": " << solve( 0, 0, M ) << "\n";
		}
		
		cin >> N >> Q;
	}
	
	return 0;
}


































