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
#include <iomanip> 
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
	
	int val[] = { 5, 10, 20, 50, 100, 200 };
	int keeper[1001];
	int dp[1001];
	int r, c, amount, sm, a[6];
	char trs;
	
	FILL( keeper, 0 );
	
	list< int > q;
	q.pb(0);
	
	while( !q.empty() ){
		int v = q.front(); q.pop_front();
		REP( i, 6 ) if( v+val[i] <= 1000 && !keeper[v+val[i]] ){
			q.pb( v+val[i] );
			keeper[v+val[i]] = keeper[v]+1;
		}
	}
	
	sm = 0;
	REP( i, 6 ) { cin >> a[i]; sm += a[i]; }
	while( sm ){
	
		cin >> r >> trs >> c;
		amount = 100*r + c;
		
		REP( i, 1001 ) dp[i] = INF;
		dp[0] = 0;
		int ans = INF;
		REP( i, 6 ){
			RREP( j , 1001 ) if( dp[j] != INF ){
				int k = 1;
				while( k <= a[i] && j+(k*val[i]) < 1001 ){
					int cur = j+(k*val[i]);
					dp[cur] = MIN( dp[cur], dp[j]+k );
					if( cur >= amount ) ans = MIN( ans, dp[cur] + keeper[cur-amount] );
					k++;
				}
			}
		}
		cout << setw(3) << ans << "\n";
	
		sm = 0;
		REP( i, 6 ) { cin >> a[i]; sm += a[i]; }	
	}
	
	return 0;
}
