// Paste me into the FileEdit configuration dialog

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

int wins[33][16][16][16][16];
bool seen[33][16][16][16];

class BallGift {
public:
	void play( int N, int G, int R, int B ){
		if( seen[N][G][R][B] ) return;
		seen[N][G][R][B] = true;
		if( G+R+B == 0 ){
			wins[N][G][R][B][0] += 1;
			return;
		}
		if( G ){
			play( N, G-1, R, B );
			REP( i, N ) wins[ N ][ G ][ R ][ B ][ i ] += wins[ N ][ G-1 ][ R ][ B ][ (i-1+N)%N ];
		}
		if( R ){
			play( N, G, R-1, B );
			REP( i, N ) wins[ N ][ G ][ R ][ B ][ i ] += wins[ N ][ G ][ R-1 ][ B ][ (i+1)%N ]; 
		}
		if( B ){
			play( N-1, G, R, B-1 );
			FOR( i, 1, N-1 ) wins[ N ][ G ][ R ][ B ][ i ] += wins[ N-1 ][ G ][ R ][ B-1 ][ i-1 ];
		}
	}
	int bestPosition( int players, int green, int red, int black ) {
		FILL( wins, 0 ); FILL( seen, false );
		play( players, green, red, black );
		int ans = 0;
		REP( i, players ) ans = MAX( ans, wins[players][green][red][black][i] );
		REP( i, players ) if( wins[players][green][red][black][i] == ans ) return i;
		return 0;
	}
};




// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
