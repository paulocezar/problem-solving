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

#define MAXN 1000

const int MOD = 10007;
int N;

char seq[MAXN];

int dp[2][1000];

inline int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

inline char next_color(){
	char c = getchar_unlocked();
	while( c != 'B' && c != 'P' ) c = getchar_unlocked();
	return c;
}

int main( int argc, char* argv[] ){
	
	N = next_int();
	REP( i, N ) seq[i] = next_color();
	
	REP( i, N ) seq[i] = (seq[i]=='P')?1:0;
	
	RREP( i, N-1 ) if( seq[i+1] ) seq[i] = !seq[i];
	
	
	REP( remove_at, N ) dp[0][remove_at] = int(seq[0]);
	
	int old = 0, cur = 1;
	
	if( seq[0] ){
	FOR( piece, 1, N-1 ){
		
		REP( remove_at, N ){
			int &res = dp[cur][remove_at];
			res = remove_at?dp[cur][remove_at-1]:0;
			
			if( seq[piece] ) res += ((remove_at <= (piece-1))?( dp[old][piece-1] - (remove_at?dp[old][remove_at-1]:0) ):0);
			else if( remove_at ) res += dp[old][remove_at-1];
					
			res %= MOD;
			res += MOD;
			res %= MOD;
			
		}
		old = !old;
		cur = !cur;
	}
	}
	printf("%d\n", dp[old][N-1] );
		
	return 0;
}

























