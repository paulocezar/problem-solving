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

int rntm[101];
int prof[101];

bool comp( int a, int b ){
	if( rntm[a] != rntm[b] ) return rntm[a] < rntm[b];
	return a < b;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int n, m, l, r;
	
	cin >> n >> m;
	list< int > run[n];
	
	REP( i, m ){
		cin >> l >> r >> rntm[i] >> prof[i];
		for( int x = l-1; x < r; x++ ) run[x].pb(i);
	}
	
	int ans = 0;
	REP( i, n ) if( !run[i].empty() ){
		run[i].sort( comp );
		ans += prof[ *(run[i].begin()) ]; 
	}
	cout << ans << "\n";
	
	return 0;
}
