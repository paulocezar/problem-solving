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

struct seg_info{
	int sum, pref, suf, best;
	seg_info(int val = -INF){ sum = pref = suf = best = val; }
	void merge( const seg_info& left, const seg_info& right ){
		sum = left.sum + right.sum;
		pref = max( left.pref, left.sum + right.pref );
		suf = max( left.suf + right.sum, right.suf );
		best = max( sum, max(pref, suf) );
		best = max( best, max(left.best, right.best) );
		best = max( best, left.suf + right.pref );
	}
};

#define MAXN 10000
#define LGMN 14

seg_info segtree[1<<(LGMN+1)];
int a[MAXN];

void build( int node, int lo, int hi ){
	if( lo == hi ) segtree[node] = seg_info(a[lo]);
	else {
		int ls = (node<<1) + 1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		build(ls,lo,mid);
		build(rs,mid+1,hi);
		segtree[node].merge(segtree[ls], segtree[rs]);
	}
}

int from, to;
seg_info query( int node, int lo, int hi ){
	if( from <= lo && hi <= to ) return segtree[node];
	int ls = (node<<1) + 1;
	int rs = ls+1;
	int mid = (lo+hi)>>1;
	if( mid < from ) return query( rs, mid+1, hi );
	if( mid+1 > to ) return query( ls, lo, mid );
	seg_info ans;
	ans.merge( query(ls, lo, mid), query(rs,mid+1,hi) );
	return ans;
}

int N;
int query( int x1, int y1, int x2, int y2 ){
	int ans = -INF;
	if( y1 < x2 ){
		from = y1; to = x2;
		ans = query(0,0,N-1).sum;
		if( x1 <= y1-1 ){ 
			from = x1, to = y1-1;
			ans += max( 0, query(0,0,N-1).suf );
		}
		if( x2+1 <= y2 ){
			from = x2+1, to = y2;
			ans += max( 0, query(0,0,N-1).pref );
		}
		return ans;
	}
	
	from = x2, to = y1;
	seg_info aux = query(0,0,N-1); ans = aux.best;
	
	int now = aux.sum;
	from = x1, to = x2-1;
	if( from <= to ) now += max( 0, query(0,0,N-1).suf );
	from = y1+1; to = y2;
	if( from <= to ) now += max( 0, query(0,0,N-1).pref );
	ans = max(ans,now);
	
	from = x1; to = x2;
	now = query(0,0,N-1).suf;
	from = x2+1, to = y2;
	if( from <= to ) now += max(0, query(0,0,N-1).pref );
	ans = max(ans,now);
	
	from = y1, to = y2;
	now = query(0,0,N-1).pref;
	from = x2, to = y1-1;
	if( from <= to ) now += max(0, query(0,0,N-1).suf);
	ans = max(ans,now);
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, M, x1, y1, x2, y2;
	
	cin >> t;
	while( t-- ){
		
		cin >> N;
		REP( i, N ) cin >> a[i];
		cin >> M;
		build( 0, 0, N-1 );
		while( M-- ){
			cin >> x1 >> y1 >> x2 >> y2;
			cout << query( x1-1, y1-1, x2-1, y2-1 ) << "\n";
		}
		
	}
	
	return 0;
}




















