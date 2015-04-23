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

#include <bitset>

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

#define MAXN 5000000
#define SQMN 2240

int sum[MAXN+1];
int dp[MAXN+1];

bitset< MAXN+100 > bs;

void sieve(){
	bs.set( 0, false );
	bs.set( 1, false );
	FOR( i, 2, MAXN ){
		if( i&1 ){
			sum[i] = 0;
			bs.set( i, true );
		} else {
			bs.set( i, false );
			sum[i] = 2;
		}
	}
	bs.set( 2, true );
	
	for( int i = 3; i <= MAXN; i+=2 ) if( bs.test(i) ){
		sum[i] = i;
		for( int j = i+i; j <= MAXN; j+=i ){
			sum[j] += i;
			bs.set( j, false );
		}
	}
}

void pre(){
	
	sieve();
	dp[0] = dp[1] = 0;
	
	FOR( i, 2, MAXN ){
		dp[i] = dp[i-1];
		if( bs.test( sum[i] ) ) dp[i]++;
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int beg, end;
	
	pre();
	
	while( (cin >> beg) && beg ){
		cin >> end;
		cout << dp[end]-dp[beg-1] << "\n";
	}
	
	return 0;
}




















