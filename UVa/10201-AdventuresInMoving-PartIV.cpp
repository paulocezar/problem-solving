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
#define MAXC 201

int64 dist[MAXN], cost[MAXN];
int64 dp[MAXN][MAXC];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	dist[0] = 0; cost[0] = INF;
	REP( i, 101 ) dp[0][i] = 0;
	FOR( i, 101, MAXC ) dp[0][i] = INF;
	
	int t;
	cin >> t;
	while( t-- ){
		
		int dest;
		cin >> dest; cin.ignore();
		string linha;
		
		int N = 1;
		while( getline( cin, linha ) && linha[0] ){
			istringstream in( linha );
			in >> dist[N] >> cost[N];
			N++;
		}
		dist[N] = dest; cost[N] = INF; N++;
		RFOR( i, N, 1 ) dist[i] -= dist[i-1];
		
		FOR( i, 1, N ){
			REP( j, MAXC ){
				dp[i][j] = INF;
				
				int k = 0;
				while( dist[i]+k < MAXC ){
					if( j-k >= 0 ) dp[i][j] = MIN( dp[i][j], dp[i-1][dist[i]+k] + (j-k)*cost[i] );
					k++;
				}
				
			}
		}
		int64 ans = INF;
		FOR( i, 100, MAXC ) ans = MIN( ans, dp[N-1][i] );
		if( ans < INF ) cout << ans << "\n";
		else cout << "Impossible\n";
		if( t ) cout << "\n";
	}
	
	return 0;
}








