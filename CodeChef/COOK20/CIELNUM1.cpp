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

bool check( int64 x ){
	int d8 = 0, d5 = 0, d3 = 0, dig;
	while( x ){
		dig = x%10;
		if( dig == 8 ) d8++;
		else if( dig == 5 ) d5++;
		else d3++;
		x /= 10;
	}
	return ((d8>=d5)&&(d5>=d3));
}

int64 ans[50000];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	
	queue< int64 > q;
	int pos = 0;
	
	q.push( 3 );
	q.push( 5 );
	q.push( 8 );
	int64 cur;
	
	while( pos < 50000 ){
		
		cur = q.front(); q.pop();
		if( check(cur) ) ans[pos++] = cur;
		
		q.push( 10LL*cur + 3LL );
		q.push( 10LL*cur + 5LL );
		q.push( 10LL*cur + 8LL );
		
	}
	
	REP( i, 50000 ){ cout << ans[i] << "\n"; }
	
	
	
	return 0;
}

























