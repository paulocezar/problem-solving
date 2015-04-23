#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 C[50001][32];

int main( int argc, char* argv[] ){
		
	C[0][0] = 1; C[0][1] = 0;
	FOR( i, 1, 50001 ){
		C[i][0] = 1;
		FOR( j, 1, MIN(i+1, 31) )
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		C[i][MIN(i+1, 31)] = 0;
	}
	
	long long N; int K;
	scanf("%lld %d", &N, &K );
	if( K == 1 ){
		printf("%lld\n", N );
	} else {
		FOR( T, 1, 50001 ){
			int64 cur = 0;
			int k = 1;
			while( C[T][k] && k <= K && cur < N ){
				cur += C[T][k++];
			}
			if( cur >= N ){
				printf("%d\n", T );
				break;
			}
		}
	}
	
	return 0;
}




















