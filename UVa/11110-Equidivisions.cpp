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

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 111
int grid[MAXN][MAXN], N;

int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
bool ok( int i, int j ){ return (i > 0) && (i <= N) && (j > 0) && (j <= N); }

int flood( int i, int j ){
	int ni, nj, ans = 1;
	grid[i][j] += 1000;
	REP( dr, 4 ){
		ni = i + ds[dr][0];
		nj = j + ds[dr][1];
		if( ok(ni,nj) && grid[ni][nj]+1000 == grid[i][j] ) ans += flood( ni, nj );
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int x, y;
	while( cin >> N && N ){
		cin.ignore();
		FOR( i, 1, N ) FOR( j, 1, N ) grid[i][j] = 1;
		FOR( a, 2, N ){
			string line;
			getline( cin, line );
			istringstream in( line );
			while( in >> x >> y ) grid[x][y] = a;
		}
		FOR( i, 1, N ) FOR( j, 1, N ) if( grid[i][j] <= N ){
			if( flood( i, j ) != N ){ cout << "wrong"; goto hell; }
		}
		cout << "good";
	hell:
		cout << "\n";
	}
	
	return 0;
}




















