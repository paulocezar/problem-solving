#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 15

int dp[1<<MAXN], calc[1<<MAXN], calc_now;
int dist[MAXN][MAXN], deg[MAXN], n;


int solve( int mask ){
	if( mask == 0 ) return 0;
	
	int &res = dp[mask];
	int &last_calc = calc[mask];
	if( last_calc == calc_now ) return res;
	last_calc = calc_now;
	res = INF;
	
	REP( i, n ) if( mask & (1<<i) ){
		FOR( j, i+1, n-1 ) if( mask & (1<<j) ){
			res = min( res, dist[i][j]+solve(mask^(1<<i)^(1<<j)) );
		}
		break;
	}
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( cin >> n && n ){
		int m;
		cin >> m;
		
		REP( i, n ){
			deg[i] = 0;
			REP( j, n ) dist[i][j] = INF;
			dist[i][i] = 0;
		}
		
		int total = 0;
		while( m-- ){
			int u, v, d;
			cin >> u >> v >> d; u--, v--;
			total += d;
			dist[u][v] = min(dist[u][v],d);
			dist[v][u] = dist[u][v];
			deg[u]++;
			deg[v]++;
		}
		
		
		REP( k, n ) REP( i, n ) REP( j, n )
			dist[i][j] = min( dist[i][j], dist[i][k]+dist[k][j] );
		
		int mask = 0;
		REP( i, n ) mask |= ((deg[i]&1)<<i);
		calc_now++;
		cout << total+solve(mask) << "\n";
	}
	
	return 0;
}

























