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

char L[1024], R[1024];

char seen[1<<22];
int dp[1<<22];

inline bool isdig( char c ){ return (('0'<=c)&&(c<='9')); }

inline int encode( int a, int b, int c, int d ){
	d <<= 10;
	d |= c;
	d <<= 1;
	d |= b;
	d <<= 1;
	d |= a;
	return d;
}

const int64 MMOD = 1000000007LL;
inline int gmd( int64 x ){ return int(x%MMOD); }

int main( int argc, char* argv[] ){
	
	#define LCKSZ 14
	int lck[] = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777 };
	
	int t; int MOD = 1000000007;
	char seen_now = 0;
	
	scanf("%d", &t );
	
	REP( ct, t ){
		
		int N = 0;
		while( !isdig(L[N] = getchar_unlocked()) ); L[N++] -= '0';
		while( isdig(L[N] = getchar_unlocked()) ) L[N++] -= '0'; 
		
		int NL = N;  N = 0;
		while( !isdig(R[N] = getchar_unlocked()) ); R[N++] -= '0';
		while( isdig(R[N] = getchar_unlocked()) ) R[N++] -= '0';
		
		int dif = (N-NL);
		
		seen_now++;
		queue< int > q;
		
		int lo, hi;
		REP( lk, LCKSZ ) if( lck[lk] <= N ){
			
			lo = (dif?0:L[0]);
			hi = (R[0]);
			
			FOR( i, lo, hi ){ 
				int xxx = encode( i==hi, i>lo, lck[lk]-((i==4)||(i==7)), 1 );
				
				if( seen[ xxx ] != seen_now ){

					seen[ xxx ] = seen_now;
					dp[ xxx ] = 1;

					if( N > 1 ) q.push( xxx );

				} else dp[ xxx ]++;

			}
			
		}		
		
		int cstate, lsq, grt, has, pos, nlsq, ngrt, nhas, nstate;
		while( !q.empty() ){
			
			cstate = q.front(); q.pop();
			int xxx = cstate;
			
			lsq = (xxx&1); xxx >>= 1;
			grt = (xxx&1); xxx >>= 1;
			has = (xxx&1023); xxx >>= 10;
			pos = (xxx&1023);
			
			if( grt ) lo = 0;
			else lo = ((pos>=dif)?(L[pos-dif]):(0));
			
			hi = (lsq?(R[pos]):(9));
		
			if( lo == hi ){
				nlsq = lsq;
				ngrt = grt;
				nhas = has-((lo==4)||(hi==7));
				if( nhas >= 0 ){

					nstate = encode( nlsq, ngrt, nhas, pos+1 );

					if( seen[ nstate ] != seen_now ){

						seen[ nstate ] = seen_now;
						dp[ nstate ] = dp[ cstate ];

						if( pos+1 < N ) q.push( nstate );

					} else {
						dp[ nstate ] += dp[cstate];
						if( dp[nstate] >= MOD ) dp[ nstate ] -= MOD;
					}

				}
				continue;
			}
			
			nlsq = 0;
			ngrt = grt;
			nhas = has-((lo==4)||(lo==7));
			if( nhas >= 0 ){
				
				nstate = encode( nlsq, ngrt, nhas, pos+1 );
			
				if( seen[ nstate ] != seen_now ){

					seen[ nstate ] = seen_now;
					dp[ nstate ] = dp[ cstate ];

					if( pos+1 < N ) q.push( nstate );

				} else {
					dp[ nstate ] += dp[cstate];
					if( dp[nstate] >= MOD ) dp[ nstate ] -= MOD;
				}
			
			}
			
			ngrt = 1;
			int64 hm = ((lo<4)&&(4<hi)) + ((lo<7)&&(7<hi));
			int64 hm2 = max(hi-lo-1-int(hm), 0);
			
			nhas = has-1;
			if( hm && (nhas >= 0) ){
				nstate = encode( nlsq, ngrt, nhas, pos+1 );
			
				if( seen[ nstate ] != seen_now ){

					seen[ nstate ] = seen_now;
					dp[ nstate ] = gmd(int64(hm)*dp[cstate]);

					if( pos+1 < N ) q.push( nstate );

				} else {
					dp[ nstate ] += gmd(int64(hm)*dp[cstate]);
					if( dp[nstate] >= MOD ) dp[ nstate ] -= MOD;
				}
			}
			
			nhas = has;
			if( hm2 && (nhas >= 0) ){
				nstate = encode( nlsq, ngrt, nhas, pos+1 );
			
				if( seen[ nstate ] != seen_now ){

					seen[ nstate ] = seen_now;
					dp[ nstate ] = gmd(int64(hm2)*dp[cstate]);

					if( pos+1 < N ) q.push( nstate );

				} else {
					dp[ nstate ] += gmd(int64(hm2)*dp[cstate]);
					if( dp[nstate] >= MOD ) dp[ nstate ] -= MOD;
				}
			}
			
			
			nlsq = lsq;
			nhas = has-((hi==4)||(hi==7));
			if( nhas >= 0 ){
				nstate = encode( nlsq, ngrt, nhas, pos+1 );
			
				if( seen[ nstate ] != seen_now ){

					seen[ nstate ] = seen_now;
					dp[ nstate ] = dp[ cstate ];

					if( pos+1 < N ) q.push( nstate );

				} else {
					dp[ nstate ] += dp[cstate];
					if( dp[nstate] >= MOD ) dp[ nstate ] -= MOD;
				}
			}
		}
		
		int ans = 0;
		REP( i, 2 ) REP( j, 2 ){
			int now = encode(i,j,0,N);
			if( seen[ now ] == seen_now ){
				ans += dp[ encode(i,j,0,N) ];
				if( ans >= MOD ) ans -= MOD;
			}
		}
		printf("%d\n", ans );
		
	}
	
	
	return 0;
}

























