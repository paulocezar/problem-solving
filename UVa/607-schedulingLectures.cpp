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
#define MAXL 501

int N, L; int64 C;
int t[MAXN];
int dp[MAXN][MAXN];

int DI( int t ){
	if( t == 0 ) return 0;
	if( 1 <= t && t <= 10 ) return -C;
	return (t-10)*(t-10);
}

int solve( int from, int lect ){
	if( from == N && lect == 0 ) return 0;
	if( from == N || lect == 0 ) return INF;
	
	if( dp[from][lect] == -1 ){
		
		int acum = 0;
		int& ans = dp[from][lect];
		ans = INF;
		
		FOR( i, from, N ){
			if( acum + t[i] > L ) break;
			acum += t[i];
			ans = MIN( ans, DI( L-acum ) + solve( i+1, lect-1 ) );
		}
		
	}
	
	return dp[from][lect];
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int tc = 1;
	cin >> N;
	while( N ){
		
		cin >> L >> C;
		REP( i, N ) cin >> t[i];
		
		int lctNdd = 0;
		int acum = 0;
		REP( i, N ){
			if( acum + t[i] > L ){
				lctNdd++;
				acum = t[i];
			} else acum += t[i];
		}
		if( acum ) lctNdd++;
		
		REP( i, N+1 ) REP( j, lctNdd+1 ) dp[i][j] = -1; 
		
		int dis = solve( 0, lctNdd );
		
		cout << "Case " << tc++ << ":\nMinimum number of lectures: " << lctNdd << "\nTotal dissatisfaction index: " << dis << "\n";
		cin >> N;
		if( N ) cout << "\n";
	}
	
	return 0;
}


































