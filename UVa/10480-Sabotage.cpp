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

#define MAXN 55
int N, M;
vector< int > gr[MAXN];
int cap[MAXN][MAXN], parent[MAXN];

bool augment(){
	FILL( parent, -1 );
	queue< int > q; int u, v, flow;
	parent[1] = 1; q.push( 1 );
	while( !q.empty() ){
		u = q.front(); q.pop();
		REP( i, SIZE(gr[u]) ){
			v = gr[u][i];
			if( parent[v] == -1 && cap[u][v] > 0 ){
				parent[v] = u;
				if( v == 2 ) goto calc_flow;
				q.push( v );
			}
		}
	}
	return false;
calc_flow:
	parent[1] = -1;
	v = 2; flow = INF;
	while( parent[v] != -1 ){
		flow = MIN( flow, cap[parent[v]][v] );
		v = parent[v];
	}
	
	v = 2;
	while( parent[v] != -1 ){
		cap[parent[v]][v] -= flow;
		cap[v][parent[v]] += flow; 
		v = parent[v];
	}
	
	return true;
}
void showcut(){
	FOR( i, 1, N ) if( parent[i] != -1 ){
		REP( j, SIZE(gr[i]) ){
			int v = gr[i][j];
			if( parent[v] == -1 ) cout << i << " " << v << "\n";
		}
	}	
}

void maxflow(){
	while( augment() );
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int u, v, c;
	
	while( (cin >> N >> M) && (N+M) ){
		FILL( cap, 0 );
		FOR( i, 1, N ) gr[i].clear();
		REP( i, M ){
			cin >> u >> v >> c;
			cap[u][v] = cap[v][u] = c;
			gr[u].PB( v );
			gr[v].PB( u );
		}
		maxflow();
		showcut(); cout << "\n";
	}
	
	return 0;
}




















