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

#define MAXN 310
#define MAXC 310
int64 dp[MAXC][MAXN];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	string linha;
	int N, from, to;
	FILL( dp[0], 0 ); dp[0][0] = 1;
	
	FOR( coins, 1, MAXC ){
		dp[coins][0] = 1;
		FOR( val, 1, MAXN ){
			dp[coins][val] = dp[coins-1][val]; 
			if( val >= coins ) dp[coins][val] += dp[coins][val-coins];
		}
	}
	
	while( getline( cin, linha ) ){
		istringstream in( linha );
		if( !(in >> N) ) break;
		if( !(in >> from) ){
			cout << dp[N][N] << "\n";
		} else {
			if( !(in >> to) ){
				from = MIN( from, 300 );
				cout << dp[from][N] << "\n";
			} else {
				from = MIN( from, 300 );
				to = MIN( to, 300 );
				int64 ans = 0LL;
				if( from == 0 ) ans = dp[to][N];
				else FOR( i, from, to+1 ) ans += dp[i][N]-dp[i-1][N];
				cout << ans << "\n";
			}
		}
	}
	
	return 0;
}


































