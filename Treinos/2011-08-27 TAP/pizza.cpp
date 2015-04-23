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

int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

#define OK(a,b) ((a>=0)&&(a<r)&&(b>=0)&&(b<c)&&(grid[a][b]!='*'))

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t, r, c;
	cin >> t;
	while( t-- ){
		cin >> r >> c;
		int seen[r][c];
		string grid[r];
		REP( i, r ) cin >> grid[i];
		queue< pair<int,int> > q;
		q.push( MP(0, 0) );
		REP( i, r ) REP( j, c ) seen[i][j] = INF;
		seen[0][0] = 1;
		while( !q.empty() ){
			int x = q.front().first;
			int y = q.front().second; q.pop();
			switch( grid[x][y] ){
				case '+':
					REP( i, 4 ){
						
						int nx = x+ds[i][0];
						int ny = y+ds[i][1];
						
						if( OK(nx, ny) && seen[x][y]+1 < seen[nx][ny] ){
							q.push( MP(nx,ny) );
							seen[nx][ny] = seen[x][y]+1;
						}
					}
					break;
				case '-':
					REP( i, 4 ){
						i++;
						
						int nx = x+ds[i][0];
						int ny = y+ds[i][1];
						
						if( OK(nx, ny) && seen[x][y]+1 < seen[nx][ny] ){
							q.push( MP(nx,ny) );
							seen[nx][ny] = seen[x][y]+1;
						}
					}
					break;
				case '|':
					REP( i, 4 ){
						
						int nx = x+ds[i][0];
						int ny = y+ds[i][1];
						
						if( OK(nx, ny) && seen[x][y]+1 < seen[nx][ny] ){
							q.push( MP(nx,ny) );
							seen[nx][ny] = seen[x][y]+1;
						}
						i++;
					}
					break;
			} 
		}
		if( seen[r-1][c-1] == INF ) seen[r-1][c-1] = -1;
		cout << seen[r-1][c-1] << "\n";
	}
	return 0;
}




















