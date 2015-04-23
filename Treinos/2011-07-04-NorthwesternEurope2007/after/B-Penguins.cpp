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

void connect( int a, int b );

#define MAXN 110

int N;
int graph[ 2*MAXN ][ 2*MAXN ], gr[ 2*MAXN ], jump[MAXN];
int bcap[ 2*MAXN ][ 2*MAXN ], cap[ 2*MAXN ][ 2*MAXN ], parent[ 2*MAXN ];
double x[MAXN], y[MAXN];
char vis[ 2*MAXN ];
int sink, flow;

void augment(){
	
	FILL( vis, 0 );
	
	queue< int > q;
	q.push( 0 ); vis[0] = 1;
	int u; 
	while( !q.empty() ){
		u = q.front(); q.pop();
		REP( i, gr[u] ) if( !vis[ graph[u][i] ] && cap[ u ][ graph[u][i] ] > 0 ){
			parent[ graph[u][i] ] = u;
			if( graph[u][i] == 2*sink ) goto calc_flow;
			vis[ graph[u][i] ] = 1;
			q.push( graph[u][i] );
		}
	}
	return;
calc_flow:
	u = 2*sink;
	while( parent[u] != -1 ){
		flow = MIN( flow, cap[ parent[u] ][ u ] );
		u = parent[u];
	}
}

int max_flow(){
	int ans = 0;
	REP( i, 2*N+2 ) REP( j, 2*N+2 ) cap[i][j] = bcap[i][j];
	while( true ){
		flow = INF;
		augment();
		
		if( flow == INF ) break;
		int v = 2*sink;
		while( parent[v] != -1 ){
			cap[ parent[v] ][ v ] -= flow;
			cap[ v ][ parent[v] ] += flow;
			v = parent[v];
		}
		ans += flow;
	}
	return ans;	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	double D;
	parent[0] = -1;
	
	cin >> t;
	while( t-- ){
		
		cin >> N >> D; D *= D;
		FILL( gr, 0 );
		
		int penguins = 0;
		int cantjump = 0;
		REP( i, 2*N+2 ) REP( j, 2*N+2 ) bcap[i][j] = 0;
		
		FOR( i, 1, N ){
			cin >> x[i] >> y[i] >> bcap[0][2*i] >> bcap[2*i][ 2*i+1 ];

			if( bcap[0][2*i] > bcap[2*i][2*i+1] ) cantjump++;
			penguins += bcap[0][2*i];
		}
		
		if( cantjump >= 2 ) cout << "-1\n";
		else {
			
			FOR( i, 1, N ){
				connect( 0, 2*i ); 
				connect( 2*i, 2*i+1 );
				FOR( j, i+1, N ) if( (SQR(x[i]-x[j])+SQR(y[i]-y[j])) < D+EPS ){
					connect( 2*i+1, 2*j );
					connect( 2*j+1, 2*i );
					bcap[ 2*i+1 ][ 2*j ] = bcap[ 2*j+1 ][ 2*i ] = INF;
				}		
			}
			
			bool print = false;
			sink = 1;
			while( sink <= N ){
				if( max_flow() == penguins ){
					if( print ) cout << " ";
					else print = true;
					cout << sink-1;
				}
				sink++;
			}
			if( !print ) cout << "-1\n";
			else cout << "\n";		
		}	
	}
	
	return 0;
}

void connect( int a, int b ){
	graph[ a ][ gr[ a ]++ ] = b;
	graph[ b ][ gr[ b ]++ ] = a;
}



















