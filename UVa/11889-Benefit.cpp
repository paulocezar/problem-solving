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
#include <bitset>
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

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 4000

bitset< MAXN > bs;
vector< int > primes;

void sieve(){
	REP( i, MAXN ) bs[i] = (i&1);
	primes.PB( 2 );
	for( int i = 3; i < MAXN; i+=2 ) if( bs[i] ){
		primes.PB( i );
		for( int j = i*i; j < MAXN; j+=i ) bs[j] = false;
	}
}

int fstpow(int a, int b){
	int res = 1;
	while( b ){
		if( b&1 ) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int fact( int lcm, int a ){
	
	int res = 1;
	REP( i, SIZE(primes) ){
		int ca = 0;
		while( a%primes[i] == 0 ){ ca++; a /= primes[i]; }
		int cb = 0;
		while( lcm%primes[i] == 0 ){ cb++; lcm /= primes[i]; }
		if( cb != ca ) res *= fstpow(primes[i], cb ); 
	}
	
	if( lcm != a ) res *= lcm;
	
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	sieve();
	
	int t;
	cin >> t;
	while( t-- ){
		
		int C, A;
		cin >> A >> C;
		
		if( C % A ) cout << "NO SOLUTION\n";
		else cout << fact( C, A ) << "\n";
		
	}
	
	return 0;
}

























