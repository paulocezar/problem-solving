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

int64 next_int(){
	int64 res = 0LL;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10LL*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;	
}

int main( int argc, char* argv[] ){

	int64 N, M, t; 
	
	t = next_int();
	while( t-- ){
		N = next_int();
		M = next_int();
		
		int64 cl = int64( ceil(double(N)/M));
		int64 fl = int64( floor(double(N)/M));
		
		int64 X = N % M, ans;
		
		if( X == 0LL ){
			
			ans = (cl)*(cl-1LL)/2LL;  // (0,0)		
			if( !(M&1LL) ){ ans += cl*(cl-1LL)/2LL; M--; } 
			ans += ((M-1LL)/2LL)*cl*cl;
			
		} else {
			
			int64 lg = max( 0LL, min( X, M-X-1LL ) );
			int64 gl = max( 0LL, M - max(X+1LL, M-X) );
			int64 ll = max( 0LL, 2LL*X-M+1LL );
			int64 gg = max( 0LL, M-2LL*X-1LL );
		
			ans = fl*(fl-1LL)/2LL;  // (0,0)		
			
			if( !(M&1LL) ){	
				// M/2  M/2
				if( M/2LL <= X ){
					ans += cl*(cl-1LL)/2LL;
					ll = max(0LL, ll-1LL);
				} else {
					ans += fl*(fl-1LL)/2LL;
					gg = max(0LL, gg-1LL);
				}
			}
			
			// <=X >X
			ans += cl*fl*lg/2LL;
			// >X <=X
			ans += cl*fl*gl/2LL;
			// <=X <=X
			ans += cl*cl*ll/2LL;
			// >X >X
			ans += fl*fl*gg/2LL;
			
			
		}
		printf("%lld\n", ans);
		
	}

	
	return 0;
}

























