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

#define MAXK 16

int K;
int64 mod, aux[MAXK][MAXK], ans[MAXK][MAXK], pot[MAXK][MAXK];
int64 c[MAXK], b[MAXK], acum[MAXK];

void mult( int64 a[][MAXK], int64 b[][MAXK] ){
	REP( i, K+1 ) REP( j, K+1 ){
		aux[i][j] = 0;
		REP( k, K+1 ){
			aux[i][j] += (a[i][k]*b[k][j])%mod;
			aux[i][j] %= mod;
		}
	}
	REP( i, K+1 ) REP( j, K+1 )
		a[i][j] = aux[i][j];
}

int64 get( int64 N ){
	if( N == 0 ) return 0;
	if( N <= K ) return acum[N-1];
	else {
		N -= K;
		REP( i, K+1 ) REP( j, K+1 ){ ans[i][j] = (i==j); pot[i][j] = 0; }
		
		FOR( i, 1, K-1 ) REP( j, K ) pot[i][j] = (i==(j+1));
		REP( i, K ) pot[0][i] = pot[K][i] = c[i];
		pot[K][K] = 1;
		
		while( N ){
			if( N&1 ) mult( ans, pot );
			mult(pot, pot);
			N >>= 1;
		}
		
		int64 res = 0;
		REP( j, K+1 ){ res += (ans[K][j]*b[j])%mod; res %= mod; }
		return res;
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	int64 n, m;
	
	cin >> t;
	while( t-- ){
		
		cin >> K;
		REP( i, K ){
			cin >> b[K-i-1];
			acum[i] = (i?(acum[i-1]+b[K-i-1]):(b[K-i-1]));
		}
		b[K] = acum[K-1];
		
		REP( i, K ) cin >> c[i];
		cin >> m >> n >> mod;
		
		int64 res = get(n);
		res -= get(m-1);
		res %= mod; res += mod; res %= mod;
		cout << res << "\n";
		
	}
	
	return 0;
}

























