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

struct query_t{
	int lo, hi, id;
	query_t( int l = 0, int h = 0, int i = 0 ) : lo(l), hi(h), id(i) {}
	bool operator < ( const query_t& q ) const {
		if( hi != q.hi ) return hi < q.hi;
		return lo < q.lo;
	}
};

struct node_t{
	int suf;	// current best suffix in [lo,hi]
	int best;	// best suffix seen so far in [lo,hi]
	int lsuf;	// current suffix to be added
	int lbest;	// best prefix of the suffix to be added
	void refresh( int val ){
		lsuf += val;
		lbest = max( lsuf, lbest );
		
		suf += val;
		best = max( suf, best );
	}
};

node_t segtree[1<<(LGMN+1)];
query_t qr[MAXN];
int a[MAXN], last[2*MAXN+2], qans[MAXN];

void build( int node, int lo, int hi ){
	segtree[node].suf = segtree[node].best = 0;
	segtree[node].lsuf = segtree[node].lbest = 0;
	if( lo != hi ){
		int ls = 2*node + 1;
		int rs = ls+1;
		int mid = (lo+hi)/2;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
	}
}

int from, to, val;

void push( int node, bool leaf ){
	if( (segtree[node].lsuf == 0 && segtree[node].lbest == 0) || leaf ) return;
	
	int ls = 2*node+1;
	int rs = ls+1;
	
	int sfx = segtree[node].lsuf;
	int bsfx = segtree[node].lbest;
	
	segtree[ls].refresh( bsfx );
	segtree[ls].refresh( sfx-bsfx );

	segtree[rs].refresh( bsfx );
	segtree[rs].refresh( sfx-bsfx );
	
	segtree[node].lsuf = segtree[node].lbest = 0;
}

void update( int node, int lo, int hi ){
	if( from <= lo && hi <= to ){
		segtree[node].refresh( val );
		return;
	}
	push( node, lo == hi );
	if( lo > to || hi < from ) return;
	int ls = 2*node+1;
	int rs = ls+1;
	int mid = (lo+hi)/2;
		update( ls, lo, mid );
		update( rs, mid+1, hi );
	segtree[node].suf = max( segtree[ls].suf, segtree[rs].suf  );
	segtree[node].best = max( segtree[ls].best, segtree[rs].best );
}

int query( int node, int lo, int hi ){
	push( node, lo == hi );
	if( from <= lo && hi <= to ) return segtree[node].best;
	int ls = 2*node + 1;
	int rs = ls+1;
	int mid = (lo+hi)/2;
	int res = 0;
	if( mid >= from ) res = max( res, query( ls, lo, mid ) );
	if( mid+1 <= to ) res = max( res, query( rs, mid+1, hi ) );
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, Q;
	cin >> N;
	build( 0, 0, N-1 );
	REP( i, N ){
		cin >> a[i];
		last[a[i]+MAXN] = -1;
	}
	cin >> Q;
	REP( i, Q ){
		cin >> from >> to;
		qr[i] = query_t(from-1,to-1,i);
	}
	sort( qr, qr+Q );
	
	int at = 0;
	REP( i, N ){
		from = last[a[i]+MAXN]+1; last[a[i]+MAXN] = i;
		to = i; val = a[i];
		update( 0, 0, N-1 );
		while( at < Q && i == qr[at].hi ){
			from = qr[at].lo;
			to = qr[at].hi;
			qans[qr[at].id] = query(0, 0, N-1);
			at++;
		}
		if( at == Q ) break;
	}
	
	REP( i, Q ) cout << qans[i] << "\n";
	
	return 0;
}


















