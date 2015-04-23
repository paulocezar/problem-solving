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

int64 paths[55][55];

int64 npaths( int dx, int dy ){
	if( paths[dx][dy] == -1 ){
		paths[dx][dy] = 0;
		if( dx ) paths[dx][dy] += npaths(dx-1,dy);
		if( dy ) paths[dx][dy] += npaths(dx,dy-1);
	}
	return paths[dx][dy];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	FILL( paths, -1 );
	paths[0][0] = 1;
	cin >> t;
	FOR( tc, 1, t ){
		
		int64 S;
		cin >> S;
		
		int ans = S+1;
		
		FOR( M, 1, 50 ) FOR( N, M, 50 ){
		
			FOR( m, 0, M ) FOR( n, 0, N ){
				
				if( m == 0 && n == 0 ) continue;
				if( m == M && n == N ) continue;
				
				int d1 = m+n;
				int d2 = (M-m)+(N-n);
				
				int64 poc = npaths(m,n);
				if( poc > S ) continue;
				int64 pcd = npaths(M-m,N-n);
				if( pcd > S ) continue;
				
				int64 paths = poc * pcd;
				
				if( paths == S ) ans = min( ans, d1+d2 );
				
			}
			
		}
		
		cout << "Case #" << tc << ": "<< ans << "\n";
	}
	
	return 0;
}




















