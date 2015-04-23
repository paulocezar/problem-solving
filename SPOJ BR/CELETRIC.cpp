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

int watts( int& valor ){
	if( valor > 4979900 ) return 1000000+(valor-4979900)/7;
	if( valor > 29900 ) return 10000+(valor-29900)/5;
	if( valor > 200 ) return 100+(valor-200)/3;
	return valor/2;
}

int valor( int& watts ){
	if( watts < 100 ) return 2*watts;
	if( watts < 10000 ) return 200 + 3*(watts-100);
	if( watts < 1000000 ) return 29900 + 5*(watts-10000);
	return 4979900 + 7*(watts-1000000);
}


int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int A, B;
	int X, Y, XY;
	int lo, hi, dif;
	
	cin >> A >> B;
	
	while( A+B ){
		
		XY = watts( A );
		lo = 0;
		hi = XY/2;
		
		while( lo < hi ){
			
			X = (lo+hi)/2;
			Y = XY-X;
			
			dif = valor(Y)-valor(X);
			
			if( dif > B ) lo = X+1;
			else if( dif < B ) hi = X-1;
			else {
				lo = X;
				break;
			}
			
		}
		
		cout << valor( lo ) << "\n";
			
		cin >> A >> B;
	}
	
	return 0;
}
