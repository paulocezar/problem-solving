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

const int64 MOD = 1000000007LL;

int64 dp[1001][1001], ans[1001];
int N;

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	dp[1][1] = 1;
	ans[1] = 1;

	FOR( els, 2, 1000 ){
		
		FOR( dif_els, 1, els ){
			dp[els][dif_els] = ((dif_els*dp[els-1][dif_els]%MOD) + dp[els-1][dif_els-1])%MOD;
			ans[els] += dp[els][dif_els]; ans[els] %= MOD;
		}
	}
	
	int t;
	cin >> t;
	while( t-- ){
		cin >> N;
		cout << ans[N] << "\n";
	}
	
	return 0;
}

























