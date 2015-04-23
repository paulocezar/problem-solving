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

const uint64 MAXN = 33333333335LLU;

#define SQRN 182575
#define NUMPRIMOS 16543
#define NUMTERMS 110996

#define DV first
#define SIG second

typedef pair< uint64, char > term_t;

term_t incexc[NUMTERMS];

void preprocess(){
	uint64 primo[NUMPRIMOS];
	char eprimo[SQRN+1];
	REP( i, SQRN+1 ) eprimo[i] = (i&1);
	int ii, j;
	int primos = 1;
	primo[0] = (unsigned long long)2;
	for( ii = 3; ii <= SQRN; ii+=2 ) if( eprimo[ii] ){
		primo[primos++] = (unsigned long long)ii;
		for( j = ii+ii; j <= SQRN; j+=ii ) eprimo[j] = 0;
	}
	set< term_t > incexca;
	incexca.insert( term_t( 1, 1 ) );
	REP( i, NUMPRIMOS ){
		set< term_t > news;
		FORIT( cr, incexca ){
			if( SQR( primo[i] ) > ( MAXN / cr->DV ) ) break;
			news.insert( term_t( (cr->DV)*SQR( primo[i] ), !cr->SIG ) );
		}
		FORIT( nw, news ) incexca.insert( *nw );	
	}
	int ieind = 0;
	FORIT( it, incexca ) incexc[ieind++] = *it;	
}

uint64 itmiha( uint64 n ){
	
	uint64 cur, ans = 0;
	REP( i, NUMTERMS ){
		cur = n / incexc[i].DV;
		if( cur == 0 ) break;
		if( incexc[i].SIG ) ans += cur;
		else ans -= cur;
	}
	
	return ans;
}

int main( int argc, char* argv[] ){
	
	preprocess();
	int t;
	uint64 n, lo, hi, mid;
	
	scanf("%d", &t );
	while( t-- ){
		
		scanf("%llu", &n );
		lo = 1;
		hi = n + (3*n)/2;
		
		while( lo < hi ){
			mid = lo + ((hi-lo)/2);
			if( itmiha(mid) < n ) lo = mid+1;
			else hi = mid; 
		}
		printf("%llu\n", lo );
		
	}
	
	return 0;
}
