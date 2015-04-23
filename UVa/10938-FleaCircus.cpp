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

#define MAXN 5111

int N;
vector< int > gr[MAXN];
int P[MAXN], L[MAXN], parent[MAXN], path[MAXN], bsz;

void dfs( int u ){
	if( L[u] < bsz ) P[u] = 1;
	else if( !(L[u] % bsz) ) P[u] = parent[u];
	else P[u] = P[ parent[u] ];
	REP( i, SIZE(gr[u]) ) if( parent[ gr[u][i] ] == u ) dfs( gr[u][i] );
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int Q, u, v;
	while( cin >> N && N ){
		
		FOR( i, 1, N ){ gr[i].clear(); parent[i] = -1; }
		REP( i, N-1 ){ cin >> u >> v; gr[u].PB(v); gr[v].PB(u); }
		
		queue< int > q; q.push(1); parent[1] = 1; L[1] = 0; P[1] = 1;
		while( !q.empty() ){
			u = q.front(); q.pop();
			REP( i, SIZE(gr[u]) ){
				v = gr[u][i];
				if( parent[v] == -1 ){
					parent[v] = u;
					L[v] = L[u]+1;
					q.push( v );
				}
			}
		}
		if( N > 1 ){
			bsz = int( ceil(sqrt(L[u])) );
			dfs( 1 );
		}
		cin >> Q;
		while( Q-- ){
			cin >> u >> v;
			int x = u, y = v;
			while( P[x] != P[y] ){
				if( L[x] > L[y] ) x = P[x];
				else y = P[y];
			}
			while( x != y ){
				if( L[x] > L[y] ) x = parent[x];
				else y = parent[y];
			}
			
			bsz = 0;
			stack< int > aux;
			while( u != x ){
				path[bsz++] = u;
				u = parent[u];
			}
			path[bsz++] = x;
			while( v != x ){
				aux.push( v  ); v = parent[v];
			}
			while( !aux.empty() ){ path[bsz++] = aux.top(); aux.pop(); }
			if( bsz & 1 ) cout << "The fleas meet at " << path[bsz/2] << ".\n";
			else {
				u = path[bsz/2-1]; v = path[bsz/2];
				if( u > v ){ u ^= v; v ^= u; u ^= v; }
				cout << "The fleas jump forever between " << u << " and " << v << ".\n";
			}
		}
	}
	return 0;
}




















