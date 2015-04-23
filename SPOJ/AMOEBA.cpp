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
 
int cycle_len[] = { 1, 4, 4, 20, 100, 500, 5000, 50000, 500000, 5000000 };

int64 mod;

int64 modpow( int n ){
	int64 res = 1;
	int64 pot = 7;
	while( n ){
		if( n & 1 ){ res *= pot; res %= mod; }
		pot *= pot; pot %= mod;
		n >>= 1;
	}
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	string num;
	while( cin >> num ){
		int64 n = 0;
		int K = SIZE(num);
		REP(i,K) n = 10LL*n + (num[i]-'0');
		
		int ans = 1;
		mod = 10;
		
		FOR( dig, 1, K ){
			
			int max_jumps = cycle_len[dig]/cycle_len[dig-1];
			while( max_jumps >= 0 ){
				if( modpow(ans-1) == (n%mod) ) goto hell;
				ans += cycle_len[dig-1];
				max_jumps--;				
			}
			ans = -1; break;
			
		hell:
			mod *= 10LL;	
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
}

























