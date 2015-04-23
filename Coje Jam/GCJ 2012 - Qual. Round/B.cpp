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

#define NORM 31
#define SURP 27

int norm_sum[NORM], norm_best[NORM];
int surp_sum[SURP], surp_best[SURP];

#define MAXN 111
#define MAXS MAXN

int calc[MAXN][MAXS], calc_now;
int ans[MAXN][MAXS];
int t[MAXN];

int N, p;

int solve( int pos, int surp_left ){
	if( pos == N ) return (surp_left?(-INF):(0));
	
	int &ret = ans[pos][surp_left];
	if( calc[pos][surp_left] == calc_now ) return ret;
	
	calc[pos][surp_left] = calc_now;
	ret = 0;
	
	REP( i, NORM ) if( norm_sum[i] == t[pos] )
		ret = max( ret, (norm_best[i]>=p) + solve(pos+1,surp_left) );
	
	if( surp_left ){
		REP( i, SURP ) if( surp_sum[i] == t[pos] )
			ret = max( ret, (surp_best[i]>=p) + solve(pos+1,surp_left-1) );
	}
	
	return ret;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int norm = 0, surp = 0;
	
	for( int x = 0; x <= 10; x++ )
	for( int y = x; y <= min(10,x+2); y++ )
	for( int z = y; z <= min(10,x+2); z++ )
		if( abs(x-y) == 2 || abs(x-z) == 2 || abs(y-z) == 2 ){
			surp_sum[surp] = x+y+z;
			surp_best[surp] = max( x, max(y,z) );
			surp++;
		} else {
			norm_sum[norm] = x+y+z;
			norm_best[norm] = max( x, max(y,z) );
			norm++;
		}
	
	int n_tsts, S;
	cin >> n_tsts;
	
	FOR( tc, 1, n_tsts ){
		
		cin >> N >> S >> p;
		REP( i, N ) cin >> t[i];
		
		calc_now++;
		cout << "Case #" << tc << ": " << solve(0,S) << "\n";
		
	}	
	
	return 0;
}

























