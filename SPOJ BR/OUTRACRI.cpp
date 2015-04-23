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

#define MAXN 100001
list< int > graph[MAXN];
int T;

int solve( int u ){
	
	if( SIZE( graph[u] ) == 0 ) return 1;
	
	int pt = 0;
	int nd[ SIZE( graph[u] ) ];
	
	FORIT( v, graph[u] ) nd[pt++] = solve( *v );
	
	sort( nd, nd+pt );
	
	int ans = 0;
	int ndd = ( T*pt + 99 ) / 100;
	
	REP( i, ndd ) ans += nd[i];
	return ans;
	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	int N, x;
	
	cin >> N >> T;
	while( N+T ){
		
		REP( i, N+1 ) graph[i].clear();
		FOR( i, 1, N+1 ){
			cin >> x;
			graph[x].pb( i );
		}
		
		cout << solve( 0 ) << "\n";
		
		cin >> N >> T;
	}
	
	return 0;
}
