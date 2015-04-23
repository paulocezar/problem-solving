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

#define MAXN 222

int n, l, k;
double p[MAXN];
int a[MAXN];

char memo[201][201][444];
double dp[201][201][444];

double solve(int at, int needwin, int space ){
	
	if( at == -1 ) return (needwin==0 && space >= 201);
	
	if( memo[at][needwin][space] ) return dp[at][needwin][space];
	memo[at][needwin][space] = 1;
	
	dp[at][needwin][space] = p[at]*solve(at-1,max(0,needwin-1),min(space+a[at],400)) + (1.0-p[at])*solve(at-1,needwin,space);
	
	return dp[at][needwin][space];
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	cin >> n >> l >> k;
	
	double x;
	REP( i, n ){
		cin >> x;
		p[i] = x/100.0;
	}
	
	REP( i, n ) cin >> a[i];
	
	cout << fixed << setprecision(10) << solve( n-1, l, k+201 ) << "\n";
		
	return 0;
}

























