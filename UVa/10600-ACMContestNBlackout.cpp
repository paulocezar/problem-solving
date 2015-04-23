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

#define MAXN 111
int pa[MAXN], rk[MAXN];

void make( int N ){ FOR( i, 1, N ) pa[i] = i, rk[i] = 0; }

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
	pa[py] = px;
	return true;
}

struct edge_t{
	int u, v, c;
	edge_t( int uu = 0, int vv = 0, int cc = 0 ) : u(uu), v(vv), c(cc) {}
	bool operator < ( const edge_t& e ) const {
		return c < e.c;
	}
};

vector< edge_t > edge;
vector< int > tree_edge;

int mst( int bad ){
	if( bad == -1 ) tree_edge.clear();
	int ans = 0;
	int add = 0;
	REP( i, SIZE(edge) ) if( i != bad && fUnion(edge[i].u, edge[i].v) ){
		if( bad == -1 ) tree_edge.PB( i );
		ans += edge[i].c;
		add++;
	}
	if( bad != -1 && add != SIZE(tree_edge) ) return INF;
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, N, M;
	cin >> t;
	while( t-- ){
		
		cin >> N >> M;
		edge.resize(M);
		REP( i, M ) cin >> edge[i].u >> edge[i].v >> edge[i].c;
		sort( ALL(edge) );
		
 		make(N);
		int best = mst( -1 ), sbest = INF;
		REP( i, SIZE(tree_edge) ){
			make(N);
			sbest = MIN( sbest, mst(tree_edge[i]) );
		}
		cout << best << " " << sbest << "\n";
	}
	
	return 0;
}




















