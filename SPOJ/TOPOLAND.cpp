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

int64 segt[1<<18];
int64 nvl, a[MAXN];

int from, to;
void build( int node, int lo, int hi ){
	if( lo == hi ){
		segt[node] = a[lo];
	} else {
		int mid = (lo+hi)>>1;
		int ls = (node<<1) + 1;
		int rs = ls+1;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
		segt[node] = max( segt[ls], segt[rs] );
	}
}

void update( int node, int lo, int hi ){
	if( lo == hi ) segt[node] = nvl;
	else {
		int mid = (lo+hi)>>1;
		int ls = (node<<1) + 1;
		int rs = ls+1;
		
		if( lo <= from && from <= mid ) update(ls, lo, mid );
		if( mid+1 <= from && from <= hi ) update(rs, mid+1, hi );
		segt[node] = max(segt[ls], segt[rs]);
	}
}

int64 query( int node, int lo, int hi ){
	if( from <= lo && hi <= to ) return segt[node];
	else{
		int mid = (lo+hi)>>1;
		int ls = (node<<1) + 1;
		int rs = ls+1;
		if( mid+1 > to ) return query( ls, lo, mid );
		if( mid < from ) return query( rs, mid+1, hi );
		return max( query(ls,lo,mid), query(rs,mid+1,hi) );
	}
}

int read_int(){
	
	char c = getchar_unlocked();
	while( (c != '-') && !isdigit(c) ) c = getchar_unlocked();
	
	int ans = 0, sig = 1;
	
	if( c == '-' ){ sig = -1; c = getchar_unlocked(); }
	
	while( !isdigit(c) ) c = getchar_unlocked();
	
	while( isdigit(c) ){
		ans = 10*ans + (c-'0');
		c = getchar_unlocked();
	}
	return (sig*ans);
}

int main( int argc, char* argv[] ){
	
	int t, N, Q;
	int64 M;
	
	t = read_int();
	
	REP( tc, t ){
		printf("Testcase %d:\n", tc );
		
		N = read_int();
		M = read_int();
		REP( i, N ) a[i] = read_int();
		
		Q = read_int();
		
		build( 0, 0, N-1 );
		
		char wut;
		while( Q-- ){
			wut = getchar_unlocked();
			while( (wut != 'A') && (wut != 'B') && (wut != 'C') ) wut = getchar_unlocked();
			
			if( wut == 'A' ){
				nvl = read_int();
				M += nvl;
			} else if( wut == 'B' ){
				from = read_int();
				nvl = read_int();
				update(0,0,N-1);
			} else {
				from = read_int();
				to = read_int();
				printf("%lld\n", abs(M-query(0,0,N-1)) );
			}
		}
		puts("");
	}
	
		
	return 0;
}

























