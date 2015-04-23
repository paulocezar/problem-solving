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

#define MAXN 2222

int N;

int low[MAXN], lbl[MAXN], dfsnum;

vector<int> gr[MAXN];
bool stkd[MAXN];
int cur_comp, comp[MAXN];
stack< int > scc;

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
		cur_comp++;
		while( !scc.empty() && scc.top() != u ){
			comp[ scc.top() ] = cur_comp;
			stkd[ scc.top() ] = false;
			scc.pop(); 
		}
		scc.pop(); stkd[u] = false;
		comp[ u ] = cur_comp;
	}
}

int wut( char c, int v ){
	if( c == 'R' ) return 2*v;
	else return 2*v+1;
}

int ifnot( int x ){ return (x^1); }

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( cin >> N  && N ){
		REP( i, 2*N ){ gr[i].clear(); lbl[i] = -1; }
		
		char c1, c2;
		int v1, v2;
		
		REP( i, N ){
			cin >> c1 >> v1 >> c2 >> v2;
			int a = wut( c1, v1 );
			int b = wut( c2, v2 );
			gr[ ifnot(a) ].PB( b );
			gr[ ifnot(b) ].PB( a );
		}
		
		REP( i, 2*N ) if( lbl[i] == -1 )
			dfs( i );
		
		for( int i = 0; i < 2*N; i+=2 ) if( comp[i] == comp[i+1] ){ cout << "N\n"; goto hell; }
		cout << "Y\n";
		hell:;
		
	}
			
	return 0;
}

























