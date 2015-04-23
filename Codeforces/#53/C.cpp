#include <map> 
#include <set> 
#include <cmath> 
#include <queue> 
#include <vector> 
#include <string> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <cfloat>
#include <ctime> 
#include <climits>

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64;

const int64 MOD = 1000000007;

int64 mpow( int64 a, int64 b ){
	
	if( b == 0 ) return 1LL;
	int64 r = mpow( a, b/2 );
	r *= r;
	r %= MOD;
	if( b&1 ) return ( r * a ) % MOD;
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	int64 n, num, den;
	cin >> n;
	
	num = den = 1;
	FOR( i, 1, n+1 ) { num *= (n+i); num %= MOD; den *= i; den %= MOD; }
	
	den = mpow( den, MOD-2 );
	
	int64 ans = ( num * den ) % MOD;
	ans = ( ans + MOD - n ) % MOD;
	
	cout << ans << "\n";
	
	return 0;
}
