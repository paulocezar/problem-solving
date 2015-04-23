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

#define MAXN 255

int w[MAXN];
int dp[MAXN][MAXN];
int rt[MAXN][MAXN];

int solve( int i, int j ){
	
	if( i > j ) return 0;
	if( i == j ) return w[i]-w[i-1];
	
	int& r = dp[i][j];
	if( r == -1 ){
		
		r = INF;
		FOR( x, i, j+1 ){
			int cur = solve(i, x-1) + solve(x+1, j) + w[j]-w[i-1];
			if( cur < r ){ 
				r = cur;
				rt[i][j] = x;
			}
		}
		
	}
	return r;
	
}

int construct( int i, int j, int k ){
	if( i > j ) return 0;
	if( i == j ) return k*dp[i][i];
	return k*dp[ rt[i][j] ][ rt[i][j] ] + construct( i, rt[i][j]-1, k+1 ) + construct( rt[i][j]+1, j, k+1 );
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int n;
	w[0] = 0;
	
	while( cin >> n ){
		
		FOR( i, 1, n+1 ){ 
			cin >> dp[i][i]; 
			w[i] = w[i-1]+dp[i][i];
			rt[i][i] = i;
		}
		
		FOR( l, 2, n+1 ){
			FOR( i, 1, n-l+2 ){				
				int j = i+l-1;
				dp[i][j] = INF;
				FOR( k, rt[i][j-1], rt[i+1][j]+1 ){
					int nc = dp[i][k-1]+dp[k+1][j]+w[j]-w[i-1];
					if( nc < dp[i][j]  ){
						dp[i][j] = nc;
						rt[i][j] = k;
					}
				}									
			}			
		}
		
		cout << construct( 1, n, 0 ) << "\n";
		
	}
	
	return 0;
}
