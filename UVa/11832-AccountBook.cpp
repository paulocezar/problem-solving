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
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char dp[44][80011];
char sgn[44];
int acm, N, F, t[44];
string ans;

bool play( int pos, int val ){

	if( pos == N ) return (val == F);
	if( dp[pos][val+acm] ) return ( dp[pos][val+acm] != '*' );

	bool pls = play( pos+1, val+t[pos] );
	bool mns = play( pos+1, val-t[pos] );

	if( pls && mns )
		dp[pos][val+acm] = '?';
	else if( pls )
		dp[pos][val+acm] = '+';
	else if( mns )
		dp[pos][val+acm] = '-';
	else dp[pos][val+acm] = '*';
	if( dp[pos][val+acm] != '*' ){
		if( ans[pos] == '.' ) ans[pos] = dp[pos][val+acm];
		else if( ans[pos] != dp[pos][val+acm] ) ans[pos] = '?';
	}
	return (dp[pos][val+acm] != '*' );
}

void build( int pos, int val ){

	if( pos == N-1 ){	
		return;
	}
	
	bool pls = (dp[ pos+1 ][ val+t[pos]+acm ] > 0);
	bool mns = (dp[ pos+1 ][ val-t[pos]+acm ] > 0);

	if( pls && mns ){
		dp[pos][val+acm] = '?';
	} else if( pls ){
		dp[pos][val+acm] = '+';
	} else if( mns ){
		dp[pos][val+acm] = '-';
	}
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cin >> N >> F;
	while( N || F ){
		
		acm = 0;
		REP( i, N ){
			cin >> t[i];
			acm += t[i];
		}
		
		REP( i, N )
			REP( j, 2*acm+1 )
				dp[i][j] = 0;
		
		ans = "";
		REP( i, N ) ans += ".";	
		if( play( 0, 0 ) ){
			cout << ans << "\n";
		} else cout << "*\n";
		
		cin >> N >> F;
	}
	
	return 0;
}




















