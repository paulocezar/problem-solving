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

int64 aux[3][3], MOD;

void mult( int64 a[][3], int64 b[][3] ){
	FILL( aux, 0 );
	REP( i, 3 ) REP( j, 3 ) REP( k, 3 ){
		aux[i][j] += (a[i][k]*b[k][j])%MOD;
		aux[i][j] %= MOD;
	} 
	REP( i, 3 ) REP( j, 3 ) a[i][j] = aux[i][j];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	uint64 n;
	int tc = 1;
	
	while( cin >> n >> MOD && (n || MOD) ){
		
		if( n > 1 ){
			int64 pot[][3] = {{1,1,1},
						 	  {1,0,0},
						 	  {0,0,1}
					 		 };
			int64 ans[][3] = {{1,0,0},
						 	  {0,1,0},
						 	  {0,0,1}
					 		 };
		
			uint64 x = n-1;
			while( x ){
				if( x&1 ) mult( ans, pot );
				mult( pot, pot );
				x >>= 1;
			}			
			x = ans[0][0]+ans[0][1]+ans[0][2]; x %= MOD;
			
			cout << "Case " << tc++ << ": " << n << " " << MOD << " " << x << "\n";
		
		} else cout << "Case " << tc++ << ": " << n << " " << MOD << " 1\n";
		
		
	
	}
	
	return 0;
}

























