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

#define MAXN 100
#define MXXX MAXN*MAXN*MAXN

long long ct[MXXX];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int n;
	cin >> n;
	
	long long s[n];
	REP( i, n ) cin >> s[i];
	
	int sz = 0;
	REP( i, n ) REP( j, n ) REP( k, n )  ct[ sz++ ] = s[i]*s[j] + s[k];
	sort( ct, ct+sz );
	
	
	long long ans = 0;
	pair< long long*, long long* > rng;
	
	REP( i, n ) if( s[i] != 0 ) REP( j, n ) REP( k, n ){
		rng = equal_range( ct, ct+sz, s[i]*(s[j]+s[k]) );
		ans += (rng.second - rng.first);
	}
	
	cout << ans << "\n";
	
	return 0;
}
