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

int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ){
		if( c == 'b' ) return -1;
		c = getchar_unlocked();
	}
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

#define MAXSHIPS 100000
int segt[1<<18];

int K, M;
void build( int node, int lo, int hi ){
	if( lo == hi ) segt[node] = K;
	else{
		int mid = (lo+hi)>>1;
		int ls = (node<<1)+1;
		int rs = ls+1;
		build(ls,lo,mid);
		build(rs,mid+1,hi);
		segt[node] = max(segt[ls],segt[rs]);
	}
}

int cur_box, cur_cap, v;
void get( int node, int lo, int hi ){
	if( lo == hi ){
		cur_box = lo;
		cur_cap = segt[node];
	} else {
		int mid = (lo+hi)>>1;
		int ls = (node<<1)+1;
		int rs = ls+1;
		
		if( segt[ls] >= v ) get(ls,lo,mid);
		else get(rs,mid+1,hi);
	}
}

void up( int node, int lo, int hi ){
	if( lo == hi ){
		segt[node] = cur_cap;
	} else {
		int mid = (lo+hi)>>1;
		int ls = (node<<1)+1;
		int rs = ls+1;
		
		if( cur_box < mid+1 ) up(ls,lo,mid);
		else up(rs,mid+1,hi);
		segt[node] = max(segt[ls],segt[rs]);
	}
}

int64 stored;
void put( int amount ){	
	get(0,0,MAXSHIPS-1);
	if( cur_cap == K ) M++;
	cur_cap -= v;
	stored += v;
	amount--;
	while( amount ){
		if( cur_cap < v ){
			up(0,0,MAXSHIPS-1);
			get(0,0,MAXSHIPS-1);
			if( cur_cap == K ) M++;
		}
		cur_cap -= v;
		stored+=v;
		amount--;
	}
	up(0,0,MAXSHIPS-1);
}

int main( int argc, char* argv[] ){
	
	int t = next_int();
	while( t-- ){
		K = next_int();
		int n = next_int();
		
		M = 0;
		stored = 0;
		
		build(0,0,MAXSHIPS-1);
		while( n ){
			v = next_int();
			if( v == -1 ){
				int r = next_int();
				n -= r;
				v = next_int();
				put( r );
			} else {
				put( 1 );
				n--;
			}
		}
		
		printf("%d %lld\n", M, (int64(M)*int64(K))-stored );
		
	}
	
	
	return 0;
}

























