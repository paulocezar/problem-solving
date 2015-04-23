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

string s;
int n;

const int64 MOD = 1000000007LL;

int memo[55][111];
int cur_test;

int64 dp[55][111];

int64 solve( int dif, int pos ){
	
	if( ('a' <= char(s[pos]-dif)) && (char(s[pos]-dif) <= 'z') ){
		
		if( pos == n-1 ) return 1;
		
		int64 &ret = dp[dif+26][pos];
		if( memo[dif+26][pos] == cur_test ) return ret;
		memo[dif+26][pos] = cur_test;
		ret = 0;
		
		char cur = char(s[pos]-dif);
		for( char now = 'a'; now <= 'z'; now++ ){
			ret += solve( int(now-cur), pos+1 );
			//ret %= MOD;
		}
			
		return ret;
		
	} else return 0;
	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	
	FILL( memo, 0 );
	cur_test = 0;

	int t;
	cin >> t;
	while( t-- ){
		
		cin >> s;
		n = SIZE(s);
		cur_test++;
		cout << solve(0,0) << endl;
		int64 ans = (solve( 0, 0 ) - 1LL + MOD)%MOD;
		cout << ans << "\n";
		
	}
	
		
	return 0;
}

























