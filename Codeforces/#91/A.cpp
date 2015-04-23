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

vector< int64 > lucky;
void gen( int64 cur ){
	if( cur > 7777777777LL ) return;
	if( cur ) lucky.PB( cur );
	gen( 10LL*cur + 4LL );
	gen( 10LL*cur + 7LL );
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	lucky.clear();
	gen( 0 );
	sort( ALL(lucky) );
	
	int64 l, r;
	cin >> l >> r;
	
	vector< int64 >::iterator beg = lower_bound( ALL(lucky), l );
		
	int64 ans = 0;
	int64 last = l-1;
	
	while( last <= r ){
		if( beg == lucky.end() ) break;
		int64 cur = *beg;
		
		ans += min( (cur-last),(r-last) )*cur;
		last = cur;
		
		beg++;
	}
	
	cout << ans << "\n";
	
	return 0;
}




















