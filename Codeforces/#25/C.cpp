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
#include <bitset>

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

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n, k;
	cin >> n;
	int64 d[n][n];
	REP( i, n ) REP( j, n ) cin >> d[i][j];
	
	int64 cur = 0;
	REP( i, n )
		FOR( j, i+1, n-1 ) cur += d[i][j];
	
	cin >> k;
	while( k-- ){
		int u, v; int64 c;
		cin >> u >> v >> c; u--, v--;
		
		int64 old = d[u][v];
		d[u][v] = MIN(d[u][v],c);
		d[v][u] = d[u][v];
		
		if( old > d[u][v] ){
			cur -= old;
			cur += d[u][v];
			REP( i, n ) REP( j, n ){
				if( d[i][u]+d[u][v]+d[v][j] < d[i][j] ){
					cur -= d[i][j];
					d[i][j] = d[i][u]+d[u][v]+d[v][j];
					d[j][i] = d[i][j];
					cur += d[i][j];
				}
			}
		}
		
		cout << cur;
		if( k ) cout << " ";
		else cout << "\n";
	}
	
	
	return 0;
}




















