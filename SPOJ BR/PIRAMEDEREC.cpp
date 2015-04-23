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

#define FOR(i, a, b) for( int i = a; i < b; ++i)
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

#define MAXN 15

int rot[][3] = { {0,1,2}, {0,2,1}, {1,2,0} };

int dim[MAXN][3];
int dp[1<<MAXN][MAXN][3];
int N;

int rec( int mask, int top, int r ){
	
	if( mask == 0 ) return 0;
	
	int &ret = dp[mask][top][r];
	if( ret == -1 ){
		
		int &X = dim[top][rot[r][0]];
		int &Y = dim[top][rot[r][1]];
		
		REP( i, N ) if( mask & (1<<i) ){	
			REP( j, 3 ) if( dim[i][rot[j][0]] >= X && dim[i][rot[j][1]] >= Y ){
				ret = MAX( ret, dim[i][rot[j][2]] + rec( mask ^ (1<<i), i, j ) );
			}
			if( ret == -1 ) ret = MAX( ret, rec( mask ^ (1<<i), top, r ) );
		}
		
	}
	
	return ret;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
		
	cin >> t;
	while( t-- ){
		
		cin >> N;
		REP( i, N ){ 
			cin >> dim[i][0] >> dim[i][1] >> dim[i][2];
			sort( dim[i], dim[i]+3);
		}
				
		int lmask = 1<<N;
		REP( i, lmask ) REP( j, N ) dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
		lmask--;
		
		int ans = 0;
		REP( i, N )
			REP( j, 3 ) 
				ans = MAX( ans, dim[i][rot[j][2]] + rec( lmask^(1<<i), i, j ) );
		
		cout << ans << "\n";
		
	}
	
	return 0;
}
