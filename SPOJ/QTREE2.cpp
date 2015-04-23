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
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct edge_t{
	int v, c;
	edge_t( int vv = 0, int cc = 0 ) : v(vv), c(cc) {}
};

#define MAXN 10001
int N, parent[MAXN], L[MAXN], dis[MAXN];
int dp[15][MAXN];

vector< edge_t > gr[MAXN];

int lca( int u, int v ){
	if( L[u] < L[v] ){
		u ^= v; v ^= u; u ^= v; 
	}
	int lg;
	for( lg = 1; (1<<lg) <= L[u]; lg++ );
	lg--;
	
	for( int i = lg; i >= 0; i-- )
		if( L[u] - (1<<i) >= L[v] )
			u = dp[i][u];
	if( u == v ) return u;
	for( int i = lg; i >= 0; i-- )
		if( dp[i][u] != -1 && dp[i][u] != dp[i][v] )
			u = dp[i][u], v = dp[i][v];
	return parent[u];
}

int kth( int k, int u ){
	while( k > 0 ){
		int lg = 0;
		while( (1<<lg) <= k ) lg++;
		lg--;
		u = dp[lg][u];
		k -= (1<<lg);
	}
	return u;
} 

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t, u, v, c, k;
	string wut;
	
	cin >> t;
	while( t-- ){
		cin >> N;
		FOR( i, 1, N ){ parent[i] = -1; gr[i].clear(); }
		REP( i, N-1 ){
			cin >> u >> v >> c;
			gr[u].PB( edge_t(v, c) );
			gr[v].PB( edge_t(u, c) );
		}
		
		L[1] = 0; dis[1] = 0; parent[1] = 1;
		queue< int > q;
		q.push( 1 );
		while( !q.empty() ){
			u = q.front(); q.pop();
			REP( i, SIZE(gr[u]) ){
				v = gr[u][i].v;
				c = gr[u][i].c;
				if( parent[v] == -1 ){
					parent[v] = u;
					dis[v] = dis[u]+c;
					L[v] = L[u] + 1;
					q.push(v);
				}
			}
		}
		parent[1] = -1;
		
		for( int lg = 0; (1<<lg) < N; lg++ )
			FOR( i, 1, N ) dp[lg][i] = -1;
			
		FOR( i, 1, N ) dp[0][i] = parent[i];
		
		for( int lg = 1; (1<<lg) < N; lg++ )
			FOR( i, 1, N ) if( dp[lg-1][i] != -1 )
				dp[lg][i] = dp[lg-1][dp[lg-1][i]];
		
	qry:
		cin >> wut;
		if( wut[1] != 'O' ){
			cin >> u >> v;
			int x = lca(u,v);
			if( wut[0] == 'D' ){
				cout << dis[u]+dis[v]-2*dis[x] << "\n";
			} else {
				cin >> k; k--;
				
				if( L[u]-L[x] >= k ){
					cout << kth( k, u ) << "\n"; 
				} else {
					k -= (L[u]-L[x]);
					k = L[v]-L[x]-k;
					cout << kth( k, v ) << "\n";
				} 
			}

			goto qry;
		}
		cout << "\n";
	}
	return 0;
}


/*
				1
		2			3
	4		5			6
*/









