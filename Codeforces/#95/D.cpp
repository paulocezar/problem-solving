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

#define MAXN 3003

vector< int > gr[MAXN];

char seen[MAXN];
int ord[MAXN];
int dist[MAXN];

void dfs( int u, int parent = -1, int dpth = 0 ){
	seen[u] = 1;
	ord[dpth] = u;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ) if( !seen[ gr[u][i] ] ){
		
		dfs( gr[u][i], u, dpth+1 );
	
	} else if( gr[u][i] != parent && seen[gr[u][i]] != 2 ){
		
		int aux = dpth;
		while( aux >= 0 ){
			dist[ ord[aux] ] = 0;
			if( ord[aux] == gr[u][i] ) break;
			aux--;
		}
		
	}
	seen[u] = 2;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	for( int i = 1; i <= n; i++ ){
		gr[i].clear();
		seen[i] = 0;
		dist[i] = INF;
	}
	
	for( int i = 0; i < n; i++ ){
		int u, v;
		cin >> u >> v;
		gr[u].PB( v );
		gr[v].PB( u );
	}
	
	dfs( 1 );
	queue< int > q;
	for( int i = 1; i <= n; i++ ) if( dist[i] == 0 ) q.push( i );
	
	while( !q.empty() ){
		
		int u = q.front(); q.pop();
		for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ) if( dist[u]+1 < dist[gr[u][i]] ){
			dist[gr[u][i]] = dist[u]+1;
			q.push( gr[u][i] );
		}
		
	}
	
	cout << dist[1];
	for( int i = 2; i <= n; i++ ) cout << " " << dist[i];
	cout << "\n";
	
	return 0;
}




















