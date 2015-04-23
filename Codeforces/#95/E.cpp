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

struct queen_t{
	int x, y, w;
	queen_t( int xx = 0, int yy = 0, int ww = 0 ) : x(xx), y(yy), w(ww) {}
	void rotate(){
		int ax = x-y;
		int ay = x+y;
		x = ax;
		y = ay;
	}
	bool operator < ( const queen_t& a ) const {
		if( x != a.x ) return x < a.x;
		return y < a.y;
	}
};

bool comp( const queen_t& a, const queen_t& b ){
	if( a.y != b.y ) return a.y < b.y;
	return a.x < b.x;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n, m;
	cin >> n >> m;
	queen_t queen[m];
	
	for( int i = 0; i < m; i++ ){
		cin >> queen[i].x >> queen[i].y;
		queen[i].w = 0;
	}
	
	for( int t = 0; t < 2; t++ ){
		
		if( t ) for( int i = 0; i < m; i++ ) queen[i].rotate();
		
		sort( queen, queen+m );
		
		for( int i = 0; i < m; i++ ){
			if( i && queen[i-1].x == queen[i].x ) queen[i].w++;
			if( i+1 < m && queen[i+1].x == queen[i].x ) queen[i].w++;
		}
		
		sort( queen, queen+m, comp );
		
		for( int i = 0; i < m; i++ ){
			if( i && queen[i-1].y == queen[i].y ) queen[i].w++;
			if( i+1 < m && queen[i+1].y == queen[i].y ) queen[i].w++;
		}
	}
	
	int t[9];
	FILL( t, 0 );
	for( int i = 0; i < m; i++ )
		t[ queen[i].w ]++;
	
	cout << t[0];
	for( int i = 1; i < 9; i++ ) cout << " " << t[i];
	cout << "\n";
	
	return 0;
}




















