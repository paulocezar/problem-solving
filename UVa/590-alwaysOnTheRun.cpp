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

#define MAXN 11
vector< int > cst[MAXN][MAXN];

inline int cost( int i, int j, int k ){
	
	k %= SIZE(cst[i][j]);
	
	if( cst[i][j][k] ) return cst[i][j][k];
	return INF;	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int ct = 1;
	int n, k;
	cin >> n >> k;
	while( n+k ){
		
		
		REP( i, n ){
			REP( j, n ) if( i != j ){
				int d;
				cin >> d;
				cst[i][j].resize(d);
				REP( x, d ) cin >> cst[i][j][x];
			}
		}
		
		
		int dp[2][MAXN];
		
		int old, cur;
		old = 0;
		cur = 1;
		REP( i, n ) dp[old][i] = INF;
		dp[old][0] = 0;
		
		REP( d, k ){
			
			REP( i, n ) dp[cur][i] = INF;
			
			REP( i, n ) if( dp[old][i] < INF ){
				
				REP( j, n ) if( i != j ){
					
					dp[cur][j] = MIN( dp[cur][j], dp[old][i] + cost( i, j, d ) );
				
				}
				
			}
			
			old = !old;
			cur = !cur;
		}
		
		cout << "Scenario #" << ct++ << "\n";
		if( dp[old][n-1] < INF ) cout << "The best flight costs " << dp[old][n-1] << ".\n\n";
		else cout << "No flight possible.\n\n";
	
		cin >> n >> k;
	}
	
	return 0;
}
