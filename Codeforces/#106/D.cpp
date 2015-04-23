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

const int64 MOD = 1000000007LL;

#define MAXN 701

int64 dp[MAXN][MAXN][3][3];

string S;

int64 solve( int from, int to, int lf, int rt ){
	if( from > to ) return 1;
	
	int64 &ans = dp[from][to][lf][rt];
	if( ans == -1 ){
		
		ans = 0;
		int j = from+1;
		int acum = 0;
		while( j <= to ){
			if( S[j] == ')' && acum == 0 ) break; 
			acum += ((S[j]=='(')?(+1):(-1));
			j++;
		}
		
		if( lf != 1 ){
			ans += ((solve(from+1, j-1, 1, 0)*solve(j+1,to,0,rt))%MOD);
			ans %= MOD;
		}
		if( j!=to || (j==to && 1 != rt ) ){
			ans += ((solve(from+1, j-1, 0, 1)*solve(j+1,to,1,rt))%MOD);
			ans %= MOD;
		}
		if( lf != 2 ){
			ans += ((solve(from+1, j-1, 2, 0)*solve(j+1,to,0,rt))%MOD);
			ans %= MOD;
		}
		if( j!=to || (j==to && 2 != rt ) ){
			ans += ((solve(from+1, j-1, 0, 2)*solve(j+1,to,2,rt))%MOD);
			ans %= MOD;
		}
	}
	
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cin >> S;	
	int N = SIZE(S);
	
	REP( i, N ) FOR( j, i, N-1 ) REP( k, 3 ) REP( l, 3 ) dp[i][j][k][l] = -1;
	
	cout << solve( 0, N-1, 0, 0 ) << "\n";
	
	return 0;
}




















