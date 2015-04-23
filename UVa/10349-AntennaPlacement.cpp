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
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXH 44
#define MAXW 11
#define MAXN 222

int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

string grid[MAXH];
int N, M, H, W, id[MAXH][MAXW], m[MAXN], m1[MAXN], color[MAXH][MAXW];
bool seen[MAXN];

vector<int> gr[MAXN];
bool ok( int i, int j ){ return ((i >= 0) && (i < H) && (j >= 0) && (j < W) && (grid[i][j]=='*')); }

int dfs( int u ){
	if( u < 0 ) return 1;
	if( seen[u] ) return 0;
	seen[u] = true;
	REP( i, SIZE(gr[u]) ){
		if( dfs( m1[gr[u][i]] ) ){
			m[u] = gr[u][i];
			m1[gr[u][i]] = u;
			return 1;
		}
	}
	return 0;
}

int dfsExp( int u ){
	REP( i, N ) seen[i] = false;
	return dfs( u );
}

int bipMatch(){
	int ans = 0;
	REP( i, N ) m[i] = -1;
	REP( i, M ) m1[i] = -1;
	int aug;
	do{
		aug = 0;
		bool first = true;
		REP( i, N ) if( m[i] < 0 ){
			if( first ) aug += dfsExp( i );
			else aug += dfs( i );
			first = false;
		}
		ans += aug;
	} while( aug );
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t;
	
	REP( j, MAXW ) color[0][j] = j&1;
	FOR( i, 1, MAXH-1 ) REP( j, MAXW ) color[i][j] = !color[i-1][j];
	
	cin >> t;
	while( t-- ){
		cin >> H >> W;
		REP( i, H ) cin >> grid[i];
		N = 0, M = 0;
		REP( i, H ) REP( j, W ){
			if( grid[i][j] == '*' ){
				if( color[i][j] ) id[i][j] = N++;
				else id[i][j] = M++;
			}
		}
		
		REP( i, N ) gr[i].clear();
		REP( i, H ) REP( j, W ){
			if( color[i][j] && grid[i][j] == '*' ){
				REP( dir, 4 ) if( ok( i+ds[dir][0], j+ds[dir][1] ) ){
					gr[ id[i][j] ].PB( id[ i+ds[dir][0] ][ j+ds[dir][1] ] );
				}
			}
		}
		cout << N+M-bipMatch() << "\n";
	}
	
	return 0;
}




















