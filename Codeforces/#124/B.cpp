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
#include <bitset>
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

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool seen[1501][1501];


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int N, M;
	cin >> N >> M;
	
	string grid[N];
	REP( i, N ) cin >> grid[i];
	
	int sx, sy;
	REP( i, N ) REP( j, M ) if( grid[i][j] == 'S' ){
		grid[i][j] = '.';
		sx = i;
		sy = j;
		seen[i][j] = false;
	} else seen[i][j] = false;
	
	queue< pair<int,int> > q;
	q.push( MP(sx,sy) );
	seen[sx][sy] = true;
	
	while( !q.empty() ){
		sx = q.front().first;
		sy = q.front().second; q.pop();
		REP( dir, 4 ){
			int nx = sx + ds[dir][0];
			int ny = sy + ds[dir][1];
			if( 0 <= nx && nx < N && 0 <= ny && ny < M ){
				if( grid[nx][ny] == '.' && !seen[nx][ny] ){
					seen[nx][ny] = true;
					q.push( MP(nx,ny) );
				}
			}
		}
	}
	
	REP( i, N ){
		if( seen[i][0] && seen[i][M-1] ){ cout << "Yes\n"; return 0; }		
	}
	REP( j, M ){
		if( seen[0][j] && seen[N-1][j] ){ cout << "Yes\n"; return 0; }
	}
	
	cout << "No\n";
	
	return 0;
}

























