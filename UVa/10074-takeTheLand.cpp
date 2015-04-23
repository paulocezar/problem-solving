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

#define MAXN 105

int grid[MAXN][MAXN];
int dp[MAXN][MAXN];
int M, N;

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	REP( i, MAXN ) { grid[0][i] = 0; dp[0][i] = 0; }
	
	cin >> N >> M;
	while( N+M ){
		
		FOR( i, 1, N+1 ){
			FOR( j, 1, M+1 ){
				cin >> grid[i][j];
				if( grid[i][j] ) dp[i][j] = i;
				else if( grid[i-1][j] ) dp[i][j] = i-1;
				else dp[i][j] = dp[i-1][j];
			}
		}
		
		int ans = 0;
		FOR( i, 1, N+1 ){
			FOR( j, i, N+1 ){
				int k = 1;
				int cur = 0;
				while( k <= M ){ 
					if( dp[j][k] < i ) cur++;
					else {
						while( k <= M && dp[j][k] >= i ) k++;
						k--;
						
						ans = MAX( ans, cur*(j-i+1) );
						cur = 0;
					}
					k++;
				}
				ans = MAX( ans, cur*(j-i+1) );
			}
		}
		cout << ans << "\n";
		
		cin >> N >> M;
	}
	
	
	return 0;
}
