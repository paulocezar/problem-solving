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

const int64 MOD = 100000007LL;

bitset< MAXN+1 > bs;
vector< int > primes;

void sieve(){
	FOR( i, 0, MAXN ) bs[i] = (i&1);
	primes.PB( 2 );
	for( int i = 3; i <= MAXN; i+=2 ) if( bs[i] ){
		primes.PB( i );
		for( int j = i*i; j <= MAXN; j += i ) bs[j] = false;
	}
}

vector< pair<int,int> > primefact;

void fact( int N ){
	primefact.clear();
	int sq = sqrt(N)+1;
	for( int i = 0; i < SIZE(primes) && primes[i] <= sq; i++ ){
		if( (N%primes[i]) == 0 ){
			primefact.PB( MP(primes[i],0) );
			while( (N%primes[i]) == 0 ){
				primefact.back().second++;
				N /= primes[i];
			}
		}
	}
	if( N != 1 ) primefact.PB( MP(N,1) );
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	sieve();
	
	int N, M, T, tc = 1;
	while( (cin >> N >> M >> T) && (N||M||T) ){
		fact(N);
		
		int sz = SIZE(primefact);
		REP( i, SIZE(primefact) ) primefact[i].second *= M;
		
		int msk = (1<<sz)-1;
		int64 ans = 0;
		while( msk ){
			
			int64 cur = 1;
			REP( i, sz ) if( msk & (1<<i) ){
				int lo = (primefact[i].second/(T+1));
				int hi = (primefact[i].second/T);
				int64 has = max(0,hi-lo);
				cur *= has; cur %= MOD;
			} else {
				int64 lo = (primefact[i].second/(T+1));
				cur *= (lo+1); cur %= MOD;
			}
			ans += cur; ans %= MOD;
			
			msk--;
		}		
		cout << "Case " << tc++ << ": " << ans << "\n";
	
	}
	
	return 0;
}

























