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

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		
		int N, M;
		cin >> N >> M;
		
		bool grid[N][M];
		int dp[N][M];
		
		REP( i, N ) REP( j, M ) grid[i][j] = true;
		
		cin.ignore();
		REP( x, N ){
			
			string line;
			getline( cin, line );
			istringstream inp( line );
			
			int i, j;
			inp >> i;
			i--;
			
			while( inp >> j ){
				j--;
				grid[i][j] = false;
			}
		}
	
		dp[0][0] = 1;
		FOR( j, 1, M ) dp[0][j] = dp[0][j-1] && grid[0][j];
		FOR( i, 1, N ) dp[i][0] = dp[i-1][0] && grid[i][0];
		
		FOR( i, 1, N ) FOR( j, 1, M ) dp[i][j] = grid[i][j]?(dp[i-1][j]+dp[i][j-1]):0;
		
		cout << dp[N-1][M-1] << "\n";
		if( t ) cout << "\n";
	}
	
	
	return 0;
}
