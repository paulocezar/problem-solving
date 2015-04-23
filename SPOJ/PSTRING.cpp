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

#define MAXN1 10010
#define MAXN2 1010

char x[MAXN1], y[MAXN2];

int n1, n2, p[MAXN2];
int nxt[MAXN2][26];
int dp[2][MAXN2];

int solve( int i, int j ){
	if( i == n1 ) return 0;
	int &r = dp[i][j];
	if( r == -1 ){
		r = 1 + solve( i+1, j );
		if( x[i] == y[j] ) j++;
		else j = p[j];
		if( j != n2 ) r = min( r, solve(i+1,j) );
	}
	return r;
}

int main( int argc, char* argv[] ){
	
	while( gets(x) ){
		gets(y);
		n1 = strlen(x);
		n2 = strlen(y);
		
		p[0] = 0, p[1] = 0;
		FOR( i, 1, n2-1 ){
			int j = p[i];
			while( y[i] != y[j] ){
				if( j == 0 ){ j = -1; break; }
				j = p[j];
			}
			p[i+1] = j+1; 
		}
		
		REP( i, n2 ){
			REP( j, 26 ){
				
				int k = i;
				while( k > 0 && y[k] != j+'a' )
					k = p[k];
					
				if( y[k] == j+'a' ) k++;
				nxt[i][j] = k;
				
			}
		}
		
		REP( i, n2 ) dp[0][i] = 0; dp[0][n2] = INF;
		int old = 0, cur = 1;
		
		RREP( i, n1 ){
			REP( j, n2 ){
				dp[cur][j] = 1+dp[old][j];
				if( nxt[j][ x[i]-'a' ] != n2 )
					dp[cur][j] = min( dp[cur][j], dp[old][nxt[j][x[i]-'a']] );
			}
			old = !old;
			cur = !cur;
		}
		
		printf("%d\n", dp[old][0] );
			
	}
	return 0;
}




















