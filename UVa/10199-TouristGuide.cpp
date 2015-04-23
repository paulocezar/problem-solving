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
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 111
int N;
vector< int > gr[ MAXN ];
int low[MAXN], lbl[MAXN], parent[MAXN], dfsnum, rchild, root, arts;
bool art[MAXN];

void dfs( int u ){
	lbl[u] = low[u] = dfsnum++;
	REP( i, SIZE( gr[u] ) ){
		int v = gr[u][i];
		if( lbl[v] == -1 ){
			parent[v] = u;
			if( u == root ) rchild++;
			dfs( v );
			if( u != root && low[v] >= lbl[u] && !art[u] ) art[u] = true, arts++;
			low[u] = MIN( low[u], low[v] );
		} else if( v != parent[u] ) low[u] = MIN( low[u], lbl[v] );
	}
	if( u == root && rchild > 1 ) art[u] = true, arts++;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int R, u, v, tc = 1;
	string su, sv;
	bool first = true;
	
	while( cin >> N && N ){
		if( !first ) cout << "\n";
		first = false;
		
		map< string, int > id;
		REP( i, N ){ cin >> su; id[ su ] = i; gr[i].clear(); art[i] = false; lbl[i] = -1; }
		cin >> R;
		REP( i, R ){
			cin >> su >> sv;
			u = id[ su ], v = id[ sv ];
			gr[u].PB( v );
			gr[v].PB( u );
		}
		
		dfsnum = 0, arts = 0;
		REP( i, N ) if( lbl[i] == -1 ){
			root = i;
			rchild = 0;
			dfs( i );
		}
		
		cout << "City map #" << tc++ << ": " << arts << " camera(s) found\n";
		FORIT( loc, id ) if( art[loc->second] ) cout << loc->first << "\n"; 
	}
	
	return 0;
}




















