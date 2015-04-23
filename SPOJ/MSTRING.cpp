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

#define ALPH 26
#define MAXN 1010

int dp[MAXN][MAXN];
int next[ALPH][MAXN];
int N1, N2;
char s1[MAXN], s2[MAXN];

int solve( int i, int j ){
	
	if( i == N1 ) return INF;
	if( j == N2 ) return 1;
	
	if( dp[i][j] == -1 ){
		
		if( next[s1[i]-'a'][j] == -1 )
			dp[i][j] = 1;
		else {
			dp[i][j] = solve( i+1, j );
			dp[i][j] = min( dp[i][j], 1 + solve( i+1, next[s1[i]-'a'][j]+1 ) );
		}
		
	}
	return dp[i][j];
}

int main( int argc, char* argv[] ){
	
	scanf("%s%s", s1, s2);
	N1 = strlen(s1);
	N2 = strlen(s2);
	
	REP( i, N1 ) REP( j, N2 ) dp[i][j] = -1;
	
	REP( i, ALPH ){
		next[i][N2] = -1;
		RREP( j, N2 ){
			if( s2[j] == char(i+'a') ) next[i][j] = j;
			else next[i][j] = next[i][j+1];
		}
	}
	
	printf("%d\n", solve(0,0) );
	
	return 0;
}




















