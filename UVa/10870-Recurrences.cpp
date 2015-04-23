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

#define MDIM 15

int64 aux[MDIM][MDIM], base[MDIM];

int DIM; int64 mod;

void mult( int64 a[][MDIM], int64 b[][MDIM] ){
	REP( i, DIM ) REP( j, DIM ){
		aux[i][j] = 0;
		REP( k, DIM ){
			aux[i][j] += (a[i][k]*b[k][j])%mod; aux[i][j] %= mod;
		}
	}
	REP( i, DIM ) REP( j, DIM ) a[i][j] = aux[i][j];
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int64 N, pot[MDIM][MDIM], ans[MDIM][MDIM];
	
	
	while( (cin >> DIM >> N >> mod) && (DIM||N||mod) ){
		REP( i, DIM ){ cin >> pot[0][i]; pot[0][i] %= mod; }
		RREP( i, DIM ){ cin >> base[i]; base[i] %= mod; }
		FOR( i, 1, DIM-1 ) REP( j, DIM ) pot[i][j] = (i==(j+1));
		REP( i, DIM ) REP( j, DIM ) ans[i][j] = (i==j);
		if( N <= DIM ) cout << base[N-DIM] << "\n";
		else {
			N -= DIM;
			while( N ){
				if( N&1 ) mult(ans,pot);
				mult(pot,pot);
				N >>= 1;
			}
			int64 res = 0;
			REP( i, DIM ){ res += (ans[0][i]*base[i])%mod; res %= mod; }
			cout << res << '\n';
		}
	}
	
	return 0;
}

























