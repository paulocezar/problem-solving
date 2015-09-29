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

#define MAXN 111

int64 a[MAXN], b[MAXN];
int A[MAXN], B[MAXN], N, M;

char calc[MAXN][MAXN], calc_now;
int64 dp[MAXN][MAXN];

int64 solve( int cura, int curb ){
	if( cura == N || curb == M ) return 0;
	
	int64 &res = dp[cura][curb];
	if( calc[cura][curb] == calc_now ) return res;
	calc[cura][curb] = calc_now;
	res = max( solve(cura+1,curb), solve(cura,curb+1) );
	if( A[cura] == B[curb] ){
		int64 aacum = 0;
		FOR( aa, cura, N-1 ){
			if( A[aa] == A[cura] ){
				aacum += a[aa];
				int64 bacum = 0;
				FOR( bb, curb, M-1 ){
					if( B[bb] == A[aa] ){
						bacum += b[bb];
						res = max( res, min(aacum,bacum)+solve(aa+1,bb+1) );
					}
				}
			}
		}
	}
	return res;
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	FOR( tc, 1, t ){
		cin >> N >> M;
		REP( i, N ) cin >> a[i] >> A[i];
		REP( i, M ) cin >> b[i] >> B[i];
		calc_now++;
		cout << "Case #" << tc << ": " << solve(0,0) << "\n";
	}
	
	
	return 0;
}

























