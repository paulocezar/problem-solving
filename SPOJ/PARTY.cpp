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

int fee[111], fun[111], parties;
int dp[111][555];
int calc[111][555], calc_now;

int solve( int pos, int budget ){
	if( pos == parties ) return 0;
	
	int &res = dp[pos][budget];
	int &last_calc = calc[pos][budget];
	if( last_calc == calc_now ) return res;
	last_calc = calc_now;
	res = solve( pos+1, budget );
	if( budget >= fee[pos] ) res = max( res, fun[pos]+solve(pos+1,budget-fee[pos]) );
	return res;
}

int solve2( int pos, int totalfun ){
	if( pos == parties ) return totalfun?INF:0;
	
	int &res = dp[pos][totalfun];
	int &last_calc = calc[pos][totalfun];
	if( last_calc == calc_now ) return res;
	last_calc = calc_now;	
	res = solve2(pos+1,totalfun);
	if( totalfun >= fun[pos] ) res = min( res, fee[pos]+solve2(pos+1,totalfun-fun[pos]) );
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int budget;
	while( (cin >> budget >> parties) && (budget || parties) ){
		
		REP( i, parties ) cin >> fee[i] >> fun[i];
		calc_now++;
		int res = solve( 0, budget );
		calc_now++;
		cout << solve2(0,res) << " " << res << "\n";
	}
	
	return 0;
}

























