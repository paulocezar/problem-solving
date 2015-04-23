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

#define MAXM 111
string grid[MAXM];
int M, N, Q;

int sz;
bool ok( int r, int c, char nd ){
	int rr = r;
	int cc = c;
	while( rr < r+sz+2 ){
		
		//cout << rr << ' ' << cc << endl;
		if( grid[rr][cc] != nd ) return false;
		rr++;
	}
	rr = r;
	while( cc < c+sz+2 ){
		
		//cout << rr << ' ' << cc << endl;
		if( grid[rr][cc] != nd ) return false;
		cc++;
	}
	cc--;
	while( rr < r+sz+2 ){
		
		//cout << rr << ' ' << cc << endl;
		if( grid[rr][cc] != nd ) return false;
		rr++;
	}
	rr--;
	while( cc >= c ){
		
		//cout << rr << ' ' << cc << endl;
		if( grid[rr][cc] != nd ) return false;
		cc--;
	}
	return true;	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, r, c;
	char chr;
	
	cin >> t;
	while( t-- ){
		cin >> M >> N >> Q;
		REP( i, M )
			cin >> grid[i];
		cout << M << " " << N << " " << Q << "\n";
		while( Q-- ){
			cin >> r >> c;
			chr = grid[r][c];
			sz = 1;
			r--, c--;
			while( r >= 0 && c >= 0 && r+sz+2 <= M && c+sz+2 <= N && ok( r, c, chr ) ){
				sz += 2;
				r--, c--;
			}
			cout << sz << "\n";
		}
	}
	
	return 0;
}




















