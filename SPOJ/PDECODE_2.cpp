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

#define MAXN 88

int N;
int pot[32][MAXN];


char pos[MAXN];
char w[MAXN];

int main( int argc, char* argv[] ){
	
	int m;
	
	while( scanf("%d %d", &N, &m ) && (N+m) ){
		
		REP( i, N ){
			scanf("%d", &pot[0][i] );
			pot[0][i]--;
		}
		
		getchar();
		gets(w);
		
		FOR( i, 1, 30 ) REP( j, N ) pot[i][j] = pot[ i-1 ][ pot[i-1][j] ];
		
		REP( i, 31 ) if( m & (1<<i) ){
			REP( j, N ) pos[ pot[i][j] ] = w[ j ];
			REP( j, N ) w[j] = pos[j];
		}
		w[N] = '\0';
		puts(w);
	}
	
	return 0;
}

























