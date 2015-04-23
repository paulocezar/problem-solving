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

struct term_t {
	uint64 dv;
	char sig;
	bool operator < ( const term_t &a ) const {
		if( dv != a.dv ) return dv < a.dv;
		return sig < a.sig;
	}
};

#define MAXN 20000000000LL
#define SQ2N 182575

int moebius[ SQ2N+1 ];
bool prime[ SQ2N+1 ];

void precalc(){
	int64 i, j;
	for( i = 0; i <= SQ2N; i++ ){
		moebius[i] = -1;
		prime[i] = true;
	}
	for( i = 2; i <= SQ2N; i++ ){
		for( j = 2*i; j <= SQ2N; j+=i ) prime[j] = false;
		
		if( SQR( (long long)sqrt(i) ) == i ){
			for( j = i; j <= SQ2N; j+=i ) moebius[j] = 0;
		} else if( prime[i] ){
			for( j = i; j <= SQ2N; j+=i ) moebius[j] = -moebius[j];
		}
	}	
}

int main( int argc, char* argv[] ){

	int t;
	int64 n, lo, hi, i, maxMob, mid, cur;
	
	precalc();
	
	scanf("%d", &t );
	while( t-- ){
		scanf("%lld", &n );
		
		lo = 1;
		hi = n+(2*n)/3;
		maxMob = (long long)ceil( sqrt( hi ) );
		
		while( lo < hi ){
			
			mid = (lo+hi)/2;
			cur = mid;
			
			for( i = 2; i < maxMob; i++ )
				cur -= moebius[i]*(mid/(i*i));
				
			if( cur < n )
				lo = mid+1;
			else hi = mid;
				
		}
		printf("%lld\n", lo );	
	}
	
	return 0;
}
