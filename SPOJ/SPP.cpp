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


#define MAXK 17

int64 MOD;
int64 aux[MAXK][MAXK], ans[MAXK][MAXK], pot[MAXK][MAXK];
int64 b[MAXK], c[MAXK], acum[MAXK];
int k;

void mult( int64 a[][MAXK], int64 b[][MAXK] ){
	REP( i, k+1 ){
		REP( j, k+1 ){
			aux[i][j] = 0LL;
			REP( x, k+1 ) aux[i][j] = (aux[i][j] + ( (a[i][x] * b[x][j])% MOD ))%MOD;
		}
	}
	REP( i, k+1 ) REP( j, k+1 ) a[i][j] = aux[i][j];

}

int64 get( int64 n ){
	
	if( n == 0 ) return 0;
	if( n <= k ){
		return acum[k-n];
	} else {
		n -= k;
		
		REP( i, k ) pot[0][i] = c[i]; pot[0][k] = 0;
		FOR( i, 1, k ) REP( j, k+1 ){
			pot[i][j] = (i==(j+1));
		}
		REP( i, k ) pot[k][i] = c[i]; pot[k][k] = 1;
		
		REP( i, k+1 ) REP( j, k+1 ) ans[i][j] = (i==j);
		
		while( n ){
			if( n & 1 ) mult( ans, pot );
			mult( pot, pot );
			n >>= 1;
		}
		
		int64 res = 0;
		REP( i, k ) res = ( res + (ans[k][i]*b[i])%MOD )%MOD;
		res = ( res + (ans[k][k]*acum[0])%MOD )%MOD;
		return res; 
	}
	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		
		cin >> k;
		
		RREP( i, k ) cin >> b[i];
		REP( i, k ) cin >> c[i];
		
		int64 m, n;
		cin >> m >> n >> MOD;
		
		b[k-1] %= MOD;
		c[k-1] %= MOD;
		acum[k-1] = b[k-1];
		RREP( i, k-1 ){
			b[i] %= MOD;
			c[i] %= MOD;
			acum[i] = ( acum[i+1] + b[i] )%MOD;
		}
		
		cout << ( get( n ) - get( m-1 ) + MOD ) % MOD << "\n";
		
	}
		
	return 0;
}





