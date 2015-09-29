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

uint64 gcd( uint64 a, uint64 b ){
	while( b ){
		a %= b;
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return a;
}

uint64 mmc( uint64 a, uint64 b ){
	uint64 g = gcd( a, b );
	return (a/g)*b;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T;
	cin >> T;
	FOR( tc, 1, T+1 ){
		
		int N;
		
		uint64 L, H;
		cin >> N >> L >> H;
		
		uint64 f[N];
		REP( i, N ) cin >> f[i];
		sort( f, f+N );
		cout << "Case #" << tc << ": ";
		
		uint64 ngcd[N];
		ngcd[N-1] = f[N-1];
		RREP( i, N-1 ) ngcd[i] = gcd( ngcd[i+1], f[i] ); 
		
		uint64 curmmc = 1;
		int i = 0;
		bool print = false;
		
		while( i < N && curmmc <= H ){
			if( curmmc >= L && !( ngcd[i] % curmmc ) ){
				cout << curmmc << "\n";
				print = true;
				break;
			} else curmmc = mmc( curmmc, f[i] );
			i++;
		}
		
		if( !print ){
			if( i == N && curmmc <= H ) cout << curmmc << "\n";
			else cout << "NO\n";
		}
	}
	
	return 0;
}


































