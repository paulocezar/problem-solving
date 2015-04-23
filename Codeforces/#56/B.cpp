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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	int K, N, M;
	int z, x, y;
	
	cin >> K >> N >> M;
	
	int dir[6][3] = { { -1, 0, 0}, { 1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}  };
	
	string grid[K][N];
	
	REP( i, K ){
		REP( j, N ) cin >> grid[i][j];
	}
	
	cin >> x >> y;
	x--, y--;
	
	
	list< pair< int, pair< int, int > > > q;
	
	q.pb( mp( 0, mp(x, y) ) );
	
	int ans = 0;
	while( !q.empty() ){
		z = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second; q.pop_front();
		
		if( grid[z][x][y] == '#' ) continue;
		ans++;
		grid[z][x][y] = '#';
		
		REP( i, 6 ){
			if( z+dir[i][0] >= 0 && z+dir[i][0] < K ){
			if( x+dir[i][1] >= 0 && x+dir[i][1] < N ){
			if( y+dir[i][2] >= 0 && y+dir[i][2] < M ){
				if( grid[z+dir[i][0]][x+dir[i][1]][y+dir[i][2]] == '.' )
					q.pb( mp( z+dir[i][0], mp( x+dir[i][1], y+dir[i][2] ) ) );
			}
			}
			}
		}
		
	}
	cout << ans << endl;
	
	return 0;
}
