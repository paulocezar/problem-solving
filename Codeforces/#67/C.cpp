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
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int gcd( int a, int b ){
	while( b ){
		a %= b;
		a ^= b; b ^= a; a ^= b;
	}
	return a;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int a, b, g;
	cin >> a >> b;
	
	g = gcd( a, b );
	
	vector< int > div;
	for( int i = 1; i*i <= g; i++ ) if( g % i == 0 ){
		div.pb( i );
		if( g/i > i ) div.pb( g/i );
	}
	sort( div.begin(), div.end() );
	
	int q;
	cin >> q;
	while( q-- ){
		int lo, hi;
		cin >> lo >> hi;
		
		bool ok = false;
		
		RREP( i, SIZE(div) ) if( div[i] >= lo && div[i] <= hi ){
			cout << div[i] << "\n";
			ok = true; break;
		} else if( div[i] < lo ) break;
		
		if( !ok ) cout << -1 << "\n";

	}
	
	return 0;
}
