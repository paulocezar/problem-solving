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

int dist[1111][1111];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n, m;
	cin >> n >> m;
	string grid[n];
	REP( i, n ) cin >> grid[i];
	
	bool hascol[m];
	REP( j, m ) hascol[j] = (grid[0][j]=='#');
	
	REP( i, n ) REP( j, m )
		dist[i][j] = INF;
	
	if( n == 1 ) cout << "0\n";
	else {
		
		queue< pair<int,int> > q;
		REP( j, m ) if( grid[n-1][j] == '#' ){
			dist[n-1][j] = 1;
			q.push( MP(n-1,j) );
		}
		
		while( !q.empty() ){
			int x = q.front().first;
			int y = q.front().second; q.pop();
			
			for( int i = 0; i < n; i++ ) if( grid[i][y] == '#' ){
				if( dist[x][y]+1 < dist[i][y] ){
					dist[i][y] = dist[x][y]+1;
					if( i == 0 ) goto hell;
					q.push( MP(i,y) );
				}
			}
			
			REP( j, m ) if( grid[x][j] == '#' ){
				if( dist[x][y]+1 < dist[x][j] ){
					dist[x][j] = dist[x][y]+1;
					
					if( hascol[j] ){ dist[0][j] = dist[x][y]+2; goto hell; }
					
					q.push( MP(x,j) );
				}
			}
			
		}
	hell:
		int mn = INF;
		REP( j, m ) mn = min( mn, dist[0][j] );
		if( mn == INF ) mn = -1;
		cout << mn << "\n";
		
	}
		
	return 0;
}

























