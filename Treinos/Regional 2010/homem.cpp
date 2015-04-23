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

#define MAXN 100000
#define LGMN 17

struct seg_info{
	int h, e, r;
	seg_info( int hh = 0, int ee = 0, int rr = 0 ) : h(hh), e(ee), r(rr) {}
	void merge( seg_info a, seg_info b ){
		h = a.h + b.h;
		e = a.e + b.e;
		r = a.r + b.r;
	}
	void rotate(){
		int aux = r;
		r = e; e = h; h = aux;
	}
};

seg_info segt[1<<(LGMN+1)];
char lazy[1<<(LGMN+1)];

void build( int node, int lo, int hi ){
	if( lo == hi ) segt[node] = seg_info( 1, 0, 0 );
	else {
		int ls = (node<<1) + 1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
		segt[node].merge( segt[ls], segt[rs] );
	}
	lazy[node] = 0;
}

void push(int node, bool leaf){
	if( !lazy[node] ) return;
	if( !leaf ){
		int ls = (node<<1) + 1;
		int rs = ls + 1;
		lazy[ls] += lazy[node]; lazy[ls] %= 3;
		lazy[rs] += lazy[node]; lazy[rs] %= 3;
	}
	while( lazy[node] ){
		segt[node].rotate();
		lazy[node]--;
	}
}

int from, to;
void update( int node, int lo, int hi ){
	if( from <= lo && hi <= to ){
		lazy[node]++; if( lazy[node] == 3 ) lazy[node] = 0;
		push(node, lo == hi );
	} else {
		int ls = (node<<1) + 1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		push( node, lo == hi );
		if( mid >= from ) update( ls, lo, mid ); else push( ls, lo == mid);
		if( mid+1 <= to ) update( rs, mid+1, hi ); else push( rs, hi == (mid+1));
		segt[node].merge( segt[ls], segt[rs] );
	}
}


seg_info query( int node, int lo, int hi ){
	push( node, lo == hi );
	if( from <= lo && hi <= to ) return segt[node];
	int ls = (node<<1) + 1;
	int rs = ls+1;
	int mid = (lo+hi)>>1;
	if( mid+1 > to ) return query(ls, lo, mid);
	if( mid < from ) return query(rs, mid+1, hi);
	seg_info ans;
	ans.merge( query(ls,lo,mid), query(rs,mid+1,hi) );
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int N, M;
	char wut;
	seg_info ans;
	
	while( cin >> N >> M ){
		build( 0, 0, N-1 );
		
		REP( i, M ){
			cin >> wut >> from >> to; from--, to--;
		
			if( wut == 'M' ) update( 0, 0, N-1 );
			else {
				ans = query( 0, 0, N-1 );
				cout << ans.h << " " << ans.e << " " << ans.r << "\n";
			}
		}
		cout << "\n";
	}
	
	return 0;
}













