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

#define MAXN 100010

char S[MAXN];
int N, SA[MAXN], RA[MAXN], LCP[MAXN], *FC, *SC, STEP;

bool comp( int a, int b ){
	if( FC[a] != FC[b] ) return FC[a] < FC[b];
	if( a+STEP < N && b+STEP < N ) return FC[ a+STEP ] < FC[ b+STEP ];
	return a > b;
}

bool up(){
	int cnt = 0;
	REP( i, N ){
		if( i && comp( SA[i-1], SA[i] ) ) cnt++;
		SC[ SA[i] ] = cnt;
	}
	if( cnt == N-1 ) return false;
	return true;
}

void buildSA(){
	REP( i, N ) RA[ i ] = S[ SA[i] = i ];
	STEP = 0; FC = RA; SC = LCP;
	sort( SA, SA+N, comp );
	if( up() ){
		swap( FC, SC );
		for( STEP = 1; STEP < N; STEP <<= 1 ){
			sort( SA, SA+N, comp );
			if( !up() ) return;
			swap( FC, SC );
		}
	}
}

#define MAXP 1010

char p[MAXP];
int cmp( int pos ){
	int d, j = 0;
	while( p[j] ){
		d = S[ SA[pos]+j ] - p[j];
		if( d ) return d;
		j++;
	}	
	return 0;
}

int main( int argc, char* argv[] ){
	
	int k, q;
	bool ok;
	
	scanf("%d", &k ); getchar();
	while( k-- ){
		
		N = strlen( gets(S) );
		buildSA();
		
		scanf("%d", &q ); getchar();
		while( q-- ){
			ok = false;
			gets( p );
			
			int r, mid, lo = 0;
			int hi = N-1;
			while( lo <= hi ){
				mid = (lo+hi)/2;
				r = cmp( mid );
				if( r ){
					if( r < 0 ) lo = mid+1;
					else hi = mid-1;
				} else{
					puts("y");
					ok = true;
					break;
				}
			}
			if( !ok ) puts("n");
		}
		
	}
	
	return 0;
}


































