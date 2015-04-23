#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct activ_t {
	int beg, end;
	activ_t( int s = 0, int e = 0 ) : beg(s), end(e) {}
	bool operator < ( const activ_t& a ) const {
		if( end != a.end ) return end < a.end;
		return beg < a.beg;
	}
	bool inter( activ_t& a ){
		return (end >= a.beg && end < a.end) || (a.end >= beg && a.end < end);
	}
};

#define MAXN 111
#define MOD 100000000

activ_t act[MAXN];
int dp[MAXN][MAXN];
int M, N;

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	act[0] = activ_t( -2, -1 ); act[1] = activ_t( -1, 0 );
	
	cin >> M >> N;
	while( M + N ){
		
		REP( i, N ) cin >> act[i+2].beg >> act[i+2].end; N += 2;
		sort( act, act+N );
		
		FILL( dp,  0 );
		dp[0][1] = 1;
		FOR( i, 2, N-1 ) dp[ 1 ][ i ] = act[i].inter( act[1] );
		
		int ans = 0;
		FOR( j, 2, N-1 ) FOR( k, j+1, N-1 ) if( act[j].inter( act[k] ) ){
			FOR( i, 1, j-1 ) if( act[i].inter( act[j] ) && !act[k].inter( act[i] ) ){
				dp[j][k] += dp[i][j]; dp[j][k] %= MOD;
			}
		}
		int k = N-1;
		while( k && act[k].end == M ){
			REP( i, N ){ ans += dp[i][k]; ans %= MOD; }
			k--;
		}
		cout << ans << "\n";
		
		cin >> M >> N;
	}
	
	return 0;
}




















