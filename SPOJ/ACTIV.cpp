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

const int MOD = 100000000;

inline void next_int( int &n ) {
	n = 0;
	bool neg = false;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = true;
		c = getchar_unlocked();
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	n = (neg ? (-n) : (n));
}


struct activ_t{
	int s, e;
	bool operator < (const activ_t& a ) const {
		if( e != a.e ) return e < a.e;
		return s < a.s;
	}
};

#define MAXN 100000
activ_t act[MAXN];

int main( int argc, char* argv[] ){
	
	int N;
play:
	next_int( N );
	if( N != -1 ){
		
		map< int, int > compress;
		REP( i, N ){
			next_int( act[i].s );
			next_int( act[i].e );
			compress[act[i].s]++;
			compress[act[i].e]++;
		}
		int cur = 1;
		FORIT( num, compress ) num->second = cur++;
		REP( i, N ){
			act[i].s = compress[act[i].s];
			act[i].e = compress[act[i].e];
		}
		sort( act, act+N );
		
		int dp[cur]; dp[0] = 0;
		int now = 0;
		FOR( i, 1, cur ){
			dp[i] = 0;
			while( act[now].e == i ){
				dp[i] += dp[act[now].s]+1;
				if( dp[i] >= MOD ) dp[i] -= MOD;
				if( now+1 < N ) now++;
				else break;
			}
			dp[i] += dp[i-1];
			if( dp[i] >= MOD ) dp[i] -= MOD;
		}
		printf("%08d\n", dp[cur-1] );	
		goto play;
	}
	
	return 0;
}




















