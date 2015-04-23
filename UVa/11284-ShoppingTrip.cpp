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

#define MAXN 55
#define MAXP 12

int N, P, dp[MAXP+1][1<<MAXP];
int floyd[MAXN][MAXN];
int where[MAXP+1], econ[MAXP+1];

int solve( int at, int mask ){
	if( mask == 0 ) return -floyd[where[at]][0];
	
	int& r = dp[at][mask];
	if( r == -1 ){
		r = -INF;
		REP( i, P ) if( mask & (1<<i) ){
			r = MAX( r, solve( at, mask ^ (1<<i) ) );
			
			if( floyd[ where[at] ][ where[i] ] != INF )
				r = MAX( r, econ[i] - floyd[ where[at] ][ where[i] ] + solve( i, mask ^ (1<<i) ) );
		}
	}
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t, M, u, v;
	double cost;
	
	cin >> t;
	while( t-- ){
		
		cin >> N >> M;
		REP( i, N+1 ) REP( j, N+1 ) floyd[i][j] = (i==j)?0:INF;
	
		while( M-- ){
			cin >> u >> v >> cost;
			floyd[u][v] = MIN( floyd[u][v], int( cost*1000.0 ) );
			floyd[v][u] = floyd[u][v];
		}
		
		REP( k, N+1 ) REP( i, N+1 ) REP( j, N+1 ) floyd[i][j] = MIN( floyd[i][j], floyd[i][k]+floyd[k][j] );
		
		cin >> P;
		REP( i, P ){
			cin >> u >> cost;
			memset( dp[i], -1, sizeof(int)*(1<<P) );
			where[i] = u;
			econ[i] = int( 1000.0*cost );
		}
		memset( dp[P], -1, sizeof(int)*(1<<P) );
		where[P] = 0; econ[P] = 0;
		
		int ans = solve( P, (1<<P)-1 );
		if( ans > 0 ) cout << "Daniel can save $" << fixed << setprecision(2) << double(ans)/1000.0 << "\n";
		else cout << "Don't leave the house\n";
		
	}
	
	return 0;
}


































