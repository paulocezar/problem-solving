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

/*
int64 solve( int lsq, int grt, int has, int pos ){
	
	if( has > 777 ) return 0;
	if( pos == N ) return lucky[has];
	
	int64 &ret = dp[lsq][grt][has][pos];
	if( memo[lsq][grt][has][pos] == cur_test ) return ret;
	memo[lsq][grt][has][pos] = cur_test;
	
	if( pos == 0 ){
		
		ret = 0;
		int lo = (L[pos]-'0');
		int hi = (R[pos]-'0');
		FOR( i, lo, hi ){ ret += solve( (i==hi), (i>lo), has+((i==4)||(i==7)), pos+1 ); ret %= MOD; }
		
	} else {
		
		ret = 0;
		int lo = (grt?(0):(L[pos]-'0'));
		int hi = (lsq?(R[pos]-'0'):(9));
		FOR( i, lo, hi ){ ret += solve( lsq && (i==hi), grt || (i>lo) , has+((i==4)||(i==7)), pos+1 ); ret %= MOD; }
		
	}
	
	return ret;
}
*/

#define LCKSZ 14
int lck[] = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777 };

char L[1010], R[1010];

const int MOD = 1000000007;
int dp[2][2][2][778];

inline bool isdig( char c ){ return ('0'<=c&&c<='9'); }

int main( int argc, char* argv[] ){
	
	
	int t;
	scanf("%d", &t );
	
	int ans[t];
	
	REP( ct, t ){
		
		int N = 0;
		while( !isdig(L[N] = getchar_unlocked()) ); N++;
		while( isdig(L[N] = getchar_unlocked()) ) N++;
		
		int NL = N;  N = 0;
		while( !isdig(R[N] = getchar_unlocked()) ); N++;
		while( isdig(R[N] = getchar_unlocked()) ) N++;
		
		int dif = (N-NL);
		
		REP( i, 2 ) REP( j, 2 ) REP( k, 778 ) dp[0][i][j][k] = 0; 
		REP( x, LCKSZ ) REP( i, 2 ) REP( j, 2 ) dp[0][i][j][ lck[x] ] = 1;
		
		int lo, hi, old = 0, cur = 1;
		
		RREP( pos, N ){
			
			REP( lsq, 2 ) REP( grt, 2 ) REP( has, 778 ){

				int ret = 0;
				
				if( pos == 0 ){
					lo = ((((pos-dif)>=0)?L[pos-dif]:'0')-'0');
					hi = (R[pos]-'0');
					FOR( i, lo, hi ){ 
						if( has+((i==4)||(i==7)) <= 777 ){
							ret += dp[old][ (i==hi) ][ (i>lo) ][ has+((i==4)||(i==7)) ];
							if( ret >= MOD ) ret -= MOD;
						}
					}
				} else {
					lo = (grt?(0):((((pos-dif)>=0)?L[pos-dif]:'0')-'0'));
					hi = (lsq?(R[pos]-'0'):(9));
					FOR( i, lo, hi ){
						if( has+((i==4)||(i==7)) <= 777 ){
							ret += dp[old][ lsq && (i==hi) ][ grt || (i>lo) ][ has+((i==4)||(i==7)) ];
							if( ret >= MOD ) ret -= MOD;
						}
					}
				}
				
				dp[cur][lsq][grt][has] = ret;
			}
			old = !old;
			cur = !cur;
		}
		
		ans[ct] = dp[old][0][0][0];
		
	}
	
	REP( ct, t ) printf("%d\n", ans[ct] );
	
	return 0;
}

























