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
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1111

const int64 MOD = 0xfaceb00c;
int64 dp[MAXN];

string s;
int n, m;

int64 solve( int pos ){
	
	if( pos == n ) return 1;
	
	int64 &ret = dp[pos];
	
	if( ret == -1 ){
		
		ret = 0;
		int x = 0;
		
		while( x <= m && pos < n ){
			
			x = 10*x + (s[pos]-'0');
			if(  1 <= x && x <= m ) ret += solve( pos+1 );
			if( x == 0 ) break;
			
			ret %= MOD;
			pos++;
		}
		
	}
	return ret;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	
	cin >> t;
	FOR( tc, 1, t ){
		cin >> m;
		cin >> s;
		
		n = SIZE(s);
		REP( i, n ) dp[i] = -1;
		
		cout << "Case #" << tc << ": " << solve( 0 ) << "\n";
	}
	
	return 0;
}




















