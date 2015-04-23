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

#define MAXN 100000
vector< vector<int> > gr;
int parent[MAXN], low[MAXN], lbl[MAXN];

int dfsnum, bridges;

void dfs( int u ){
	lbl[u] = low[u] = dfsnum++;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		int v = gr[u][i];
		if( lbl[v] == -1 ){
			parent[v] = u;
			dfs( v );
			
			if( low[u] > low[v] ) low[u] = low[v];
			if( low[v] == lbl[v] ) bridges++;
			
		} else if( v != parent[u] ) low[u] = min( low[u], lbl[v] );
	}
}

set< pair<int,int> > seen;

void show( int u ){
	lbl[u] = 0;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		int v = gr[u][i];
		if( lbl[v] == -1 ){
			cout << u+1 << " " << v+1 << "\n";
			seen.insert( MP(min(u,v), max(u,v)) );
			show( v );			
		} else if( seen.insert( MP(min(u,v),max(u,v))).second  ) cout << u+1 << " " << v+1 << "\n";
	}
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n, m, u, v;
	
	cin >> n >> m;
	gr.resize(n);
	REP( i, n ){ gr[i].clear(); lbl[i] = low[i] = -1; parent[i] = -1; }
	
	REP( i, m ){
		cin >> u >> v; u--, v--;
		gr[u].PB( v );
		gr[v].PB( u );
	}
	
	dfsnum = 0, bridges = 0; dfs( 0 );
	if( bridges ) cout << "0" << "\n";
	else{ REP( i, n ) lbl[i] = -1; show( 0 ); }
	
	
	return 0;
}




















