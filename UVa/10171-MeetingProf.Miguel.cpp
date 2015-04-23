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

#define MAXN 30
int gr[MAXN][MAXN], gr2[MAXN][MAXN];


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, u, v, c;
	char a, t, cu, cv;
	
	while( (cin>>N) && N ){
		
		FILL( gr, INF ), FILL( gr2, INF );
		REP( i, N ){
			cin >> a >> t >> cu >> cv >> c; u = int(cu-'A'); v = int(cv-'A');
			if( a == 'Y' ){
				gr[u][v] = MIN( gr[u][v], c );
				if( t == 'B' ) gr[v][u] = gr[u][v];
			} else {
				gr2[u][v] = MIN( gr2[u][v], c );
				if( t == 'B' ) gr2[v][u] = gr2[u][v];
			}
		}
		cin >> cu >> cv; u = int(cu-'A'), v = int(cv-'A');
		
		REP( i, 26 ) gr[i][i] = 0, gr2[i][i] = 0;
		REP( k, 26 )
			REP( i, 26 )
			REP( j, 26 )
			gr[i][j] = MIN( gr[i][j], gr[i][k]+gr[k][j] ),
			gr2[i][j] = MIN( gr2[i][j], gr2[i][k]+gr2[k][j] );
	
		int ans = INF;
		REP( k, 26 )
			ans = MIN( ans, gr[u][k]+gr2[v][k] );
		if( ans == INF ) cout << "You will never meet.\n";
		else {
			cout << ans;
			REP( k, 26 )
				if( gr[u][k]+gr2[v][k] == ans ) cout << ' ' << char(k+'A'); 
			cout << "\n";
		}
	}
	
	return 0;
}




















