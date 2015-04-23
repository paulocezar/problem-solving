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

#define MAXN 100000
#define LGMN 17

int segt[1<<(LGMN+1)][3];
char lazy[1<<(LGMN+1)];

void build( int node, int lo, int hi ){
	if( lo == hi ){
		segt[node][0] = 1;
		segt[node][1] = 0;
		segt[node][2] = 0;
	} else {
		int mid = (lo+hi)>>1;
		int ls = (node<<1)+1;
		int rs = ls+1;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
		segt[node][0] = segt[ls][0]+segt[rs][0];
		segt[node][1] = segt[ls][1]+segt[rs][1];
		segt[node][2] = segt[ls][2]+segt[rs][2];	
	}
	lazy[node] = 0;
}

int from, to;

void push( int node, bool fl ){
	if( !lazy[node] ) return;
	if( fl ){
		int ls = (node<<1)+1;
		int rs = ls+1;
		lazy[ls] = (lazy[ls]+lazy[node])%3;
		lazy[rs] = (lazy[rs]+lazy[node])%3;
	}
	while( lazy[node] ){
		int nzz = segt[node][2];
		segt[node][2] = segt[node][1];
		segt[node][1] = segt[node][0];
		segt[node][0] = nzz;
		lazy[node]--;
	}
}

void update( int node, int lo, int hi ){
	
	if( from <= lo && hi <= to ){
		lazy[node] = (lazy[node]+1)%3;
		push( node, lo != hi );
	} else {
		int mid = (lo+hi)>>1;
		int ls = (node<<1)+1;
		int rs = ls+1;
		
		push( node, lo != hi );
		push( ls, lo != mid );
		push( rs, mid+1 != hi );
		
		if( mid >= from )
			update( ls, lo, mid );
		
		if( mid+1 <= to )
			update( rs, mid+1, hi );
		
		segt[node][0] = segt[ls][0]+segt[rs][0];
		segt[node][1] = segt[ls][1]+segt[rs][1];
		segt[node][2] = segt[ls][2]+segt[rs][2];
	}
}

int get( int node, int lo, int hi ){
	push( node, lo != hi );
	if( from <= lo && hi <= to )
		return segt[node][0];
	
	int mid = (lo+hi)>>1;
	int ls = (node<<1)+1;
	int rs = ls+1;
	
	int ans = 0;
	if( mid >= from ) ans += get( ls, lo, mid );
	if( mid+1 <= to ) ans += get( rs, mid+1, hi );
	
	return ans;
}

inline int next_int() {
	int n = 0;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) {
		c = getchar_unlocked();
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return n;
}

int main( int argc, char* argv[] ){
	
	int N, Q, wut;
	
	N = next_int();
	Q = next_int();
	build( 0, 0, N-1 );
	while( Q-- ){
		wut = next_int();
		from = next_int();
		to = next_int();
		
		if( wut ) printf("%d\n", get( 0, 0, N-1 ) );
		else update( 0, 0, N-1 );
	}
	
	return 0;
}




















