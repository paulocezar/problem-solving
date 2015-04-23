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

#define MAXN 222
int N;
vector< int > gr[MAXN];
bool seen[MAXN];

bool eulerian(){
	queue< int > q; q.push( 0 ); seen[0] = true;
	int u, v, vis = 0;
	while( !q.empty() ){
		u = q.front(); q.pop();
		vis++;
		REP( i, SIZE(gr[u]) ){
			v = gr[u][i];
			if( !seen[v] ){
				q.push( v );
				seen[v] = true;
			}
		}
	}
	if( vis != N ) return false;
	REP( i, N ) if( SIZE(gr[i]) & 1 ) return false;
	return true;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int M, u, v;
	while( cin >> N >> M ){
		REP( i, N ){ gr[i].clear(); seen[i] = false; }
		REP( i, M ){
			cin >> u >> v;
			gr[u].PB( v );
			gr[v].PB( u );
		}
		if( eulerian() ) cout << "Possible\n";
		else cout << "Not Possible\n";
	}
	return 0;
}




















