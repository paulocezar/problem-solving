/*
 *  Problema:
 *  Tecnica Utilizada:  
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1001
int64 bit[MAXN][MAXN];

int N, M;
int64 getXupYdown( int x, int y ){
	int64 ans = 0;
	int xx, yy;
	
	xx = N;
	while( xx > 0 ){
		yy = y;
		while( yy > 0 ){
			ans += bit[xx][yy];
			yy -= ( yy & -yy );
		}
		xx -= ( xx & -xx );
	}
	
	while( x > 0 ){
		yy = y;
		while( yy > 0 ){
			ans -= bit[x][yy];
			yy -= ( yy & -yy );
		}
		x -= ( x & -x );
	}
	
	return ans;
}

int64 getXdownYup( int x, int y ){
	int yy;
	int64 ans = 0;
	while( x > 0 ){
		yy = M;
		while( yy > 0 ){
			ans += bit[x][yy];
			yy -= ( yy & -yy );
		}
		yy = y;
		while( yy > 0 ){
			ans -= bit[x][yy];
			yy -= ( yy & -yy );
		}
		x -= ( x & -x );
	}
	return ans;
}

void up( int x, int y ){
	int yy;
	while( x <= N ){
		yy = y;
		while( yy <= M ){
			bit[x][yy]++;
			yy += ( yy & -yy );
		}		
		x += ( x & -x );
	}
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T, K, x, y;
	cin >> T;
	FOR( tc, 1, T+1 ){
		
		cin >> N >> M >> K;
		FILL( bit, 0 );
		
		int64 ans = 0;
		while( K-- ){
			cin >> x >> y;
			ans += ( getXupYdown( x, y-1 ) + getXdownYup( x-1, y ) );
			up( x, y );
		}
		cout << "Test case " << tc << ": " << ans << "\n";
		
	}
	
	return 0;
}
