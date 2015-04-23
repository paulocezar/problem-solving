/*
 *  Problema:
 *  Tecnica Utilizada:  
 *      
 *
 *  Dificuldade: 
 *      Complexidade:
 *                              O(  )
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

#define MAXN 1010

int a[MAXN];
int dp[MAXN][MAXN];
int N;

int solve( int from, int rem, int passo ){
	
	if( 2*(passo+1) >= N ){
		if( N&1 ) dp[from][rem] = a[rem];
		else dp[from][rem] = MAX( a[rem], a[N-1] );
		return dp[from][rem];
	}
	
	if( dp[from][rem] != -1 ) return dp[from][rem];
	
	dp[from][rem] = MIN( MAX(a[rem], a[from]) + solve( from+2, from+1, passo+1 ),
						 MIN( MAX(a[rem], a[from+1]) + solve( from+2, from, passo+1 ),
							  MAX(a[from],a[from+1]) + solve( from+2, rem, passo+1 ) ) 
						);
	
	return dp[from][rem];
}

void build( int from, int rem, int passo ){
	if( 2*(passo+1) >= N ){
		if( N&1 ) cout << rem+1 << "\n";
		else cout << rem+1 << " " << N << "\n";
		return;
	}
	
	if( dp[from][rem] == MAX(a[rem],a[from])+dp[from+2][from+1] ){
		cout << rem+1 << " " << from+1 << "\n";
		build( from+2, from+1, passo+1 );
	} else if( dp[from][rem] == MAX( a[rem], a[from+1] )+dp[from+2][from] ){
		cout << rem+1 << " " << from+2 << "\n";
		build( from+2, from, passo+1 );
	} else {
		cout << from+1 << " " << from+2 << "\n";
		build( from+2, rem, passo+1 );
	}
	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	cin >> N;
	REP( i, N ) cin >> a[i];
	
	if( N == 1 ){
		cout << a[0] << "\n1\n";
		return 0;
	} else if( N == 2 ){
		cout << MAX(a[0],a[1]) << "\n1 2\n";
		return 0;
	}
	FILL( dp, -1 );
	
	int ans = MIN( MAX(a[0],a[1])+solve(3,2, 1), MIN( MAX(a[0],a[2])+solve(3,1, 1), MAX(a[1],a[2])+solve(3,0,1) ) );
	cout << ans << "\n";
	
	if( ans == MAX(a[0],a[1])+dp[3][2] ){
		cout << "1 2\n";
		build( 3, 2, 1 );
	} else if( ans == MAX( a[0], a[2] )+dp[3][1] ){
		cout << "1 3\n";
		build( 3, 1, 1 );
	} else {
		cout << "2 3\n";
		build( 3, 0, 1 );
	}
	
	return 0;
}
