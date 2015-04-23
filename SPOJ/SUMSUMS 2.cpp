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

const int64 mod = 98765431LL;

#define MAXN 50000
int64 C[MAXN];

int main( int argc, char* argv[] ){
	
	int N;
	int64 T, sum = 0;
	
	scanf("%d %lld", &N, &T );
	int odd = (T&1LL);
	
	REP( i, N ){ scanf("%lld", C+i ); sum += C[i]; sum %= mod; }
	
	if( N==1 ) puts("0");
	else if( N==2 ){
		if( odd ) printf("%lld %lld\n", C[1], C[0] );
		else printf("%lld %lld\n", C[0], C[1] );
	} else {
		
		int64 a00 = N-2, a01 = N-1;
		int64 a10 =   1, a11 =   0;
		
		int64 b00 =   1, b01 =   0;
		int64 b10 =   0, b11 =   1;
		int64 x, y, z, w;
		
		while( T ){
			
			if( T&1 ){
				x = ((b00*a00)%mod + (b01*a10)%mod)%mod;
				y = ((b00*a01)%mod + (b01*a11)%mod)%mod;
				z = ((b10*a00)%mod + (b11*a10)%mod)%mod;
				w = ((b10*a01)%mod + (b11*a11)%mod)%mod;
				b00 = x, b01 = y, b10 = z, b11 = w;
			}
			
			x = ((a00*a00)%mod + (a01*a10)%mod)%mod;
			y = ((a00*a01)%mod + (a01*a11)%mod)%mod;
			z = ((a10*a00)%mod + (a11*a10)%mod)%mod;
			w = ((a10*a01)%mod + (a11*a11)%mod)%mod;
			a00 = x, a01 = y, a10 = z, a11 = w;
			
			T >>= 1;
		}
		
		sum *= b10; sum %= mod;
		if( odd ) REP( i, N ) printf("%lld\n", (((sum-C[i])%mod)+mod)%mod );
		else REP( i, N ) printf("%lld\n", (sum+C[i])%mod );
		
	}
	
	
	return 0;
}

























