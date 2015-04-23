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
vector< int > gr[MAXN];
int low[MAXN], lbl[MAXN], parent[MAXN], dfsnum, rchild;
bool art[MAXN];

void dfs( int u ){
	low[u] = lbl[u] = dfsnum++;
	REP( i, SIZE(gr[u]) ){
		int v = gr[u][i];
		if( lbl[ v ] == -1 ){
			parent[v] = u;
			if( u == 0 ) rchild++;
			dfs( v );
			if( lbl[u] > 0 && low[v] >= lbl[u] ) art[u] = true;
			low[u] = MIN( low[u], low[v] );
		} else if( v != parent[u] ) low[u] = MIN( low[u], lbl[v] );
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	string line;
	parent[0] = -1;
	int u, v;
	
	while( cin >> N && N ){
		
		REP( i, N ){ gr[i].clear(); lbl[i] = -1; art[i] = false; }
		
		cin.ignore();
		while( getline(cin, line) && line != "0" ){
			istringstream in( line );
			in >> u; u--;
			while( in >> v ){ v--;
				gr[u].PB( v );
				gr[v].PB( u );
			}
		}
		dfsnum = 0, rchild = 0;
		dfs( 0 );
		if( rchild > 1 ) art[0] = true;
	
		int arts = 0;
		REP( i, N ) if( art[i] ) arts++;	
		cout << arts << "\n";
		
	}
	
	return 0;
}




















