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

#define MXXX 10000

int64 sieve_size;
bitset< MXXX+10 > bs;
vector< int > primes;

void sieve( int64 ub ){
	sieve_size = ub+1;
	bs.reset(); bs.set( 2, true ); primes.PB( 2 );
	FOR( i, 3, sieve_size ) if( i&1 ) bs.set( i, true );
	FOR( i, 3, sieve_size ) if( bs.test(i) ){
		for( int j = i*i; j <= sieve_size; j+=i ) bs.set(j, false);
		primes.PB( i );
	}
}

bool isPrime( int64 N ){
	if( N < sieve_size ) return bs.test( N );
	REP( i, SIZE(primes) ) if( N % primes[i] == 0 ) return false;
	return true;
}

#define MAXN 10010
int a[MAXN], dp[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	sieve( MXXX );
	int t;
	cin >> t;
	while( t-- ){
		int N;
		cin >> N;
		dp[0] = 0;
		REP( i, N ){
			cin >> a[i];
			dp[i+1] = a[i]+dp[i];
		}
		FOR( sz, 2, N ){
			for( int i = 1; i+sz-1 <= N; i++ ){
				if( isPrime(dp[i+sz-1]-dp[i-1]) ){
					cout << "Shortest primed subsequence is length " << sz << ":";
					FOR( x, i-1, i+sz-2 ) cout << " " << a[x];
					goto hell;
				}
			}
		}
		cout << "This sequence is anti-primed.";
	hell:
		cout << "\n";
	}
	
	return 0;
}




















