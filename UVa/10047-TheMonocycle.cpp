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

#define MAXN 25 
#define COLORS 5

int ds[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

string grid[MAXN];
int seen[MAXN][MAXN][COLORS][4];
int N, M;
inline bool ok( int i, int j ){ return ((i>=0) && (j>=0) && (i<N) && (j<M) && grid[i][j] != '#'); }

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int tc = 1;
	int si, sj, ti, tj, ni, nj, clr, dir;
	bool first = true;
	
	while( (cin>>N>>M) && (N+M) ){
		if( !first ) cout << "\n";
		first = false;
		
		REP( i, N ){
			cin >> grid[i];
			REP( j, M ){
				if( grid[i][j] == 'S' ) si = i, sj = j;
				if( grid[i][j] == 'T' ) ti = i, tj = j;
				REP( k, COLORS )
					REP( l, 4 ) seen[i][j][k][l] = INF;
			}
		}
		
		seen[si][sj][0][0] = 0;
		queue< int > q; q.push( ((si*100 + sj )*10 + 0)*10 + 0 );
		while( !q.empty() ){
			si = q.front(); q.pop();
			dir = si%10; si /= 10;
			clr = si%10; si /= 10;
			sj = si%100; si /= 100;
			if( seen[si][sj][clr][dir]+1 < seen[si][sj][clr][(dir+1)%4] ){
				seen[si][sj][clr][(dir+1)%4] = seen[si][sj][clr][dir]+1;
				q.push( ((si*100 + sj )*10 + clr)*10 + ((dir+1)%4) );
			}
			if( seen[si][sj][clr][dir]+1 < seen[si][sj][clr][(dir+3)%4] ){
				seen[si][sj][clr][(dir+3)%4] = seen[si][sj][clr][dir]+1;
				q.push( ((si*100 + sj )*10 + clr)*10 + ((dir+3)%4) );
			}
			ni = si+ds[dir][0];
			nj = sj+ds[dir][1];
			if( ok( ni, nj ) && seen[si][sj][clr][dir]+1 < seen[ni][nj][(clr+1)%COLORS][dir] ){
				seen[ni][nj][(clr+1)%COLORS][dir] = seen[si][sj][clr][dir]+1;
				q.push( ((ni*100 + nj )*10 + ((clr+1)%COLORS))*10 + dir );
			}
			
		}
		
		cout << "Case #" << tc++ << "\n";
		int ans = MIN( seen[ti][tj][0][0], MIN( seen[ti][tj][0][1], MIN( seen[ti][tj][0][2], seen[ti][tj][0][3] ) ) );
		if( ans == INF ) cout << "destination not reachable\n";
		else cout << "minimum time = " << ans << " sec\n";
	}
	return 0;
}




















