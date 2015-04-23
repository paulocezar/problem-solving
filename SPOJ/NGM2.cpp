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

int64 gcd( int64 a, int64 b ){
	while( b ){
		a %= b; 
		b ^= a; a ^= b; b ^= a;
	}
	return a;
}

int64 mmc( int64 a, int64 b ){
	return (a/gcd(a,b))*b;
}

int64 N, x[15];
int K;

int64 solve( int64 now, int64 sg, int pos ){
	if( now > N  ) return 0;
	if( pos == K ) return sg*(N/now);
	return solve(now, sg, pos+1) + solve( mmc(now,x[pos]), -sg, pos+1 );
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cin >> N >> K;
	REP( i, K ) cin >> x[i];
	cout << solve( 1, 1, 0 ) << "\n";
	
	/*
	int mask = 1<<K; int64 sg;
	int64 ans = 0;
	
	while( mask ){
		mask--;
		if( __builtin_popcount(mask) & 1 ) sg = -1;
		else sg = 1;
		
		int64 cur = 1;
		REP( i, K ) if( mask & (1<<i) ){
			cur = mmc( cur, x[i] );
			if( cur > N ) break;
		}
		
		if( cur <= N ) ans = ans + sg*(N/cur);
	}
	
	cout << ans << "\n";
	*/
	return 0;
}




















