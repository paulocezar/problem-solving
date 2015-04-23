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

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n;
	cin >> n;
	int a[n];
	
	int each = 0;
	int acm = 0;
	REP( i, n ){ cin >> a[i]; acm += a[i]; }
	each = acm/n;
	
	if( each*n != acm ){
	cout << "Unrecoverable configuration.\n";
	return 0;	
	}
	
	int d = 0;
	int f, t;
	f = t = -1;
	
	REP( i, n ) if( a[i] != each ){
		d++;
		if( f == -1 ) f = i;
		else t = i;
	}
	
	if( d == 0 ) cout << "Exemplary pages.\n";
	else if( d == 2 ){
		if( a[f] < a[t] ) cout << each-a[f] << " ml. from cup #" << f+1 << " to cup #" << t+1 << ".\n";
		else cout << each-a[t] << " ml. from cup #" << t+1 << " to cup #" << f+1 << ".\n";
	} else cout << "Unrecoverable configuration.\n";
	
	
	return 0;
}




















