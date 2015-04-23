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

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector< string > grid;
int mp[101][101];
int sz[10001];
int cur, N, M;
int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void flood( int i, int j ){
	if( i < 0 || j < 0 || i >= N || j >= M || grid[i][j] != '#' ) return;
	grid[i][j] = 'X';
	mp[i][j] = cur;
	sz[cur]++;
	REP( x, 4 ) flood( i+ds[x][0], j+ds[x][1] );
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int K, L, C;
	cin >> N >> M;
	
	grid.resize( N );
	
	REP( i, N ) cin >> grid[i];
	cin >> K;
	
	FILL( sz, 0 );
	cur = 0;
	REP( i, N ) REP( j, M ) if( grid[i][j] == '#' ){ flood( i, j ); cur++; } 
		
	REP( i, K ){
		cin >> L >> C; L--; C--;
		if( grid[L][C] != '.' ){ sz[mp[L][C]]--; grid[L][C] = '.'; }
	}
	int ans = 0;
	REP( i, cur ) ans += (sz[i] == 0);
	cout << ans << '\n';
	
	return 0;
}
