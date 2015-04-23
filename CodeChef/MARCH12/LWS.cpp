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

char s[2012];

int dp[2][26][26];
int n;

/*int solve( int inc, int dec, int pos ){
	if( pos == n ) return 0;
	int &ret = dp[inc][dec][pos];
	if( ret != -1 ) return ret;
	
	ret = solve( inc, dec, pos+1 );
	if( s[pos]-'a' >= inc ) ret = max( ret, 1+solve(s[pos]-'a',dec,pos+1) );
	if( s[pos]-'a' <= dec ) ret = max( ret, 1+solve(inc,s[pos]-'a',pos+1) );
	return ret;
}*/

int main( int argc, char* argv[] ){
	
	int t;
	scanf("%d", &t ); getchar();
	while( t-- ){
		gets(s);
		n = strlen(s);
		
		REP( i, 26 ) REP( j, 26 ) dp[0][i][j] = 0;
		int cur = 1;
		int old = 0;
		RREP( pos, n ){
			REP( inc, 26 ) REP( dec, 26 ){
				dp[cur][inc][dec] = dp[old][inc][dec];
				if( s[pos]-'a' >= inc ) dp[cur][inc][dec] = max( dp[cur][inc][dec], 1+dp[old][s[pos]-'a'][dec] );
				if( s[pos]-'a' <= dec ) dp[cur][inc][dec] = max( dp[cur][inc][dec], 1+dp[old][inc][s[pos]-'a'] );
			}
			old = !old;
			cur = !cur;
		}
		
		printf("%d\n", dp[old][0][25] );
	}
		
	return 0;
}

























