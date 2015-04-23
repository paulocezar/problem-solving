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

#define MAXN 505

int n, m, k;
string grid[MAXN];

int bg[MAXN][MAXN], ed[MAXN][MAXN];

int begin(int i, int j){
	if( grid[i][j] == '0' ) return 0;
	if( i==0 || i == n-1 || j+2 >= m ) return 0;
	return ((grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i-1][j+1]+grid[i+1][j+1]) == (5*'1'));
}

int end(int i, int j){
	if( grid[i][j] == '0' ) return 0;
	if( i==0 || i == n-1 || j-2 < 0 ) return 0;
	return ((grid[i][j] + grid[i][j-1] + grid[i][j-2] + grid[i-1][j-1]+grid[i+1][j-1]) == (5*'1'));
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	cin >> n >> m >> k;
	for( int i = 0; i < n; i++ ) cin >> grid[i];
	
	for( int j = 0; j < m; j++ ){
		for( int i = 0; i < n; i++ ){
			bg[i][j] = i?bg[i-1][j]:0;
			ed[i][j] = i?ed[i-1][j]:0;
			bg[i][j] += begin(i,j);
			ed[i][j] += end(i,j);
		}
	}
	
	int64 ans = 0;
	for( int top = 0; top < n; top++ ){
		for( int bot = top+2; bot < n; bot++ ){
			
			int lft = 0, rgt = 0;
			int cur = 0;
			
			while( lft < m ){
				
				cur -= (lft?(bg[bot-1][lft-1]-((top>=0)?bg[top][lft-1]:0)):0);
				
				while( rgt < m && cur < k ){
					cur += (ed[bot-1][rgt]-((top>=0)?ed[top][rgt]:0));
					rgt++;
				}
				if( cur >= k ) ans += (m-rgt+1);
				lft++;
			}
			
		}
	}
	
	cout << ans << "\n";
	
	
	return 0;
}




















