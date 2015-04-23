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

#define MAXR 301
#define MAXC 301
#define NMOVES 3

int dp[MAXR][MAXC][NMOVES];
int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };



int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	while( t-- ){
		
		int R, C;
		cin >> R >> C;
		string grid[R];
		REP( i, R ) cin >> grid[i];
		
		int xs, ys, xe, ye;
		
		REP( i, R ) REP( j, C ){
			if( grid[i][j] == 'S' ) xs = i, ys = j;
			else if( grid[i][j] == 'E' ) xe = i, ye = j;
			REP( k, NMOVES ) dp[i][j][k] = INF;
		}
		
		dp[xs][ys][0] = 0;
		queue< pair< int, pair<int,int> > > q;
		q.push( mp( xs, mp( ys, 0 ) ) );
		while( !q.empty() ){
			xs = q.front().first;
			ys = q.front().second.first;
			int ks = q.front().second.second;
			q.pop();
			
			int nk = ks+1; if( nk == 3 ) nk = 0;
			
			REP( dir, 4 ){
				int nx, ny;
				nx = xs, ny = ys;
				bool ok = true;
				REP( rr, ks+1 ){
					nx += ds[dir][0];
					ny += ds[dir][1];
					if( nx < 0 || nx >= R || ny < 0 || ny >= C || grid[nx][ny] == '#' ){ ok = false; break; }
				}
				if( ok && dp[xs][ys][ks]+1 < dp[nx][ny][nk] ){
					dp[nx][ny][nk] = dp[xs][ys][ks]+1;
					q.push( mp( nx, mp( ny, nk ) ) );
				}
			}
		
		}
		
		int ans = MIN( dp[xe][ye][0], MIN( dp[xe][ye][1], dp[xe][ye][2] ) );
		if( ans == INF ) cout << "NO\n";
		else cout << ans << "\n";
		
	}
	
	return 0;
}


































