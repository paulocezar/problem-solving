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

#define MAXN 1001
int dp[MAXN][MAXN], N;
string s, ss;

int solve( int from, int to ){
	if( from > to ) return 0;
	if( from == to ) return (dp[from][to] = 0);
	
	int& r = dp[from][to];
	if( r == -1 ){
		r = INF;
		if( s[from] == s[to] ) r = solve( from+1, to-1 );
		else r = 1 + MIN( solve(from, to-1), solve(from+1,to) );
	}
	return r;	
}

void build( int from, int to ){
	
	if( from > to ) return;
	if( from == to ){ ss = s[from]; return; }
	
	if( s[from] == s[to] ){
		build( from+1, to-1 );
		ss = s[from] + ss + s[to];
	} else if( dp[from][to] == 1+dp[from+1][to] ){
		build( from+1, to );
		ss = s[from] + ss + s[from];
 	} else {
		build( from, to-1 );
		ss = s[to] + ss + s[to];
	}
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	while( cin >> s ){
		N = SIZE(s);
		REP( i, N ) REP( j, N ) dp[i][j] = -1;
		cout << solve( 0, N-1 ) << " ";
		ss = ""; build( 0, N-1 );
		cout << ss << "\n";
	}
	
	return 0;
}


































