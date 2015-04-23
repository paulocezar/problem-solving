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

string cur;

int64 dp[2][20][200];
int memo[2][20][200];
int cur_test;

int64 go( int lsq, int pos, int has ){
	if( has < 0 ) return 0;
	if( pos == SIZE(cur) ) return (has==0);
	
	int64 &ret = dp[lsq][pos][has];
	if( memo[lsq][pos][has] == cur_test ) return ret;
	memo[lsq][pos][has] = cur_test;
	
	if( pos == 0 ){
		
		ret = 0;
		int lim = (cur[pos]-'0');
		REP( i, lim+1 ){ ret += go( (i==lim), pos+1, has-i ); }
		
	} else {
		
		ret = 0;
		int lim = (lsq?(cur[pos]-'0'):(9));
		REP( i, lim+1 ){ ret += go( lsq && (i==lim), pos+1, has-i ); }
		
	}
	
	return ret;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	string A, B;
	
	FILL( memo, 0 );
	cur_test = 0;
	
	cin >> t;
	while( t-- ){
		
		int64 X;
		cin >> A >> B >> X;
		
		int x  = SIZE(A)-1;
		while( x >= 0 ){
			if( A[x] == '0' ){ A[x] = '9'; x--; }
			else{ A[x]--; break; }
		}
		while( (SIZE(A) > 1) && *A.begin() == '0' ) A.erase( A.begin() );
		
		
		int64 ans = 0;
		
		for( int64 i = 1LL; i <= 162LL; i++ ){
			cur = B; cur_test++;
			int64 x = go( 0, 0, i );
			cur = A; 
			if( A != "0" ){ cur_test++; x -= go( 0, 0, i ); }
			
			int64 now = min( x, X/i );
			ans += now;
			X -= now*i;
			
			if( X < i ) break;
		}
		
		cout << ans << "\n";
	}

	return 0;
}

























