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

#define MAXK 100000
int x[MAXK];
int K;

int solve( int N, int sz ){
	int lo = 0, hi = K-1;
	while( hi >= 0 && x[hi] > sz ) hi--;
	int ans = 0;
	while( hi >= 0 && x[hi] == sz && N ) hi--, N--, ans++;
	while( N && hi > lo ){
		if( x[lo]+x[hi] == sz ){ ans += 2; N--; lo++, hi--; }
		else if( x[lo]+x[hi] < sz ) lo++;
		else hi--;
	}
	if( N ) return INF;
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int M, N, L;
	while( cin >> M >> N ){
		cin >> L;
		cin >> K;
		REP( i, K ) cin >> x[i];
		sort( x, x+K );
		
		int ans = INF;
		if( ((N*100) % L) == 0 ) ans = min( ans, solve((N*100)/L, M) );
		if( ((M*100) % L) == 0 ) ans = min( ans, solve((M*100)/L, N) );
		
		if( ans == INF ) cout << "impossivel\n";
		else cout << ans << "\n";
	}
	
	return 0;
}




















