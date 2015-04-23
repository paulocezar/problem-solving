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

int64 l[MAXN], x[MAXN], y[MAXN];

inline int64 next_int() {
	int64 n = 0, neg = 1;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
	}
	while ('0' <= c && c <= '9') {
		n = (n * 10LL) + (c - '0');
		c = getchar_unlocked();
	}
	return neg*n;
}

int main( int argc, char* argv[] ){
	
	//ios::sync_with_stdio( false );
	
	int64 N;
	N = next_int();
	while( N ){
		
		REP( i, N ){
			l[i] = next_int();
			x[i] = next_int();
			y[i] = next_int();
		}
		
		int64 cur, grt, lss, ans;
		
		REP( mask, 4 ){
			
			int64 term[3];
			REP( i, 3 ) if(mask & (1<<i) ) term[i] = 1; else term[i] = -1;
			
			grt = term[0]*l[0] + term[1]*x[0] + term[2]*y[0];
			lss = term[0]*l[1] + term[1]*x[1] + term[2]*y[1];
			
			if( grt < lss ) swap( grt, lss );
			
			FOR( i, 2, N-1 ){
				cur = term[0]*l[i] + term[1]*x[i] + term[2]*y[i];
				if( cur > grt ) grt = cur;
				if( cur < lss ) lss = cur;
			}
			
			if( mask==0 ) ans = (grt-lss);
			if( (grt-lss)>ans ) ans = grt-lss;
			if( (lss-grt)>ans ) ans = lss-grt;
		}
		
		printf("%lld\n", ans );
		N = next_int();
		
	}
	
			
	return 0;
}

























