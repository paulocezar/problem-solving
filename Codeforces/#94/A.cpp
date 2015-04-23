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

string grid[8];
int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, {1,-1}, {-1,1}, {-1,-1}, {1,1}, {0,0} };

bool win( int x, int y, bool first = false ){
	if( x < 0 || y < 0 || x > 7 || y > 7 || grid[x][y] == 'S' ) return false;
	if( x == 0 && y == 7 ) return true;
	
	vector<int> removed;
	bool ans = false;
	bool done = false;
	
	if( !first ){
		bool good = true;
		for( int i = 7; i >= 0; i-- )
			for( int j = 0; j < 8; j++ ) if( grid[i][j] == 'S' ){
				if( i == 7 ) removed.PB(j);
				else {
					if( i+1 == x && j == y ){
						done = true;
						ans = false;
					}
					
					grid[i+1][j] = 'S';
					good = false;
				}
				grid[i][j] = '.';
			}
		if( good ){
			done = true;
			ans = true;	
		}
	}
	
	for( int dir = 0; (!done && !ans) && dir < 9; dir++ ) if( win(x+ds[dir][0],y+ds[dir][1]) )
		ans = true;
	
	if( !first ){
		for( int i = 0; i < 7; i++ )
			for( int j = 0; j < 8; j++ ) if( grid[i+1][j] == 'S' ){
				grid[i+1][j] = '.';
				grid[i][j] = 'S';
			}
		for( size_t i = 0, sz = removed.size(); i < sz; i++ )
			grid[7][removed[i]] = 'S';
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	
	REP( i, 8 ) cin >> grid[i];
	
	if( win( 7, 0, true ) ) cout << "WIN\n";
	else cout << "LOSE\n";
	
	return 0;
}




















