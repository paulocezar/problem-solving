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

char gr[26][26], dp[26][26];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	string line;
	cin >> t;
	while( t-- ){
		
		FILL( gr, 0 );
		vector< string > edges;
		
		cin >> line;
		while( line != "**" ){
			edges.PB( line );
			gr[line[0]-'A'][line[1]-'A'] = 1;
			gr[line[1]-'A'][line[0]-'A'] = 1;
			cin >> line;
		}
		
		int ans = 0;
		REP( e, SIZE(edges) ){
			memcpy(dp, gr, sizeof(gr));
			dp[edges[e][0]-'A'][edges[e][1]-'A'] = 0;
			dp[edges[e][1]-'A'][edges[e][0]-'A'] = 0;
				
			REP(k, 26) REP(i,26) REP(j,26)
				dp[i][j] = dp[i][j] | (dp[i][k] & dp[k][j]);
				
			if( !dp[0][1] ){ cout << edges[e] << "\n"; ans++; }
		}
		cout << "Existem " << ans << " estradas a bombardear.\n";		
	}
	
	return 0;
}




















