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

const int MOD = 10007;

int segtree[1<<(LGMN+1)];
int lazy[1<<(LGMN+1)][3];

void build( int node, int lo, int hi ){
	segtree[node] = 0;
	REP( i, 3 ) lazy[node][i] = 0;
	if( lo == hi ) return;
	int mid = (lo+hi)/2;
	int ls = 2*node + 1;
	int rs = ls+1;
	build(ls, lo, mid);
	build(rs, mid+1, hi);
}

int sumi( int n ){
	if( n <= 0 ) return 0;
	return ( ( ((n%MOD) * ((n+1)%MOD))%MOD ) * 5004 )%MOD; 
}

int sumi2( int n ){
	if( n <= 0 ) return 0;
	n %= MOD;
	return ( ((((n*((n+1)%MOD))%MOD)*((2*n+1)%MOD))%MOD)*1668 ) % MOD;
}

void push( int node, int lo, int hi ){
	if( lo != hi ){
		int ls = 2*node + 1;
		int rs = ls+1;
		REP( i, 3 ){
			lazy[ls][i] = (lazy[ls][i]+lazy[node][i])%MOD;
			lazy[rs][i] = (lazy[rs][i]+lazy[node][i])%MOD;
		}
	}
	
	int scoef = 0;
	scoef = (((hi-lo+1)%MOD)*lazy[node][2]) % MOD;
	
	int sumx = ( ((sumi(hi) - sumi(lo-1))%MOD) + MOD ) % MOD;
	int sumx2 = ( ((sumi2(hi) - sumi2(lo-1))%MOD) + MOD ) % MOD;
	
	segtree[node] += (lazy[node][0]*sumx2)%MOD; segtree[node] %= MOD;
	segtree[node] += (lazy[node][1]*sumx)%MOD; segtree[node] %= MOD;
	segtree[node] += scoef; segtree[node] %= MOD;

	REP( i, 3 ) lazy[node][i] = 0;
}

int from, to, eq[3];
void update( int node, int lo, int hi ){
	
	if( from <= lo && hi <= to ){
		REP( i, 3 ) lazy[node][i] = (lazy[node][i]+eq[i])%MOD;
		push(node, lo, hi);
		return;
	}
	push( node, lo, hi );
	if( hi < from || lo > to ) return;
	
	int ls = 2*node + 1;
	int rs = ls+1;
	int mid = (lo+hi)/2;
		update( ls, lo, mid );
		update( rs, mid+1, hi );
	segtree[node] = (segtree[ls]+segtree[rs])%MOD;
}

int query( int node, int lo, int hi ){
	push( node, lo, hi );
	if( from <= lo && hi <= to ) return segtree[node];
	int ls = 2*node + 1;
	int rs = ls+1;
	int mid = (lo+hi)/2;
	int ans = 0;
	if( mid >= from ){ ans += query(ls,lo,mid); ans %= MOD; }
	if( mid+1 <= to ){ ans += query(rs,mid+1,hi); ans %= MOD; }
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int wut, N, M;
	cin >> N >> M;
	build( 0, 0, N-1 );
	while( M-- ){
		cin >> wut;
		if( wut ){
			cin >> from >> to;
			cout << query(0, 0, N-1) << "\n";
		} else {
			cin >> from >> to >> eq[0] >> eq[1] >> eq[2];
			update(0, 0, N-1);
		}
	}
	
	return 0;
}




















