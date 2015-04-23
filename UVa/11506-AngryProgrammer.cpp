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
vector< int > gr[MAXN];
int cap[MAXN][MAXN], parent[MAXN], flow;
int s, t, N;

bool augment(){
	REP( i, N ) parent[i] = -1;
	int u, v;
	queue< int > q;
	q.push( s ); parent[s] = s;
	while( !q.empty() ){
		u = q.front(); q.pop();
		REP( i, SIZE(gr[u]) ){
			v = gr[u][i];
			if( parent[v] == -1 && cap[u][v] > 0 ){
				parent[v] = u;
				if( v == t ) goto calc_flow;
				q.push( v );
			}
		}
	}
	return false;
calc_flow:
	parent[s] = -1; flow = INF;
	v = t;
	while( parent[v] != -1 ){
		flow = MIN( flow, cap[parent[v]][v] );
		v = parent[v];
	}
	v = t;
	while( parent[v] != -1 ){
		cap[parent[v]][v] -= flow;
		cap[v][parent[v]] += flow;
		v = parent[v];
	}
	return true;
}

int maxFlow(){
	int ans = 0;
	while( augment() ){
		ans += flow;
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int u, v, c, M;
	
	while( (cin >> N >> M ) && (N+M) ){
		FILL( cap, 0 );
		
		REP( i, 2*N ) gr[i].clear();
		gr[0].PB( 1 ); gr[1].PB( 0 );
		gr[2*N-2].PB( 2*N-1 ); gr[2*N-1].PB(2*N-2);
		cap[0][1] = cap[2*N-2][2*N-1] = INF;
		REP( i, N-2 ){
			cin >> u >> c; u--;
			cap[ 2*u ][ 2*u+1 ] = c;
			gr[2*u].PB( 2*u+1 );
			gr[2*u+1].PB( 2*u );
		}
		N = 2*N;
		s = 0, t = N-1;
		REP( i, M ){
			cin >> u >> v >> c; u--, v--;
			gr[2*u+1].PB(2*v); gr[2*v+1].PB(2*u);
			gr[2*v].PB(2*u+1); gr[2*u].PB(2*v+1);
			cap[2*u+1][2*v] = cap[2*v+1][2*u] = c;
		}
		cout << maxFlow() << "\n";
	}
	
	return 0;
}




















