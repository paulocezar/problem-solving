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

#define MAXN 27
bool gr[MAXN][MAXN], seen[MAXN];
int days[MAXN], tsort[MAXN], dp[MAXN], pos;

void dfs( int u ){
	seen[u] = true;
	REP( v, MAXN ) if( gr[u][v] && !seen[v] ) dfs( v );
	tsort[--pos] = u;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t, d;
	cin >> t; cin.ignore(); cin.ignore();
	while( t-- ){
		FILL( gr, false ); FILL( seen, false ); FILL( days, 0 );
		string line, pre;
		char from;
		while( getline( cin, line ) && SIZE(line) ){
			istringstream in(line);
			in >> from >> d >> pre;
			days[ from-'A' ] = d;
			REP( i, SIZE(pre) ) gr[pre[i]-'A'][from-'A'] = true;
		}
		pos = MAXN;
		REP( i, MAXN ) if( !seen[i] ) dfs( i );
		
		int ans = 0;
		REP( i, MAXN ){
			dp[i] = days[i];
			RFOR( j, i-1, 0 ) if( gr[j][i] && dp[j]+days[i] > dp[i] ){
				dp[i] = dp[j]+days[i];
			}
			ans = MAX( ans, dp[i] );
		}
		cout << ans << "\n";
		if( t ) cout << "\n";
	}
	
	return 0;
}




















