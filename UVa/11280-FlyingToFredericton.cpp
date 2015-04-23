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

#define MAXN 111
#define MAXM 1111

int gr[MAXN][MAXN];
map< string, int > id;
int u[MAXM], v[MAXM], c[MAXM];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t, N, M, Q, stops;
	string su, sv;
	
	cin >> t;
	FOR( sc, 1, t ){
		
		cin >> N;
		REP( i, N ){
			cin >> su; id[su] = i;
		}
		
		FILL( gr, INF ); gr[0][0] = 0;
		
		cin >> M;
		REP( i, M ){
			cin >> su >> sv >> c[i];
			u[i] = id[su], v[i] = id[sv];
			if( u[i] == 0 ) gr[ 0 ][ v[i] ] = MIN( gr[0][v[i]], c[i] );
		}
		
		FOR( k, 1, N )
			REP( i, M )
				gr[k][ v[i] ] = MIN( gr[k][v[i]], MIN( gr[k-1][ v[i] ], gr[k-1][ u[i] ] + c[i] ) );
		
		cin >> Q;
		cout << "Scenario #" << sc << "\n";
		while( Q-- ){
			cin >> stops; stops = MIN( stops, N );
			if( gr[stops][N-1] != INF ) cout << "Total cost of flight(s) is $" << gr[stops][N-1] << "\n";
			else cout << "No satisfactory flights\n";
		}	
		if( sc < t ) cout << "\n";
	}
	
	return 0;
}




















