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

inline int64 next_int64() {
	int64 n = 0, neg = 1;
	char c = getchar_unlocked();
	if( c == EOF ) exit(0);
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
		if( c == EOF ) exit(0);
	}
	while ('0' <= c && c <= '9') {
		n = (n * 10LL) + c - '0';
		c = getchar_unlocked();
	}
	return neg*n;
}

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

#define MAXN 100000
#define LGMN 17

int64 a[MAXN];

bool ones[1<<(LGMN+1)];
int64 sum[1<<(LGMN+1)];

void build( int node, int lo, int hi ){
	if( lo == hi ){
		sum[node] = a[lo];
		if( a[lo] == 1LL ) ones[node] = true;
		else ones[node] = false;
	} else {
		int ls = (node<<1) + 1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
		sum[node] = sum[ls] + sum[rs];
		ones[node] = (ones[ls] && ones[rs]);
	}
}

int from, to;
void update( int node, int lo, int hi ){
	if( lo == hi ){
		a[lo] = int64( sqrt( (long double)a[lo] ) );
		sum[node] = a[lo];
		
		if( a[lo] == 1LL ) ones[node] = true;
		else ones[node] = false;
		return;
	}
	
	int ls = (node<<1) + 1;
	int rs = ls + 1;
	int mid = (lo+hi)>>1;
	if( mid >= from && !ones[ls] ) update( ls, lo, mid );
	if( mid+1 <= to && !ones[rs] ) update( rs, mid+1, hi );
	ones[node] = (ones[ls] && ones[rs]);
	sum[node] = sum[ls] + sum[rs]; 
}

int64 query( int node, int lo, int hi ){
	if( from <= lo && hi <= to ) return sum[node];
	int ls = (node<<1) + 1;
	int rs = ls + 1;
	int mid = (lo+hi)>>1;
	int64 ans = 0;
	if( mid >= from ) ans += query( ls, lo, mid );
	if( mid+1 <= to ) ans += query( rs, mid+1, hi );
	return ans;
}

int main( int argc, char* argv[] ){
	
	int N, M, wut, tc = 1;
	
	while( true ){

		N = next_int();
		REP( i, N ) a[i] = next_int64();
		
		printf("Case #%d:\n", tc++ );
		build( 0, 0, N-1 );
		
		M = next_int();
		while( M-- ){
			wut = next_int();
			from = next_int();
			to = next_int();
			from--, to--;
			
			if( from > to ){
				from ^= to; to ^= from; from ^= to;
			}
			
			if( wut ) printf("%lld\n", query(0, 0, N-1) );
			else update(0, 0, N-1);
		}
		puts("");
	}
	
	return 0;
}




















