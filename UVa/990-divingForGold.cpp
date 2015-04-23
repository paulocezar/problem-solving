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

int dp[33][1001];


int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t, w, n;
	bool flag = true;
	
	while( cin >> t >> w ){
		
		if( flag ) flag = false;
		else cout << "\n";
		
		t /= (3*w);
		REP( i, t+1 ) dp[0][i] = 0;
		
		cin >> n;
		int d[n+1], v[n+1];
		REP( i, n ) cin >> d[i+1] >> v[i+1];
		
		FOR( i, 1, n+1 ){
			for( int tt = 1; tt <= t; tt++ ){								
				if( (tt >= d[i]) && ( dp[i-1][ tt-d[i] ] + v[i] > dp[i-1][tt] ) )
					dp[i][tt] = dp[i-1][tt-d[i]]+v[i];
				else dp[i][tt] = dp[i-1][tt];
			}
		}
		
		cout << dp[n][t] << "\n";
		w = n;
		vector< int > print;
		while( w && t ){
			if( dp[w][t] > dp[w-1][t] ) { print.pb( w ); t -= d[w]; } 
			w--;
		}
		cout << SIZE( print ) << "\n";
		for( int i = SIZE( print )-1; i >= 0; i-- ) cout << d[print[i]] << " " << v[print[i]] << "\n";
		
	}
	
	return 0;
}
