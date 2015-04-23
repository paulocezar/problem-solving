#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 111
vector< int > gr[MAXN];
int ans[MAXN][MAXN];
bool seen[MAXN], seen2[MAXN];

void dfs( int u ){
	seen[u] = true;
	REP( i, SIZE(gr[u]) ) if( !seen[ gr[u][i] ] ) dfs( gr[u][i] );
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, tc = 1, N;
	
	cin >> t;
	while( t-- ){
		cin >> N;
		REP( i, N ){
			gr[i].clear(); seen[i] = false;
			REP( j, N ){
				cin >> ans[i][j];
				if( ans[i][j] ) gr[i].PB( j );
			}
		}
		dfs( 0 );
		REP( i, N ){ seen2[i] = seen[i]; ans[0][i] = seen[i]; }
		FOR( i, 1, N-1 ){
			
			REP( j, N ) seen[j] = false;
			seen[i] = true;
			dfs( 0 );
			seen[i] = false;
			REP( j, N ){
				if( seen2[j] && !seen[j] ) ans[i][j] = 1;
				else ans[i][j] = 0;
			}
		} 
		cout << "Case " << tc++ << ":\n";
		REP( i, N ){ 
			cout << "+-"; REP( x, N-1 ) cout << "--"; cout << "+\n|";
			REP( j, N ) cout << ( (ans[i][j])?('Y'):('N') ) << "|";
			cout << "\n";
		}
		cout << "+-"; REP( x, N-1 ) cout << "--"; cout << "+\n";
	}
	
	return 0;
}




















