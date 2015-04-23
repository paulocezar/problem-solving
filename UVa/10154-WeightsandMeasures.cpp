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

#define MAXN 5608
pair<int,int> turtles[MAXN];
int dp[2][MAXN];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N = 0;
	while( cin >> turtles[N].second >> turtles[N].first ) N++;
	sort( turtles, turtles+N );
	
	REP( i, N+1 ) dp[0][i] = INF; dp[0][0] = 0;
	
	int old = 0;
	int cur = 1;
	REP( i, N ){
		
		REP( k, N+1 ) if( dp[old][k-1]+turtles[i].second <= turtles[i].first ){
			dp[cur][k] = MIN( dp[old][k], dp[old][k-1]+turtles[i].second );
		} else dp[cur][k] = dp[old][k];
		
		old = !old;
		cur = !cur;
	}
	
	int ans = 0;
	RREP( i, N+1 ) if( dp[old][i] != INF ) ans = MAX( ans, i );
	cout << ans << endl; 
	
	return 0;
}


































