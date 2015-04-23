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

#define MAXN 50000
#define LGMN 16

int segt[1<<(LGMN+1)];

void build( int node, int lo, int hi ){
	if( lo == hi ) segt[node] = INF;
	else{
		int mid = (lo+hi)>>1;
		int ls = (node<<1) + 1;
		int rs = ls+1;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
		segt[node] = MIN( segt[ls], segt[rs] );
	}
}

int from, to, val;

void update( int node, int lo, int hi ){
	if( lo == hi ){
		segt[node] = MIN( segt[node], val );
	} else {
		int mid = (lo+hi)>>1;
		int ls = (node<<1) + 1;
		int rs = ls+1;
		if( lo <= to && to <= mid ) update( ls, lo, mid );
		if( mid+1 <= to && to <= hi ) update( rs, mid+1, hi );
		segt[node] = MIN(segt[ls],segt[rs]);
	}
}
string trsh;
int get( int node, int lo, int hi ){
	if( from <= lo && hi <= to ){
		return segt[node];
	}
	int mid = (lo+hi)>>1;
	int ls = (node<<1) + 1;
	int rs = ls+1;
	int ans = INF;
	if( mid >= from ) ans = MIN( ans, get( ls, lo, mid ) );
	if( mid+1 <= to ) ans = MIN( ans, get( rs, mid+1, hi ) );
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t, N, M;
	
	cin >> t;
	while( t-- ){
		cin >> N >> M;
		build( 0, 1, N );
		
		to = 1; val = 0;
		update( 0, 1, N );
		
		REP( i, M ){
			cin >> from >> to;
			val = 1 + get(0, 1, N);
			update( 0, 1, N );			
		}
		from = to = N;
		cout << get(0, 1, N) << "\n";
	}
	return 0;
}




















