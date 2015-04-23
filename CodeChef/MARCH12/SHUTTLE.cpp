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

int fstpw(int a, int b){
	int res = 1;
	while( b ){
		if( b&1 ) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int phi( int n ){
	int res = 1;
	int limit = (int)sqrt(n) + 1;

	for(int i = 2; i <= limit; i++ ){
        if( (n % i) == 0 ){
			int xp = 0;
			while((n % i) == 0){
				xp++;
				n /= i;
			}
			res *=  fstpw( i, xp - 1)*(i - 1);
			if(n == 1) return res;
		}
	}
	
	if(n != 1) res *= (n - 1);
	return res;
}

int main( int argc, char* argv[] ){
	
	int t, n;
	scanf("%d", &t );
	while(t--){
		scanf("%d", &n );
		printf("%d\n", phi(n) );
	}
		
	return 0;
}

























