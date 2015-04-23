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

int seen[9][9];

int ds[][2] = {{ 1, 2}, { 2, 1},
			   { 1,-2}, { 2,-1},
			   {-1, 2}, {-2, 1},
			   {-1,-2}, {-2,-1}};

inline bool ok( int x, int y ){ return((x>0)&&(x<9)&&(y>0)&&(y<9)); }

int qx[64], qy[64];
int beg, end;

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, xs, ys, xt, yt, nx, ny;
	cin >> t;
	while( t-- ){
		cin >> xs >> ys;
		cin >> xt >> yt;
		beg = 0, end = 0;
		
		FOR( i, 1, 8)
			FOR( j, 1, 8)
				seen[i][j] = INF;
		seen[xs][ys] = 0;
			
		qx[end] = xs;
		qy[end++] = ys;
		while( beg < end ){
			xs = qx[beg];
			ys = qy[beg++];
			if( xs == xt && ys == yt ) break;
			REP( dir, 8 ){
				nx = xs+ds[dir][0];
				ny = ys+ds[dir][1];
				if( ok(nx,ny) && seen[xs][ys]+1 < seen[nx][ny] ){
					seen[nx][ny] = seen[xs][ys]+1;
					qx[end] = nx;
					qy[end++] = ny;
				}
			}
		}
		cout << seen[xt][yt] << "\n";
	}
	
	return 0;
}




















