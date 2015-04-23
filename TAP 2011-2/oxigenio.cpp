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

#define OK(x,y) ((x>=0)&&(x<n)&&(y>=0)&&(y<n))
#define MAXN 25

int dist[MAXN][MAXN];
int grid[MAXN][MAXN];
int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, n;
	cin >> t;
	while( t-- ){
		cin >> n;
		REP( i, n ) REP( j, n ){ 
			cin >> grid[i][j];
			dist[i][j] = INF;
		}
		dist[0][0] = 0;
		priority_queue< pair<int,int> > q; q.push( MP(0,0) );
		while( !q.empty() ){
			int dis = -q.top().first;
			int x = q.top().second; q.pop();
			int y = x%100; x /= 100;
			REP( dir, 4 ){
				int nx = x+ds[dir][0];
				int ny = y+ds[dir][1];
				if( OK(nx,ny) && ABS(grid[x][y]-grid[nx][ny]) <= 2 ){
					int ndist = (((grid[nx][ny]>grid[0][0])||(grid[x][y]>grid[0][0]))?(1):(0)) + dis;
					if( ndist < dist[nx][ny] ){
						dist[nx][ny] = ndist;
						q.push( MP(-ndist,100*nx+ny) );
					}
				}
			}
		}
		if( dist[n-1][n-1] == INF ) cout << "Inexiste passagem\n\n";
		else cout << dist[n-1][n-1] << "\n\n";
		
	}
	
	return 0;
}




















