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

const int64 MOD = 1000000007LL;
const int DIM = 3;

struct matrix{
	int64 a, b, c, d, e, f, g, h, i;
	matrix( int64 aa = 0, int64 bb = 0, int64 cc = 0,
			int64 dd = 0, int64 ee = 0, int64 ff = 0,
			int64 gg = 0, int64 hh = 0, int64 ii = 0 ) : 
			a(aa%MOD), b(bb%MOD), c(cc%MOD), 
			d(dd%MOD), e(ee%MOD), f(ff%MOD), 
			g(gg%MOD), h(hh%MOD), i(ii%MOD) {}
	matrix	operator *(const matrix& x) {
		return matrix( a*x.a + b*x.d + c*x.g,a*x.b + b*x.e + c*x.h,a*x.c + b*x.f + c*x.i,
					   d*x.a + e*x.d + f*x.g,d*x.b + e*x.e + f*x.h,d*x.c + e*x.f + f*x.i,
					   g*x.a + h*x.d + i*x.g,g*x.b + h*x.e + i*x.h,g*x.c + h*x.f + i*x.i);
	}
};

int main( int argc, char* argv[] ){
	
	//ios::sync_with_stdio( false );
	
	int t;
	int64 n, nn;
	
	scanf("%d", &t );
	while( t-- ){
		
		
		matrix ans(1,0,0,0,1,0,0,0,1);
		matrix tr(1,1,1,0,2,3,0,3,5);
		
		scanf("%lld", &n );
		nn = n;
		while( nn > 0 ){
			if( nn&1LL ) ans = ans*tr;
			tr = tr*tr;
			nn >>= 1;
		}
		
		if( n == 0 ) puts("0");
		else printf("%lld\n", (ans.b+ans.c)%MOD );
		
	}
	
	return 0;
}




















