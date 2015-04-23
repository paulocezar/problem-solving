#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(double a, double b) { return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define AREAS 25
#define DIM 5

int x[AREAS], y[AREAS];
int pop[DIM][DIM];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	int n, a, b, c;
	
	REP( i, AREAS ){ x[i] = i/DIM; y[i] = i%DIM; }
	cin >> t;
	while( t-- ){
		
		FILL( pop, 0 );
		cin >> n;
		while( n-- ){
			cin >> a >> b >> c;
			pop[a][b] = c;
		}
		
		int ans = INF;
		int i[DIM], aans[DIM];
		
		for( i[0] = 0; i[0] < AREAS; i[0]++ )
		for( i[1] = i[0]+1; i[1] < AREAS; i[1]++ )
		for( i[2] = i[1]+1; i[2] < AREAS; i[2]++ )
		for( i[3] = i[2]+1; i[3] < AREAS; i[3]++ )
		for( i[4] = i[3]+1; i[4] < AREAS; i[4]++ ){
			int cur = 0;
			REP( xx, DIM ) REP( yy, DIM ){
				int ds = INF;
				if( pop[xx][yy] ) REP( z, DIM ) ds = MIN( ds, ABS(xx-x[i[z]]) + ABS(yy-y[i[z]]) );
				cur += pop[xx][yy]*ds;
			}
			if( cur < ans ){
				ans = cur;
				REP( xx, DIM ) aans[xx] = i[xx];
			}
		}
		cout << aans[0];
		FOR( ii, 1, DIM ) cout << " " << aans[ii];
		cout << "\n";
	}
	
	return 0;
}




















