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

int grid[555][555], acmLN[555][555], acmCL[555][555];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n, m;
	cin >> n >> m;
	
	REP( i, n ) REP( j, m )
		cin >> grid[i][j];
		
	REP( i, n ){
		acmLN[i][0] = grid[i][0];
		FOR( j, 1, m-1 )
			acmLN[i][j] = acmLN[i][j-1] + grid[i][j];
	}
	
	REP( j, m ){
		acmCL[0][j] = grid[0][j];
		FOR( i, 1, n-1 )
			acmCL[i][j] = acmCL[i-1][j] + grid[i][j];	
	}
	
	int ans;
	bool calc = false;	
	REP( i, n ) REP( j, m ){
		
		int ii = i;
		int jj = j;
		int len = 2;
		int cur = 0;
		
		while( ii >= 0 && jj >= 0 && ii+len < n && jj+len < m ){
				
			cur += acmLN[ii][jj+len] - (jj?acmLN[ii][jj-1]:0);
				
			cur += acmCL[ii+len][jj+len] - acmCL[ii][jj+len];
				 
			cur += acmLN[ii+len][jj+len-1] - (jj?acmLN[ii+len][jj-1]:0);
				
			cur += acmCL[ii+len-1][jj] - acmCL[ii+1][jj];
				
			if( len > 2 ) cur += grid[ii+2][jj+1];
				
			ans = calc?max(ans,cur):cur;
			calc = true;
			
			ii -= 2;
			jj -= 2;
			len += 4;
			
		}
		
	}
	
	REP( i, n ) REP( j, m ){
		
		int ii = i;
		int jj = j;
		int len = 4;
		int cur = 0;
		
		while( ii >= 0 && jj >= 0 && ii+len < n && jj+len < m ){
				
			cur += acmLN[ii][jj+len] - (jj?acmLN[ii][jj-1]:0);
			
			cur += acmCL[ii+len][jj+len] - acmCL[ii][jj+len];
			 
			cur += acmLN[ii+len][jj+len-1] - (jj?acmLN[ii+len][jj-1]:0);
			
			cur += acmCL[ii+len-1][jj] - acmCL[ii+1][jj];
			
			
			if( len == 4 ){
				cur += grid[ii+2][jj+1];
				cur += grid[ii+2][jj+2];
			} else cur += grid[ii+2][jj+1];
				
			ans = calc?max(ans,cur):cur;
			calc = true;
			
			ii -= 2;
			jj -= 2;
			len += 4;
			
		}
		
	}
	
	cout << ans << "\n";
		
	return 0;
}

























