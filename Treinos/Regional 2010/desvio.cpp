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

#define MAXN 1001

int low[MAXN], lbl[MAXN], parent[MAXN], dfsnum, components;

bool stkd[MAXN];
stack< int > scc;

namespace directed {
	vector<int> gr[MAXN];
	void dfs( int u ){
		lbl[u] = low[u] = dfsnum++;
		scc.push( u );
		stkd[u] = true;
		int v;
		for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
			v = gr[u][i];
			if( lbl[v] == -1 ) dfs( v );
			if( stkd[v] ) low[u] = min( low[u], low[v] );
		}
		if( low[u] == lbl[u] ){
			components++;
			while( !scc.empty() && scc.top() != u ){
				stkd[ scc.top() ] = false;
				scc.pop(); 
			}
			scc.pop(); stkd[u] = false;
		}
	}
};

namespace undirected {
	vector<int> gr[MAXN];
	vector< pair<int,int> > brid;
	
	void dfs( int u ){
		lbl[u] = low[u] = dfsnum++;
		for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
			int v = gr[u][i];
			if( lbl[v] == -1 ){
				parent[v] = u;
				dfs( v );
				if( low[v] > lbl[u] )
					brid.push_back( make_pair(u, v) );
				low[u] = min( low[u], low[v] );
			} else if( v != parent[u] ) low[u] = min( low[u], lbl[v] );
		}
	}
	
};

int cantbe[MAXN][MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	FILL( cantbe, -1 );
	int cur = -1;
	
	int N, M;
	int u, v, t;
hell:	
	while( cin >> N >> M ){
		cur++;
		REP( i, N ){ directed::gr[i].clear(); undirected::gr[i].clear(); }
		
		cin >> u >> v >> t; M--;
		set< pair<int,int> > und;
		
		REP( i, M ){
			cin >> u >> v >> t; u--, v--;
			directed::gr[u].PB( v );
			undirected::gr[u].PB( v );
			undirected::gr[v].PB( u );
			if( t == 2 ) directed::gr[v].PB( u );
			else cantbe[u][v] = cantbe[v][u] = cur;
		}
		
		REP( i, N ) low[i] = lbl[i] = -1;
		components = 0; dfsnum = 0;
		
		while( !scc.empty() ) scc.pop();
		FILL( stkd, false );
		REP( i, N ) if( lbl[i] == -1 ) directed::dfs(i);
		if( components == 1 ) cout << "-\n";
		else {
			REP( i, N ) low[i] = lbl[i] = -1, parent[i] = -1;
			dfsnum = 0;
			
			undirected::brid.clear();
			undirected::dfs(0);
			REP( i, N ) if( lbl[i] == -1 ){ cout << "*\n"; goto hell; }
			
			REP( i, SIZE(undirected::brid) ){
				if( cantbe[undirected::brid[i].first][undirected::brid[i].second] == cur )
				{ cout << "2\n"; goto hell; }
			}
			
			cout << "1\n";
		}
	}
	
	return 0;
}




















