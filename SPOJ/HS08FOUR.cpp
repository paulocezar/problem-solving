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

inline int next_int() {
	int res = 0;
	char c = getchar_unlocked();	
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = (res * 10) + (c - '0');
		c = getchar_unlocked();
	}
	return res;
}

typedef int64 mtrx[4][4];
const int64 MOD = 1000000007LL;

mtrx low[1<<15], high[1<<15], ans;
int64 base[4];

int main( int argc, char* argv[] ){
	
	
	low[0][0][0] = 1; low[0][0][1] = 0; low[0][0][2] = 0; low[0][0][3] = 0; 
	low[0][1][0] = 0; low[0][1][1] = 1; low[0][1][2] = 0; low[0][1][3] = 0; 
	low[0][2][0] = 0; low[0][2][1] = 0; low[0][2][2] = 1; low[0][2][3] = 0; 
	low[0][3][0] = 0; low[0][3][1] = 0; low[0][3][2] = 0; low[0][3][3] = 1;
	
	low[1][0][0] = 1; low[1][0][1] = 0; low[1][0][2] = 0; low[1][0][3] = 2; 
	low[1][1][0] = 0; low[1][1][1] = 0; low[1][1][2] = 0; low[1][1][3] = 1; 
	low[1][2][0] = 1; low[1][2][1] = 1; low[1][2][2] = 1; low[1][2][3] = 1; 
	low[1][3][0] = 0; low[1][3][1] = 0; low[1][3][2] = 3; low[1][3][3] = 0; 
	
	REP( i, 4 ) REP( j, 4 ) 
		high[0][i][j] = low[0][i][j];

	base[0] = 6, base[1] = 3, base[2] = 4, base[3] = 3;
	
	int MX = (1<<15) - 1;
	FOR( msk, 2, MX ){
		
		REP( i, 4 ) REP( j, 4 ){
			REP( k, 4 )
				low[msk][i][j] += low[1][i][k]*low[msk-1][k][j];
			low[msk][i][j] %= MOD;
		}
		
	}
	
	REP( i, 4 ) REP( j, 4 ){
		REP( k, 4 )
			high[1][i][j] += low[MX][i][k]*low[1][k][j];
		high[1][i][j] %= MOD;
	}
	
	FOR( msk, 2, MX ){
		REP( i, 4 ) REP( j, 4 ){
			REP( k, 4 )
				high[msk][i][j] += high[msk-1][i][k]*high[1][k][j];
			high[msk][i][j] %= MOD;
		}
	}
	
	int N, loid, tst = next_int();
	
	while( tst-- ){
		
		N = next_int();
		if( N == 1 ) puts("4");
		else {
			N -= 2;
			int64 res = 0;
			
			FILL( ans, 0 );
			loid = N&MX;
			N >>= 15;
			REP( i, 4 ) REP( j, 4 ){ REP( k, 4)
				ans[i][j] += low[loid][i][k]*high[N][k][j];
				ans[i][j] %= MOD;
			}
			
			REP( i, 4 ) REP( j, 4 ){
				res += ans[i][j]*base[j];
				res %= MOD;
			}
			
			printf("%lld\n", res );
		}
	}
	
	
	return 0;
}

























