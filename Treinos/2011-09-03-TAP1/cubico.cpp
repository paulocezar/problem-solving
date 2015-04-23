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

#define MAXN 25
int l, c, g[MAXN][MAXN], seen[MAXN][MAXN], cter;
bool ok[MAXN][MAXN];

bool play( int i, int j ){
	queue< int > q;
	q.push( 100*i + j ); seen[i][j] = ++cter;
	while( !q.empty() ){
		j = q.front()%100; i = q.front()/100; q.pop();
		REP( dir, 4 ){
			int ni = i + ds[dir][0];
			int nj = j + ds[dir][1];
			if( g[ni][nj] == g[i][j] && seen[ni][nj] != cter ){
				seen[ni][nj] = cter;
				q.push( 100*ni + nj );
			}
			if( g[ni][nj] < g[i][j] ) return false;
		}
	}
	return true;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	
	FILL( seen, -1 );
	cter = 0;
	
	cin >> t;
	while( t-- ){
		cin >> l >> c;
		
		FOR( i, 1, l ){
			g[i][0] = g[i][c+1] = -1;
			FOR( j, 1, c ){
				g[0][i] = g[l+1][i] = -1;
				cin >> g[i][j];
			}
		}
		
		int ans = 0;
		REP( prof, 51 ){
			
			FOR( i, 1, l ) FOR( j, 1, c ){
				if( g[i][j] == prof ) ok[i][j] = play( i, j );
			}
			
			FOR( i, 1, l ) FOR( j, 1, c ) if( ok[i][j] ){ ans++; g[i][j]++; }
				
		}
		
		cout << ans << "\n";
	}
	
	
	return 0;
}




















