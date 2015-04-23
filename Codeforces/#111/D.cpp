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

#define MAXN 100000

int pa[MAXN], rk[MAXN], lst[MAXN], cst[MAXN];
char wut[MAXN];

int find( int x ){
	int y = x, ax;
	while( y != pa[y] ) y = pa[y];
	while( x != y ){
		ax = pa[x];
		pa[x] = y;
		x = ax;
	}
	return y;
}

struct edge_t{
	int u, v, c, id;
	edge_t( int x = 0, int y = 0, int z = 0, int w = 0 ) : u(x-1), v(y-1), c(z), id(w) {}
	bool operator < ( const edge_t& e ) const {
		return c < e.c;
	}
};


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n, m, x, y;
	cin >> n >> m;
	
	REP( i, n ) pa[i] = i, rk[i] = 0;
	
	vector< edge_t > edge;
	REP( i, m ){
		cin >> x[i] >> y[i] >> z[i];
		edge.PB( edge_t(x[i],y,z[i],i) );
	}
	sort( ALL(edge) );
	
	
	map< int, int > repeated;
	
	REP( i, m ){
		int px = find(edge[i].u);
		int py = find(edge[i].v);
		if( px != py ){
			
			if( rk[px] < rk[py] ) swap( px, py );
			pa[py] = px;
			if( rk[px] == rk[py] ) rk[px]++;
			lst[px] = i;
			if( repeated.find(edge[i].c) == repeated.end() ) 
				repeated[ edge[i].c ] = 0;
			
		} else if( edge[i].c == edge[ lst[px] ].c )
			repeated[ edge[i].c ]++;
		
	}
	
	REP( i, m ){
		if( repeated.find(cst[i]) == repeated.end() ) cout << "none\n";
		else if( repeated[cst[i]] && !() ) cout << "at least one\n";
		else cout << "any\n";
	}
	
	return 0;
}

























