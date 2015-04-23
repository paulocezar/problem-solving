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

#define MAXM 100100

int N, M;

struct bus_t{
	int s, t;
	bus_t( int ss = 0, int tt = 0 ) : s(ss), t(tt) {}
	bool operator < ( const bus_t& b ) const {
		if( t != b.t ) return t < b.t;
		return s < b.s;
	}
};

bus_t bus[MAXM];

const int64 MOD = 1000000007LL;

int64 bit[2*MAXM + 1];

void up( int x, int64 tt ){
	while( x <= (2*MAXM) ){
		bit[x] = bit[x] + tt;
		bit[x] %= MOD;
		x += ( x & -x );
	}
}

int64 get( int x ){
	int64 ans = 0;
	while( x > 0 ){
		ans += bit[x];
		ans %= MOD;
		x -= ( x & -x );
	}
	return ans;
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cin >> N >> M;
	
	map< int, int > occ;
	REP( i, M ){
		cin >> bus[i].s >> bus[i].t;
		occ[ bus[i].s ]++;
		occ[ bus[i].t ]++;
	}
	occ[ 0 ]++;
	occ[ N ]++;
	
	sort( bus, bus+M );
	
	map< int, int > id;
	int cid = 1;
	FORIT( x, occ ) id[ x->first ] = cid++;
	
	up( 1, 1 );
	REP( i, M ){
		up( id[ bus[i].t ], ( get( id[ bus[i].t ]-1 ) - get( id[ bus[i].s ]-1 ) + MOD ) % MOD );
	}
	
	cout << ( get( id[N] ) - get( id[N] - 1 ) + MOD ) % MOD << "\n";
	
	return 0;
}




















