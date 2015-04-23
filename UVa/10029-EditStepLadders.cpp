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

#define MAXN 25000
#define MAXS 30
char cur[MAXS], dict[MAXN][MAXS];
int dp[MAXN];

void up( int i ){
	int mid, r, lo = 0;
	int hi = i-1;
	
	while( lo <= hi ){
		mid = (lo+hi)/2;
		r = strcmp( cur, dict[mid] );
		if( r ){
			if( r < 0 ) hi = mid-1;
			else lo = mid+1;
		} else {
			dp[i] = MAX( dp[i], dp[mid]+1 );
			return;
		}
	}
	
}

int main( int argc, char* argv[] ){

	int N = 0;
	while( scanf("%s", dict[N] ) == 1 ) N++;
	
	dp[0] = 1;
	int ans = 1;
	FOR( i, 1, N ){
		dp[i] = 1;
		
		// delete .. change
		for( int j = 0; dict[i][j]; j++ ){
			
			int cp = 0;
			for( int k = 0; dict[i][k]; k++ ) if( k != j ) cur[cp++] = dict[i][k];
			cur[cp] = 0;
			up( i );
			
			cp = 0;
			for( int k = 0; dict[i][k]; k++ ) cur[cp++] = dict[i][k];
			cur[cp] = 0;
			
			for( char chr = 'a'; chr <= 'z'; chr++ ) if( chr != dict[i][j] ){
				cur[j] = chr;
				up( i );
			}	
		}
		
		// add
		for( int j = 0, s = strlen( dict[i] ); j <= s; j++ ){
			int cp = 0;
			for( int k = 0; k < j; k++ ) if( k != j ) cur[cp++] = dict[i][k];
			cur[cp++] = '_';
			for( int k = j; dict[i][k]; k++ ) cur[cp++] = dict[i][k];
			cur[cp] = 0;
			for( char chr = 'a'; chr <= 'z'; chr++ ){
				cur[j] = chr;
				up( i );
			}
		}
		
		ans = MAX( ans, dp[i] );
	}
	printf("%d\n", ans );
	
	return 0;
}


































