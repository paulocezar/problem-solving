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

#define MAXK 51
#define MAXVAL 100010

int bit[MAXK][MAXVAL];
const int MOD = 5000000;
int MXXX;

int get( int k, int val ){
	int ans = 0;
	while( val > 0 ){
		ans += bit[k][val];
		if( ans >= MOD ) ans -= MOD;
		val -= ( val & -val );
	}
	return ans;
}

int up( int k, int val, int amnt ){
	while( val < MXXX ){
		bit[k][val] += amnt;
		if( bit[k][val] >= MOD ) bit[k][val] -= MOD;
		val += ( val & -val );
	}
}

#define MAXN 10000
int x[MAXN];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N, K;
	cin >> N >> K;
	
	REP( i, K ) FILL( bit[i], 0 );
	MXXX = 0;
	REP( i, N ){ cin >> x[i]; x[i]++; MXXX = MAX( MXXX, x[i]+1 ); }
	
	REP( i, N ){
		up( 0, x[i], 1 );
		FOR( j, 1, MIN( K, i+1 ) ){
			int g = get( j-1, x[i]-1 );
			up( j, x[i], g );
		}	
	}
	
	cout << get( K-1, MXXX-1 ) << "\n";
	
	return 0;
}
