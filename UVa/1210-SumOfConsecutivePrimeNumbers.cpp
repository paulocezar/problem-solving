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

#define MAXN 10000

bitset< MAXN+10 > bs;
vector< int > primes;

void sieve(){
	primes.clear();
	REP( i, MAXN+1 ) bs[i] = i&1;
	primes.PB( 2 );
	for( int i = 3; i < MAXN; i+= 2 ) if( bs[i] ){
		primes.PB( i );
		if( i <= 100 ) for( int j = i*i; j <= MAXN; j+=i ) bs[j] = false;
	}
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	sieve();
	int MXN = SIZE(primes);
	int acum[MXN+1];
	
	acum[0] = 0;
	FOR( i, 1, MXN ) acum[i] = acum[i-1]+primes[i-1];
	
	map< int, int > ans;
	FOR( len, 1, MXN ){
		for( int j = len; j <= MXN; j++ ) ans[acum[j]-acum[j-len]]++;
	}
	
	int n;
	while( cin >> n && n ) cout << ans[n] << "\n";
	
	return 0;
}

























