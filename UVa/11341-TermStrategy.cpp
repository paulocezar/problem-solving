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

#define MAXN 10
#define MAXM 101

int N, M, L[MAXN][MAXM], dp[MAXN][MAXM];

int solve( int i, int j ){
	if( i == N ) return 0;
	if( j == 0 ) return -2;
	//cout << i << " " << j << endl;
	int& r = dp[i][j];
	if( r == -1 ){
		r = -2;
		REP( nj, j ) if( L[i][nj] >= 5 && j-nj-1 >= 0 ){
			int rr = solve( i+1, j-nj-1 );
			if( rr >= 0 ) r = MAX( r, L[i][nj]+rr );
		}
	}
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		cin >> N >> M;
		REP( i, N ){
			REP( j, M ){
				cin >> L[i][j];
				dp[i][j] = -1;
			}
			dp[i][M] = -1;
		}
		int r = solve( 0, M );
		if( r > 0 ) cout << "Maximal possible average mark - " << fixed << setprecision(2) << double( r )/N+1e-9 << ".\n"; 
		else cout << "Peter, you shouldn't have played billiard that much.\n";
	}
	
	return 0;
}


































