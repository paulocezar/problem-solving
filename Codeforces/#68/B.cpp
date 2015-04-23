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

#define MAXN 55
#define MAXT 210

int n;
string now;
int dp[MAXN][MAXN][MAXT];

int play( int m, int k, int inc, int tm ){
	
	if( m == k ) return tm-1;
	if( tm == SIZE(now) ) return tm;
		
	int& r = dp[m][k][tm];
	if( r != -1 ) return r;
	
	r = tm;
	int ok = k;
	k += inc;
	if( k == 1 || k == n ) inc = -inc;
	
	if( now[tm-1] == '1' ){
		
		REP( i, n ) r = MAX( r, play( i+1, k, inc, tm+1 ) );
		
	} else {
		
		FOR( i, -1, 2 ) if( m+i > 0 && m+i <= n && m+i != ok ) r = MAX( r, play( m+i, k, inc, tm+1 ) );
		
	}
	
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int m, k;
	string to, dir;
	
	cin >> n >> m >> k;
	cin >> to >> dir;
	cin >> now;
	
	REP( i, n+1 ) REP( j, n+1 ) REP( tm, SIZE(now)+1 ) dp[i][j][tm] = -1;
	
	int ddir = (dir=="head")?(-1):(+1);
	
	int result = play( m, k, ddir, 1 );
	
	if( result == SIZE(now) ) cout << "Stowaway\n";
	else cout << "Controller " << result << "\n";
	
	return 0;
}
