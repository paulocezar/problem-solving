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

int x[222], y[222];

inline bool left( int i, int j ){
	return (( x[j] > x[i] ) && (y[i]==y[j]));
}

inline bool right( int i, int j ){
	return (( x[j] < x[i] ) && (y[i]==y[j]));	
}

inline bool low( int i, int j ){
	return (( x[j] == x[i] ) && (y[i]>y[j]));
}

inline bool up( int i, int j ){
	return (( x[j] == x[i] ) && (y[i]<y[j]));
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int N;
	cin >> N;
	REP( i, N ) cin >> x[i] >> y[i];
	int ans = 0;
	
	REP( i, N ){
		bool a = false, b = false, c = false, d = false;
		REP( j, N ) if( i!=j ){
			a = a || left(i,j);
			b = b || right(i,j);
			c = c || low(i,j);
			d = d || up(i,j);
		}
		if( a && b && c && d ) ans++;
	}
	
	cout << ans << "\n";
	
		
	return 0;
}

























