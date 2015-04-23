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

#define MAXN 25

int N, M;
int low[MAXN], lbl[MAXN], dfsnum;
bool gr[MAXN][MAXN], instack[MAXN];
vector< vector<int> > comps;
stack< int > scc;
string name[MAXN];

void dfs( int u ){
	lbl[u] = low[u] = dfsnum++;
	scc.push( u ); instack[u] = true;
	REP( v, N ) if( gr[u][v] ){
		if( lbl[v] == -1 ) dfs( v );
		if( instack[v] ) low[u] = MIN( low[u], low[v] );
	}
	if( low[u] == lbl[u] ){
		while( !scc.empty() && scc.top() != u ){
			cout << name[ scc.top() ] << ", ";
			instack[ scc.top() ] = false;
			scc.pop(); 
		}
		cout << name[ u ] << "\n"; scc.pop(); instack[u] = false;
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int tc = 1;
	bool first = true;
	FILL( instack, false );
	string su, sv;
	
	while( (cin >> N >> M) && (N+M) ){
		if( !first ) cout << "\n";
		first = false;
		
		REP( i, N ){ lbl[i] = -1; REP( j, N ) gr[i][j] = false; }
		map< string, int > id; int cid = 0;
		
		while( M-- ){
			cin >> su >> sv;
			if( id.find( su ) == id.end() ){ name[cid] = su; id[ su ] = cid++; }
			if( id.find( sv ) == id.end() ){ name[cid] = sv; id[ sv ] = cid++; }
			gr[ id[su] ][ id[sv] ] = true;
		}
		
		dfsnum = 0;
		cout << "Calling circles for data set " << tc++ << ":\n";
		REP( i, N ) if( lbl[i] == -1 ) dfs( i );
		
	}
	
	return 0;
}




















