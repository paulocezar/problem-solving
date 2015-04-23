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

const int64 MOD = 1000000000000LL;

int n, tc; 
int64 dp[7][2222];

int beg[22], end[22], len[22];


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	
	beg[1]	= 0; end[1]  = 0; len[1] = 1;
	beg[2] 	= 0; end[2]  = 5; len[2] = 1;
	beg[3] 	= 5; end[3]  = 0; len[3]  = 2;
	beg[4] 	= 3; end[4]  = 0; len[4]  = 2;
	beg[5] = 2; end[5] = 5; len[5] = 2;
	beg[6]	= 0; end[6]  = 2; len[6] = 1;
	beg[7] 	= 2; end[7]  = 0; len[7]  = 2;
	beg[8]  = 3; end[8]  = 1; len[8] = 1;
	beg[9] 	= 6; end[9]  = 4; len[9] = 1;
	beg[10] = 0; end[10] = 1; len[10] = 1;
	beg[11] = 6; end[11] = 0; len[11] = 2;
	beg[12] = 0; end[12] = 3; len[12] = 1;
	beg[13] = 4; end[13] = 0; len[13] = 2;	
	beg[14] = 0; end[14] = 6; len[14] = 1;
	beg[15] = 1; end[15] = 0; len[15] = 2;
	beg[16] = 4; end[16] = 3; len[16] = 2;
	beg[17] = 1; end[17] = 6; len[17] = 2;
	beg[18] = 0; end[18] = 4; len[18] = 1;
	beg[19] = 3; end[19] = 1; len[19] = 3;
	beg[20] = 6; end[20] = 4; len[20] = 3;	
	
	REP( i, 7 ) dp[i][0] = 0;
	dp[0][0] = 1;
	
	FOR( size, 1, 2000 ){
		
		REP( i, 7 ) dp[i][size] = 0;
		
		FOR( last, 1,  20 ){
			if( size >= len[last] ){
				dp[ end[last] ][size] += dp[ beg[last] ][size-len[last]];
				dp[ end[last] ][size] %= MOD;
			}
		}
	}
	
	
	while( cin >> n && n ){ tc++; cout << "Case " << tc << ": " << dp[0][n] << "\n"; }
	
	return 0;
}

























