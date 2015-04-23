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

#define MAXN 100000
int x[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, N, C;
	cin >> t;
	while( t-- ){
		cin >> N >> C;
		REP( i, N ) cin >> x[i];
		sort( x, x+N );
		
		int lo = 0;
		int hi = x[N-1]-x[0]+1;
		int ans;
		
		while( lo <= hi ){
			
			int mid = lo + (hi-lo)/2;
			int out = C-1;
			int last = 0;
			int now = 1;
			while( out > 0 ){
				while( now < N && x[now]-x[last] < mid ) now++;
				if( now < N ){
					out--;
					last = now;
				} else break;
				now++;
			}
			
			if( out == 0 ){
				ans = mid;
				lo = mid+1;
			} else {
				hi = mid-1;
			}
			
		}
		cout << ans << "\n";
		
	}
	
	return 0;
}




















