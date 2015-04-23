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

char grid[222][222];
int ans;

int dx[] = { -1, -1, -1,  0,  0, +1, +1, +1 };
int dy[] = { -1,  0, +1, -1, +1, -1,  0, +1 };

void flood( int x, int y ){
	ans++;
	REP( i, 8 ) if( !grid[x+dx[i]][y+dy[i]] ){
		grid[x+dx[i]][y+dy[i]] = 1;
		flood( x+dx[i], y+dy[i] );
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, M, X, Y, K, a, b;
	
	cin >> N >> M >> X >> Y >> K;
	
	FOR( i, 0, N+1 ) grid[i][0] = grid[i][M+1] = 1;
	FOR( i, 0, M+1 ) grid[0][i] = grid[N+1][i] = 1;
	
	while( K-- ){
		cin >> a >> b;
		grid[a][b] = 1;
	}
	
	grid[X][Y] = 1; 
	flood( X, Y );
	cout << ans << "\n";
	
	return 0;
}

























