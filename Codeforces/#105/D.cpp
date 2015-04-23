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

char memo[1001][1001];
double dp[1001][1001];

double solve( int w, int b ){
	if( w < 0 || b < 0 ) return 0;
	if( w+b == 0 ) return 0;
	if( b == 0 ) return 1;
	if( !memo[w][b] ){
		memo[w][b] = 1;
		
		double pgw = double(w)/(w+b);
		double pgb = double(b)/(w+b);
		double pdgb = (w+b-1)?(double(b-1)/(w+b-1)):(0);
		
		dp[w][b] = pgw;
		dp[w][b] += pgb*( pdgb*(solve(w, b-3)+solve(w-1, b-2)) );
	}
	return dp[w][b];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 9 );
	int w, b;
	cin >> w >> b;
	REP( i, w+1 ) REP( j, b+1 ) memo[i][j] = 0;
	cout << solve( w, b ) << "\n";
	
	return 0;
}




















