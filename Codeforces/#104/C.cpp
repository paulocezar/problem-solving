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

const int64 MOD = 1000000007LL;

int sz;
int64 dp[2000][2000];
vector< int > vec;

map< int, int64 > occ;

int64 solve( int pos, int nd ){
	if( nd == 0 ) return 1;
	if( pos == sz ) return 0;
	
	int64 &ret = dp[pos][nd];
	if( ret == -1 ){
		ret = solve( pos+1, nd ); 
		ret += ( (occ[vec[pos]]*solve(pos+1,nd-1)) %MOD );
		ret %= MOD;
	}
	return ret;
}

bool lucky( int x ){
	while( x ){
		if( x%10 != 4 && x%10 != 7 ) return false;
		x /= 10;
	}
	return true;
}

int64 modpow( int64 a, int64 b ){
	int64 ans = 1;
	while( b ){
		if( b&1 ){ ans *= a; ans %= MOD; }
		a *= a; a %= MOD;
		b >>= 1;
	}
	return ans;
}

int64 fat[100001];

int64 comb( int n, int k ){
	if( n < k ) return 0;
	return (fat[n] * modpow( (fat[k]*fat[n-k])%MOD, MOD-2 )) % MOD;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n, k;
	
	cin >> n >> k;
	
	FILL( dp, -1 );
	vec.clear();
	
	fat[0] = 1;
	FOR( i, 1, max(n,k) ){
		fat[i] = fat[i-1]*i;
		fat[i] %= MOD;
	}

	int ai;
	occ.clear();
	int nn = n;
	
	REP( i, n ){
		cin >> ai;
		if( lucky(ai) ){ 
			if( occ[ai] == 0 ) vec.PB( ai );
			occ[ai]++;
			nn--;
		}
	}
	
	sz = SIZE(occ);
	int64 ans = 0;
	REP( i, min(k,sz)+1 ){
		int64 now = solve( 0, i ) * comb( nn, k-i );
		now %= MOD;
		ans += now;
		ans %= MOD;
	}
	
	cout << ans << "\n";
	
	return 0;
}




















