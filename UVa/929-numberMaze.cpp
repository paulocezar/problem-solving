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

#define MAXN 1001

int maze[MAXN][MAXN];
int dist[MAXN][MAXN];
int ds[][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int tsts;
	int N, M;
	int d, x, y, nx, ny;
	
	cin >> tsts;
	while( tsts-- ){
		cin >> N >> M;
	
		REP( i, N ) REP( j, M ){
			cin >> maze[i][j];
			dist[i][j] = INF;
		}
		
		dist[0][0] = maze[0][0];
		priority_queue< pair<int, pair<int, int> > > q;
		q.push( mp( -dist[0][0], mp(0, 0) ) );
		
		while( !q.empty() ){
			d = -q.top().first;
			x = q.top().second.first;
			y = q.top().second.second; q.pop();
			
			if( d > dist[x][y] ) continue;
			if( (x == N-1) && (y == M-1) ) break;
			
			REP( i, 4 ){
				nx = x+ds[i][0];
				ny = y+ds[i][1];
				if( nx >= 0 && nx < N && ny >= 0 && ny < M ){
					if( (dist[x][y]+maze[nx][ny]) < dist[nx][ny] ){
						dist[nx][ny] = dist[x][y]+maze[nx][ny];
						q.push( mp( -dist[nx][ny], mp(nx, ny) ) );
					}
				}
			}
		}
		
		cout << dist[N-1][M-1] << "\n";
	}
	
	return 0;
}
