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

typedef double real;

using namespace std;

real SDIS( real xa, real ya, real xb, real yb ){
	return SQR(xa-xb) + SQR(ya-yb);
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, a;
	real a2, x, y;
	
	while( cin >> N && N ){
		cin >> a;
		a2 = SQR(real(a));
		int M = 0;
		REP( i, N ){
			cin >> x >> y;
			real d1 = SDIS(x,y,0,0);
			real d2 = SDIS(x,y,0,a);
			real d3 = SDIS(x,y,a,0);
			real d4 = SDIS(x,y,a,a);
			if( d1 < a2 && d2 < a2 && d3 < a2 && d4 < a2 ) M++;
		}
		cout << fixed << setprecision(5) << M*a2/N << endl; 
		
	}
	
	return 0;
}




















