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

#define MAXN 100000
int k, a[MAXN];

map< int, int > neg, pos;
int nneg, npos;
int zeroes;

int64 get_best(){
	int64 res = 0;
	
	if( nneg <= k || npos <= k ){
		FORIT( guy, neg ) res -= ((guy->first)*(guy->second));
		FORIT( guy, pos ) res += ((guy->first)*(guy->second));
	}
	
	int64 positivesum = 0, negativesum = 0;
	
	FORIT( guy, pos ) positivesum += ((guy->first)*(guy->second));
	FORIT( guy, neg ) negativesum += ((guy->first)*(guy->second));
	
	
	
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n, len;
	
	cin >> n >> len;
	REP( i, n ) cin >> a[i];	
	cin >> k;
	
	nneg = 0, npos = 0;
	REP( i, len ){
		if( a[i] > 0 ){ pos[ a[i] ]++; npos++; }
		else if( a[i] < 0 ){ neg[ a[i] ]++; nneg++; }
		else zeroes++;
	}
	
	int64 ans = get_best();
	FOR( i, len, n-1 ){
		if( a[i-len] > 0 ){ pos[ a[i] ]--; npos--; }
		else if( a[i-len] < 0 ){ neg[ a[i] ]--; nneg--; }
		else zeroes--;
		
		if( a[i] > 0 ){ pos[ a[i] ]++; npos++; }
		else if( a[i] < 0 ){ neg[ a[i] ]++; nneg++; }
		else zeroes++;
		ans = max( ans, get_best() );
	}
	cout << ans << "\n";
			
	return 0;
}

























