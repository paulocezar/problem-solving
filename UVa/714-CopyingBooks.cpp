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

#define MAXM 555
int64 p[MAXM];
int m, k;
bool ok( int64 mid ){
	int64 now = 0;
	int i = 0, j = 0;
	while( i < m && j < k ){
		now += p[i];
		if( now > mid ){
			now = p[i];
			j++;
		}
		if( j == k ) return false;
		i++;
	}
	if( i == m ) return true;
	return false;
}

vector< int > ans;
void build( int64 mx ){
	ans.clear();
	int64 now = 0;
	int i = m-1, j = 0;
	while( i >= k-j-1 ){
		now += p[i];
		if( now > mx ){
			ans.PB( -1 );
			now = p[i];
			j++;
		}
		ans.PB( p[i] );
		i--;
	}
	while( i >= 0 ){
		ans.PB( -1 );
		ans.PB( p[i--] );
	}
	RREP( i, SIZE(ans) ){
		if( i != SIZE(ans)-1 ) cout << " ";
		if( ans[i] == -1 ) cout << "/";
		else cout << ans[i];
	}
	cout << "\n";
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		cin >> m >> k;
		int64 lo = 0, hi = 0;
		REP( i, m ){
			cin >> p[i];
			hi += p[i];
			lo = MAX( lo, p[i] );
		}
		int64 mid, ans = hi;
		while( lo <= hi ){
			mid = lo + (hi-lo)/2LL;
			if( ok( mid ) ){
				ans = mid;
				hi = mid-1LL;
			} else lo = mid+1LL;
		}
		build( ans );
	}
	
	return 0;
}




















