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
char aux[MAXN][MAXN], pot[MAXN][MAXN], ans[MAXN][MAXN];

void mult( char a[][MAXN], char b[][MAXN] ){
	REP( i, N ) REP( j, N ){
		aux[i][j] = 0;
		REP( k, N ) aux[i][j] |= (a[i][k]&b[k][j]);
	}
	REP( i, N ) REP( j, N ) a[i][j] = aux[i][j];
}

int pos[MAXN];
char w[MAXN];

int main( int argc, char* argv[] ){
	
	int m, x;
	
	while( scanf("%d %d", &N, &m ) && (N+m) ){
		REP( i, N ) REP( j, N ){
			ans[i][j] = (i==j);
			pot[i][j] = 0;
		}
		REP( i, N ){
			scanf("%d", &x );
			pot[x-1][i] = 1;
		}
		while( m ){
			if( m&1 ) mult(ans,pot);
			mult(pot,pot);
			m >>= 1;
		}
		
		getchar();
		gets(w);
		
		REP( i, N ) {
			int j = 0;
			while( !ans[i][j] ) j++;
			putchar( w[j] );
		}
		putchar('\n');
	}
	
	return 0;
}

























