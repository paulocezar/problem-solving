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

#define MAXN 111
int64 k[MAXN], c[MAXN];
int tp[MAXN];

bool comp( int a, int b ){
	if( c[a] != c[b] ) return c[a] < c[b];
	return k[a] > k[b];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	
	REP( i, n ){
		cin >> k[i] >> c[i];
		tp[i] = i;
	}
	sort( tp, tp+n, comp );
	
	int t;
	cin >> t;
	
	int64 p[t+1];
	REP( i, t ) cin >> p[i];	
	p[t] = 1e16;
	
	int64 ans = 0;
	int f = 1;
	int tt = 0;
	int64 d = 0;
	
	while( tt < n && f <= t ){
		int type = tp[tt];
		
		if( d+k[type] > p[f-1] ){
			
			int64 nxt = d+k[type] - p[f-1];
			int64 cur = k[type]-nxt;
			d += cur;
			
			k[type] = nxt;
			ans += cur*int64(f)*c[type];
			f++;
			
		} else {
			d += k[type];
			ans += k[type]*int64(f)*c[type];
			tt++;
		}
		
	}
	
	while( tt < n ){
		int type = tp[tt];
		
		ans += int64(f)*k[type]*c[type];
		tt++;
	}
	
	cout << ans << "\n";
		
	return 0;
}

























