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

#define MAXN 2*10001+1

string S;
int STEP, N, SA[MAXN], RA[MAXN], LCP[MAXN], *CUR, *OLD;

bool comp( int a, int b ){
	if( OLD[a] != OLD[b] ) return OLD[a] < OLD[b];
	if( a+STEP < N && b+STEP < N ) return OLD[a+STEP] < OLD[b+STEP];
	return a > b;
}

bool up(){
	int cnt = 0;
	REP( i, N ){
		if( i && comp( SA[i-1], SA[i] ) ) cnt++;
		CUR[ SA[i] ] = cnt;
	}
	if( cnt == N-1 ) return false;
	return true;
}

void buildSA(){
	REP( i, N ) RA[ i ] = S[ SA[i] = i ];
	STEP = 0; OLD = RA, CUR = LCP;
	sort( SA, SA+N, comp );
	if( up() ){
		swap( OLD, CUR );
		for( STEP = 1; STEP < N; STEP *= 2 ){
			sort( SA, SA+N, comp );
			if( !up() ) return;
			swap( OLD, CUR );
		}
	}
}

int main( int argc, char* argv[] ){

	int t;
	cin >> t;
	while( t-- ){
		
		cin >> S; S += S; S += '~';
		N = SIZE( S ); buildSA();
		
		cout << SA[0]+1 << "\n";
			
	}
	
	return 0;
}


































