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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

inline int next_int() {
	int n = 0, neg = 1;
	char c = getchar_unlocked();
	if( c == EOF ) exit(0);
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
		if( c == EOF ) exit(0);
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return neg*n;
}

#define MAXN 100001
vector< int > gr[MAXN];

int parent[MAXN], treesize[MAXN];
int chain[MAXN], chainleader[MAXN], chainpos[MAXN], vertexat[MAXN];
int cur_chain, pos;

int segt[1<<18];

void explore( int u ){
	treesize[u] = 1;
	int v;
	REP( i, SIZE(gr[u]) ){
		v = gr[u][i];
		if( parent[v] == -1 ){
			parent[v] = u;
			explore(v);
			treesize[u] += treesize[v];
		}
	}
}

void decompose( int u, bool light = true ){
	if( light ){
		++cur_chain;
		chainleader[cur_chain] = u;
	}
	chain[u] = cur_chain;
	chainpos[u] = pos;
	vertexat[pos++] = u;
	
	int v, mx = -1;
	REP( i, SIZE(gr[u]) ){
		v = gr[u][i];
		if( parent[v] == u && (mx == -1 || treesize[mx] < treesize[v]) )
			mx = v;
	}
	if( mx != -1 ) decompose( mx, false );
	REP( i, SIZE(gr[u]) ){
		v = gr[u][i];
		if( parent[v] == u && v != mx ) decompose( v );
	}	
}

int from, to;
void update( int node, int lo, int hi ){
	if( lo == hi ){
		if( segt[node] ) segt[node] = 0;
		else segt[node] = vertexat[ lo ];
	} else {
		int ls = (node<<1)+1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		
		if( lo <= from && from <= mid ) update(ls,lo,mid);
		if( mid+1 <= from && from <= hi ) update(rs,mid+1,hi);
		
		if( segt[ls] ) segt[node] = segt[ls];
		else segt[node] = segt[rs];
	}
}

int query( int node, int lo, int hi ){
	if( from <= lo && hi <= to ){
		return segt[node];
	} else {
		int ls = (node<<1)+1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		int q1 = 0, q2 = 0;
		
		if( mid >= from ) q1 = query(ls,lo,mid);
		if( mid+1 <= to ) q2 = query(rs,mid+1,hi);
		
		if( q1 ) return q1;
		return q2;
	}
}

int rootcolor;

int query( int v ){
	int ans = -1;
	while( v != 1 ){
		if( chainleader[chain[v]] == v ){
			from = chainpos[v];
			to = chainpos[v];
			int ax = query(0,0,pos);
			if( ax ) ans = ax;
			v = parent[v];
		} else {
			from = chainpos[ chainleader[ chain[v] ] ];
			to = chainpos[ v ];
			int ax = query(0,0,pos);
			if( ax ) ans = ax;
			v = chainleader[ chain[v] ];
		}
	}
	if( rootcolor ) return 1;
	return ans;
}


int main( int argc, char* argv[] ){
	
	int N = next_int();
	int Q = next_int();
	int u, v;
	
	FOR( i, 1, N ){ gr[i].clear(); parent[i] = -1; }
	//FILL( segt, 0 );
	
	REP( i, N-1 ){
		u = next_int(); v = next_int();
		gr[u].PB( v );
		gr[v].PB( u );
	}
	parent[1] = 0;
	explore(1); parent[1] = -1;
	cur_chain = -1; pos = 0;
	decompose( 1 ); pos--;
	rootcolor = 0;
	
	while( Q-- ){
		u = next_int();
		v = next_int();
		if( u ){
			printf("%d\n", query(v) );
		} else {
			if( v == 1 ) rootcolor = !rootcolor;
			from = chainpos[v];
			update(0,0,pos);
		}
	}	
	
	return 0;
}




















