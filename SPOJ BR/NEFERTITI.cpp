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
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 101
#define MAXK 6

struct bigint {
	char s[100];
	
	bigint& operator += ( const bigint& x ){
		
		int i = 0, j = 0, cr = 0;
		
		while( (s[i] >= 0) && (x.s[j] >= 0) ){
			if( s[i]+x.s[j]+cr < 10 ){ s[i] += (x.s[j]+cr); cr = 0; }
			else{ s[i] += (x.s[j]+cr-10); cr = 1; }
			i++, j++; 
		}
		while( s[i] >= 0 ){
			if( s[i]+cr < 10 ){ s[i] += cr; cr = 0; }
			else{ s[i] += (cr-10); cr = 1; }
			i++;
		}
		while( x.s[j] >= 0 ){
			if( x.s[j]+cr < 10 ){ s[i++] = x.s[j]+cr; cr = 0; }
			else{ s[i++] = x.s[j]+cr-10; cr = 1; }
			j++;
		}
		if( cr ) s[i++] = 1;
		s[i] = -1;
		return *this;
	}
	void print(){
		int i = 0; while( s[i] >= 0 ) i++; i--;
		while( i >= 0 ) cout << char( s[i--]+'0' );
		cout << "\n";
	}
};

bool memo[MAXN+1][1<<(2*MAXK + 1)];
bigint dp[MAXN+1][1<<(2*MAXK + 1)];
int N, K, kk, fl;

void solve( int pos, int mask ){
	if( !memo[pos][mask] ){
		memo[pos][mask] = true;
		dp[pos][mask].s[0] = 0; dp[pos][mask].s[1] = -1;
		if( pos == N ){ 
			if( mask == (1<<(K+1))-1 ){ dp[pos][mask].s[0] = 1; dp[pos][mask].s[1] = -1; }
		} else {
			REP( i, kk ) if( mask & (1<<i) ){
				solve( pos+1, (((mask ^ (1<<i)) << 1) | 1) & fl );
				dp[pos][mask] += dp[ pos+1 ][ (((mask ^ (1<<i)) << 1) | 1) & fl ];
			}
		}
	}
	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		cin >> N >> K;
		kk = 2*K + 1; 
		fl = (1<<kk) - 1;
		REP( i, N+1 ) REP( j, 1<<kk ) memo[i][j] = false;
		solve( 0, ((1<<(K+1))-1) & fl );
		dp[ 0 ][ ((1<<(K+1))-1) & fl ].print();
	}
	return 0;
}















