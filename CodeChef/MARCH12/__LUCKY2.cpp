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

const int MOD = 1000000007;

#define LCKSZ 14
int lck[] = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777 };

int dp[2][2][1010];
char wanted[1010];

int islucky( int x ){
	if( x == 0 ) return 0;
	while( x ){ if(((x%10)!=4) && ((x%10)!=7)) return 0; x /= 10; }
	return 1;
}

/*int solve( int lsq, int pos, int has ){
	
	if( pos == n ) return wanted[has];
	
	int &ret = dp[lsq][pos][has];
	
	if( memo[lsq][pos][has] == cur_test ) return ret;
	memo[lsq][pos][has] = cur_test;
	
	if( pos == 0 ){
		
		ret = 0;
		int lim = cur[pos]-'0';
		REP( i, lim+1 ){ ret += solve( (i==lim), pos+1, has+((i==4)||(i==7)) ); ret %= MOD; }
		
	} else {
		
		ret = 0;
		int lim = (lsq?(cur[pos]-'0'):(9));
		REP( i, lim+1 ){ ret += solve( lsq && (i==lim) , pos+1, has+((i==4)||(i==7)) ); ret %= MOD; }
		
	}
	return ret;
}*/

char L[1010], R[1010];
	
int solve( char* cur, int n ){
	int old = 0;
	int now = 1;
	REP( i, 2 ) REP( j, n+1 ) dp[0][i][j] = wanted[j];
	
	RREP( pos, n ){
		REP( lsq, 2 ) REP( has, n+1 ){
			int &ret = dp[now][lsq][has];
			if( pos == 0 ){

				ret = 0;
				int lim = cur[pos]-'0';
				REP( i, lim+1 ){
					ret += dp[old][ (i==lim) ][ has+((i==4)||(i==7)) ];
					if( ret >= MOD ) ret -= MOD;
				}

			} else {

				ret = 0;
				int lim = (lsq?(cur[pos]-'0'):(9));
				REP( i, lim+1 ){
					ret += dp[old][ lsq && (i==lim) ][ has+((i==4)||(i==7)) ];
					if( ret >= MOD ) ret -= MOD;
				}

			}
		}
		old = !old;
		now = !now;
	}
	
	return dp[old][0][0];
}

int main( int argc, char* argv[] ){
	
	int t;
	
	REP( i, LCKSZ ) wanted[ lck[i] ] = 1;
	
	scanf("%d", &t );
	while( t-- ){
		
		scanf("%s", L );
		scanf("%s", R );
		
		int sz;
		int x = solve( L, sz = strlen(L) );
		int y = solve( R, strlen(R) );
		
		int occ = 0;
		REP( i, sz ) occ += ((L[i]=='4')||(L[i]=='7'));
		
		int ans = (((y-x)%MOD)+MOD)%MOD;
		ans += islucky(occ); ans %= MOD;
		
		printf("%d\n", ans);
	}
		
	return 0;
}

























