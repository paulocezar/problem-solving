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

int64 aux[5][5];
int64 pot[5][5];
int64 ans[5][5];

void mulap(){
	REP( i, 5 ) REP( j, 5 ){
		aux[i][j] = 0;
		REP( k, 5 ){ aux[i][j] += ((ans[i][k]*pot[k][j])%MOD); aux[i][j] %= MOD; }
	}
	REP( i, 5 ) REP( j, 5) ans[i][j] = aux[i][j];
}

void mulp(){
	REP( i, 5 ) REP( j, 5 ){
		aux[i][j] = 0;
		REP( k, 5 ){ aux[i][j] += ((pot[i][k]*pot[k][j])%MOD); aux[i][j] %= MOD; }
	}
	REP( i, 5 ) REP( j, 5) pot[i][j] = aux[i][j];
}

int64 get( int n ){
	if( n < 3 ) return 0;
	n -= 3;
	
	pot[0][0] = 1; pot[0][1] = 1; pot[0][2] = 1; pot[0][3] = 1; pot[0][4] = 1;
	pot[1][0] = 0; pot[1][1] = 1; pot[1][2] = 1; pot[1][3] = 1; pot[1][4] = 1;
	pot[2][0] = 0; pot[2][1] = 1; pot[2][2] = 0; pot[2][3] = 0; pot[2][4] = 0;
	pot[3][0] = 0; pot[3][1] = 0; pot[3][2] = 1; pot[3][3] = 0; pot[3][4] = 0;
	pot[4][0] = 0; pot[4][1] = 0; pot[4][2] = 0; pot[4][3] = 1; pot[4][4] = 0;
	
	
	ans[0][0] = 1; ans[0][1] = 0; ans[0][2] = 0; ans[0][3] = 0; ans[0][4] = 0;
	ans[1][0] = 0; ans[1][1] = 1; ans[1][2] = 0; ans[1][3] = 0; ans[1][4] = 0;
	ans[2][0] = 0; ans[2][1] = 0; ans[2][2] = 1; ans[2][3] = 0; ans[2][4] = 0;
	ans[3][0] = 0; ans[3][1] = 0; ans[3][2] = 0; ans[3][3] = 1; ans[3][4] = 0;
	ans[4][0] = 0; ans[4][1] = 0; ans[4][2] = 0; ans[4][3] = 0; ans[4][4] = 1;
	
	while( n ){
		if( n&1 ) mulap();
		mulp();
		n >>= 1;
	}
	return (ans[0][0]+ans[0][1])%MOD;
}

int read(){
	int n = 0;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) c = getchar_unlocked();
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return n;
}

int main( int argc, char* argv[] ){
	
	//ios::sync_with_stdio( false );

	int t, n, m;
	t = read();
	while( t-- ){
		n = read();
		m = read();
		int64 ans = get(m)-get(n-1); ans %= MOD;
		ans += MOD; ans %= MOD;
		printf("%d\n", int(ans) );
	}
	
	return 0;
}




















