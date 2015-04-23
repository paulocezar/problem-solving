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

#define MAXN 1000
#define XTR_TRNS 10

int dp[2][XTR_TRNS][2];
//int calc[2][XTR_TRNS][2], calc_now;

int N, up[MAXN], down[MAXN];


/*int solve( int dir, int made, int pos ){
	
	if( pos == N ) return 0;
		
	int &res = dp[dir][made][pos];
	
	int &last_calc = calc[dir][made][pos];
	if( last_calc == calc_now ) return res;
	last_calc = calc_now;
	
	res = INF;
	
	int opp = (dir?down[pos]:up[pos]);
	int xtr = 0;
	while( xtr < XTR_TRNS ){
		res = min( res, xtr*26 + opp + solve( 1-dir, xtr, pos+1) );
		xtr++;
	}
	
	int ndd = (dir?up[pos]:down[pos]);
	
	int fll = made;
	int cur = (pos?( dir?(up[pos-1]):(down[pos-1]) ):(0));
	
	if( cur >= ndd ){
		
		res = min( res, solve(dir, fll, pos+1) );
		
		fll++;
		int cst = 26-cur+ndd;
		
		while( fll < XTR_TRNS ){
			res = min( res, cst + solve(dir, fll, pos+1) );
			fll++;
			cst += 26;
		}
		
	} else {
		
		if( fll ){
			fll--;
			res = min( res, solve(dir, fll, pos+1) );
			fll++;
			
			int cst = ndd-cur;
			while( fll < XTR_TRNS ){
				res = min( res, cst+solve(dir, fll, pos+1) );
				fll++;
				cst += 26;
			}
		} else {
			int cst = ndd-cur;
			
			while( fll < XTR_TRNS ){
				res = min( res, cst + solve(dir,fll,pos+1) );
				fll++;
				cst += 26;
			}	
		}
		
	}
	
	return res;	
} */


char x[MAXN+1];

inline void readx(){
	N = 0;
	x[N] = getchar_unlocked();
	while( !(('a' <= x[N] && x[N] <= 'z') || (x[N] == '*')) ) x[N] = getchar_unlocked();
	while( (('a' <= x[N] && x[N] <= 'z') || (x[N] == '*')) ){
		N++;
		x[N] = getchar_unlocked();
	}
}

int main( int argc, char* argv[] ){
	
	readx();
	while( x[0] != '*' ){
		
		REP( i, N ) up[i] = int(x[i]-'a');
		REP( i, N ) down[i] = (26-int(x[i]-'a'))%26;
		
		
		int old = 0;
		int cur = 1;
		
		REP( i, 2 ) REP( j, XTR_TRNS ) dp[i][j][0] = 0;
		
		RREP( pos, N ){
			REP( dir, 2 ) REP( made, XTR_TRNS ){
				
				int &res = dp[dir][made][cur];

				
				res = INF;

				int opp = (dir?down[pos]:up[pos]);
				int xtr = 0;
				while( xtr < XTR_TRNS ){
					res = min( res, xtr*26 + opp + dp[ 1-dir ][ xtr ][ old ] );
					xtr++;
				}

				int ndd = (dir?up[pos]:down[pos]);

				int fll = made;
				int cur = (pos?( dir?(up[pos-1]):(down[pos-1]) ):(0));

				if( cur >= ndd ){

					res = min( res, dp[dir][ fll ][ old ] );

					fll++;
					int cst = 26-cur+ndd;

					while( fll < XTR_TRNS ){
						res = min( res, cst + dp[dir][ fll ][old] );
						fll++;
						cst += 26;
					}

				} else {

					if( fll ){
						fll--;
						res = min( res, dp[dir][fll][old] );
						fll++;

						int cst = ndd-cur;
						while( fll < XTR_TRNS ){
							res = min( res, cst+dp[dir][fll][old] );
							fll++;
							cst += 26;
						}
					} else {
						int cst = ndd-cur;

						while( fll < XTR_TRNS ){
							res = min( res, cst + dp[dir][fll][old] );
							fll++;
							cst += 26;
						}	
					}

				}
				
				
			}
			old = !old;
			cur = !cur;
		}
		
		
		//calc_now++;
		printf("%d\n", dp[ 0 ][ 0 ][ old ] );
		readx();
	}

	return 0;
}


























