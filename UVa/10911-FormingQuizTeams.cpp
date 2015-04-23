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

#define MAXN 16
int N, x[MAXN], y[MAXN];
char memo[1<<MAXN];
double d[MAXN][MAXN], dp[1<<MAXN]; 

double solve( int mask ){
	if( mask == 0 ) return 0.;
	if( !memo[mask] ){
		dp[mask] = INF;
		REP( i, N ) if( mask & (1<<i) ){
			FOR( j, i+1, N-1 ) if( mask & (1<<j) ){
				dp[mask] = MIN( dp[mask], d[i][j] + solve( ( mask ^ (1<<i) ) & ( mask ^ (1<<j) ) ) );
			}
			break;
		}
		memo[mask] = 1;
	}
	return dp[mask];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	string trsh;
	int tc = 1;

	while( (cin>>N) && N ){
		N *= 2;
		REP( i, N )
			cin >> trsh >> x[i] >> y[i];
		REP( i, N )
			FOR( j, i+1, N-1 )
				d[i][j] = d[j][i] = sqrt( SQR(x[i]-x[j])+SQR(y[i]-y[j]) );
		memset( memo, 0, (1<<N)*sizeof(char) );
		cout << "Case " << tc++ << ": " << fixed << setprecision(2) << solve( (1<<N)-1 ) << "\n";
	}
	
	return 0;
}




















