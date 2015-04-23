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

const int64 MOD = 1000000000LL;

typedef vector< vector< int64 > > matr;

matr aux;
int k;

void mult( matr& a, matr& b ){
	REP( i, k ){
		REP( j, k ){
			aux[i][j] = 0LL;
			REP( x, k ) aux[i][j] = (aux[i][j] + ( (a[i][x] * b[x][j])% MOD ))%MOD;
		}
	}
	REP( i, k ) REP( j, k ) a[i][j] = aux[i][j];
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int c, n;
	cin >> c;
	
	while( c-- ){
		
		cin >> k;
		
		matr tr( k );
		matr p( k );
		aux.resize( k );
		vector< int64 > b(k);
		
		RREP( i, k ){ 
			cin >> b[i];
			tr[i].resize(k);
			p[i].resize(k);
			aux[i].resize(k);
		}
		
		REP( i, k ) cin >> p[0][i];
		
		FOR( i, 1, k ) REP( j, k ){
			p[i][j] = (i==(j+1));
		}
		
		REP( i, k ) REP( j, k ) tr[i][j] = (i==j);
		
		cin >> n;
		if( n <= k ){
			cout << b[k-n] << "\n";
		} else {
			n -= k;
			
			while( n ){
				if( n&1 ) mult( tr, p );
				mult( p, p );
				n /= 2;
			}
		
			int64 ans = 0;
			REP( i, k ) ans = ( ans + ((tr[0][i]*b[i])%MOD) )%MOD;
			cout << ans << "\n";
		}
	}
	
	return 0;
}
