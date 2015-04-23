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
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXM 200001
int pa[MAXM], rk[MAXM];

int find( int x ){
	int a = x, ax;
	while( pa[a] != a ) a = pa[a];
	while( pa[x] != a ){
		ax = pa[x];
		pa[x] = a;
		x = ax;
	}
	return a;
}

bool fUnion( int x, int y ){
	int px = find(x);
	int py = find(y);
	if( px == py ) return false;
	if( rk[px] < rk[py] ){ px ^= py; py ^= px; px ^= py; }
	if( rk[px] == rk[py] ) rk[px]++;
	pa[ py ] = px;
	return true;
}

struct edge_t{
	int u, v, c;
	edge_t( int uu = 0, int vv = 0, int cc = 0 ) : u(uu), v(vv), c(cc) {}
	bool operator < ( const edge_t& e ) const {
		return c < e.c;
	} 
};

edge_t edge[MAXM];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int M, N;
	
	while( (cin >> M >> N) && (M+N) ){
		REP( i, M ) pa[i] = i, rk[i] = 0; 
		REP( i, N ) cin >> edge[i].u >> edge[i].v >> edge[i].c;
		sort( edge, edge+N );
		
		int ans = 0;
		REP( i, N ) if( !fUnion( edge[i].u, edge[i].v ) )
			ans += edge[i].c;
		cout << ans << "\n";
	}
	
	return 0;
}




















