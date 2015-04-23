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

vector< int > ok;
bool seen[10];

void build( int sz, int val, int can ){
	if( sz == 5 ){ ok.PB( val ); return; }
	REP( i, 10 ) if( can & ( 1<<i) ) build( sz+1, 10*val + i, can ^ (1<<i) );
}

int main( int argc, char* argv[] ){
	
	ok.clear();
	build( 0, 0, (1<<10)-1 );
	
	int N;
	bool first = true;
	while( scanf("%d", &N) && N ){
		if( !first ) puts("");
		
		bool print = false;
		REP( i, SIZE(ok) ) if( binary_search( ALL(ok), N*ok[i] ) ){
			int num = N*ok[i];
			int den = ok[i];
			FILL( seen, false );
			REP( j, 5 ){
				int d1 = num % 10; num /= 10;
				int d2 = den % 10; den /= 10;
				if( seen[d1] ) goto next;
				seen[d1] = true;
				if( seen[d2] ) goto next;
				seen[d2] = true;
			}
			print = true;
			printf("%05d / %05d = %d\n", N*ok[i], ok[i], N );
		next:
			print = print;
		}
		if( !print ) printf( "There are no solutions for %d.\n", N );
		first = false;
	}
	
	return 0;
}




















