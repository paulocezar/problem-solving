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

#define MAXN 20000

int segt[1<<16], a[MAXN];

void build( int node, int lo, int hi ){
	if( lo == hi ) segt[node] = a[lo];
	else {
		int mid = (lo+hi)>>1;
		int ls = (node<<1)+1;
		int rs = ls+1;
		build(ls,lo,mid);
		build(rs,mid+1,hi);
		segt[node] = (segt[ls]&segt[rs]);
	}
}

int from, to;
int get( int node, int lo, int hi ){
	if( from <= lo && hi <= to ) return segt[node];
	else{
		int mid = (lo+hi)>>1;
		int ls = (node<<1)+1;
		int rs = ls+1;
		if( mid+1 > to ) return get(ls,lo,mid);
		if( mid < from ) return get(rs,mid+1,hi);
		return (get(ls,lo,mid)&get(rs,mid+1,hi));
	}
}

int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

int main( int argc, char* argv[] ){
	
	int t;
	
	t = next_int();
	while( t-- ){
		int N, K;
		
		N = next_int();
		K = next_int();
		REP( i, N ) a[i] = next_int();
		
		if( 2*K >= N ){
			int elm = a[0];
			FOR( i, 1, N-1 ) elm &= a[i];
			REP( i, N ){
				if( i ) putchar(' ');
				printf("%d", elm );
			}
			puts("");
		} else {
			build(0,0,N-1);
			int lo, hi;
			REP( i, N ){
				if( i ) putchar(' ');
				lo = (((i-K)%N)+N)%N;
				hi = (i+K)%N;
				if( lo <= hi ){
					from = lo, to = hi;
					printf("%d", get(0,0,N-1) );
				} else {
					from = 0, to = hi;
					int res = get(0,0,N-1);
					from = lo, to = N-1;
					res &= get(0,0,N-1);
					printf("%d", res );
				}
			}
			puts("");			
		}
		
	}
	
	return 0;
}

























