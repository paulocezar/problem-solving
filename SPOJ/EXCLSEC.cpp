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

#define MAXN 100100

int64 x[MAXN];
int64 segt[1<<18];

void build( int node, int lo, int hi ){
	if( lo == hi ){
		segt[node] = x[lo];
	} else {
		int ls = (node<<1) + 1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
		segt[node] = segt[ls] ^ segt[rs];
	}
}

int from, to;

int64 get( int node, int lo, int hi ){
	if( from <= lo && hi <= to ){
		return segt[node];
	} else {
		int ls = (node<<1 )+ 1;
		int rs = ls + 1;
		int mid = (lo+hi)>>1;
		if( mid+1 > to ) return get(ls,lo,mid);
		if( mid < from ) return get(rs,mid+1,hi);
		return (get(ls,lo,mid) ^ get(rs,mid+1,hi));
	}
}

int main( int argc, char* argv[] ){
	
	
	int N, T, Q;
	
	while( (scanf("%d %d %d", &N, &T, &Q ) == 3) && (N || T || Q) ){
		set< int64 > forbid;
		
		REP( i, N ){ scanf("%lld", x+i); forbid.insert( x[i] ); }
		build(0,0,N-1);
		while( T-- ){
			scanf("%d %d", &from, &to );
			from--; to--;
			forbid.insert( get(0,0,N-1) );
		}
		
		while( Q-- ){
			int64 val; scanf("%lld", &val );
			if( forbid.count(val) ) puts("N");
			else puts("Y");
		}
		puts("-");
		
	}
			
	return 0;
}

























