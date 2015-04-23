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

const int64 mod = 1000000007LL;

int64 dp[222][3333];
bool calc[222][3333];

int n, was[222], length[222], width[222];

int64 solve( int last, int len ){
	if( len < 0 ) return 0;
	if( len == 0 ) return 1;
	
	int64 &res = dp[last][len];
	if( calc[last][len] ) return res;
	calc[last][len] = true;
	
	res = 0;
	REP( i, n ) if( was[i] != was[last] && width[last] == length[i] ){
		res += solve( i, len-length[i] );
		res %= mod;
	}
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int l;
	cin >> n >> l;
	
	REP( i, n ){ cin >> length[i] >> width[i]; was[i] = i; }
	
	int n2 = n;
	REP( i, n ) if( length[i] != width[i] ){
		length[n2] = width[i];
		width[n2] = length[i];
		was[n2] = i;
		n2++;
	}
	
	n = n2;
	int64 res = 0;
	REP( i, n ){
		res += solve( i, l-length[i] ); res %= mod;
	}
	cout << res << "\n";
		
	return 0;
}

























