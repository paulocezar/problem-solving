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

int toint( string s ){
	int pos = 0, val = 0;
	while( s[pos] ) val = 10*val + (s[pos++]-'0');
	return val;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
	string linha;
	
	cin >> t; cin.ignore(); cin.ignore();
	while( t-- ){
		
		vector< int > lis, last, a;
		int longest = 0;
		
		while( getline( cin, linha ) && linha[0] ){
			a.pb( toint( linha ) );
			if( longest == 0 || last.back() < a.back() ){
				last.pb( a.back() );
				lis.pb( ++longest );
			} else {
				int j = lower_bound( last.begin(), last.end(), a.back() ) - last.begin();
				last[j] = a.back();
				lis.pb( j+1 );
			}
		}
		
		cout << "Max hits: " << longest << "\n";
		int* nxt = 0;
		RREP( i, SIZE(a) ) if( lis[i] == longest && ( nxt == 0 || a[i] < *nxt ) ){
			last[ --longest ] = a[i];
			nxt = &a[i];
		}
		REP( i, SIZE(last) ) cout << last[i] << "\n";
		if( t ) cout << "\n";
	}
	
	return 0;
}


































