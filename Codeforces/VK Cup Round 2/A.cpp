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

typedef unsigned long long hash;

#define BASE 33ULL
#define VALUE(c) ( (c)-'a'+1 )

const int64 MOD = 1000000007LL;

string s, t;
int ssz, tsz;

map< hash, int64 > hpn;
map< hash, int64 > dp[5555];

int64 calc( hash pref, int pos ){
	if( pos == tsz ) return (hpn[pref]%MOD);
	if( dp[pos].count(pref) ) return dp[pos][pref];
	dp[pos][pref] = calc( pref, pos+1 ) + calc( (pref*BASE)+VALUE(t[pos]), pos+1 );
	dp[pos][pref] %= MOD;
	return dp[pos][pref];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	cin >> s >> t;
	ssz = SIZE(s);
	tsz = SIZE(t);
	
	hpn.clear();
	REP( beg, ssz ){
		hash h = 0;
		FOR( end, beg, tsz-1 ){
			h = h*BASE + VALUE(s[end]);
			hpn[h]++;
		} 
	}
	
	cout << calc( 0, 0 ) << "\n";
	
	
	return 0;
}

























