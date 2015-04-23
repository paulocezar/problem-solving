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

int64 mod, aux[2][2];

void mult( int64 a[][2], int64 b[][2] ){
	REP( i, 2 ) REP( j, 2 ){
		aux[i][j] = 0;
		REP( k, 2 ){
			aux[i][j] += (a[i][k]*b[k][j])%mod;
			aux[i][j] %= mod;
		}
	}
	REP( i, 2 ) REP( j, 2 )
		a[i][j] = aux[i][j];
}


int64 fib( int n ){
	int64 pot[2][2] = { {0,1},
						{1,1} };
	int64 ans[2][2] = { {1,0},
						{0,1} };
		
	if( n <= 2 ) return 1;
	n -= 2;
	while( n ){
		if( n&1 ) mult(ans,pot);
		mult(pot,pot);
		n >>= 1;
	}
	return (ans[1][0]+ans[1][1])%mod;				 
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		int N;
		cin >> N >> mod;
		cout << fib(2*N-1) << "/" << fib(2*N) << "\n";		
	}
	
	return 0;
}

























