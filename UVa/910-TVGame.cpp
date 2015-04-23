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
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 33

int gr[MAXN][2];
int dp[MAXN][MAXN];
int final[MAXN];

int solve( int pos, int moves ){
	if( !moves ) return final[pos];
	if( dp[pos][moves] == -1 ){
		dp[pos][moves] = solve( gr[pos][0], moves-1 ) + solve( gr[pos][1], moves-1 );
	}
	return dp[pos][moves];
}
	
int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	char u, v0, v1, fn;
	int N, M;
	
	while( cin >> N ){
		REP( i, N ){
			cin >> u >> v0 >> v1 >> fn;
			gr[u-'A'][0] = v0-'A';
			gr[u-'A'][1] = v1-'A';
			final[u-'A'] = (fn=='x');
		}
		cin >> M;
		REP( i, N )
			REP( j, M+1 ) dp[i][j] = -1;
		cout << solve( 0, M ) << "\n";
	}
	
	
	return 0;
}




















