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

int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

#define MAXN 501

int woman_prefer[MAXN][MAXN], men_prefer[MAXN][MAXN];
int marry_with[MAXN], married_to[MAXN];
int n;

void marrythemall(){
	REP( i, n ) marry_with[i] = 0;
	REP( i, n ) married_to[i] = -1;
	
	REP( nxt_man, n ){
		int man = nxt_man;
rematch:
		int wmn = men_prefer[man][ marry_with[man]++ ];
		if( married_to[wmn] == -1 ){
			married_to[wmn] = man;
		} else {
			if( woman_prefer[wmn][ man ] < woman_prefer[wmn][ married_to[wmn] ] )
				swap( married_to[wmn], man );
			goto rematch;
		}
	}
}

int main( int argc, char* argv[] ){
	
	int t = next_int();
	while( t-- ){
		n = next_int();
		REP( i, n ){
			int woman = next_int()-1;
			REP( j, n )
				woman_prefer[woman][ next_int()-1 ] = j;
		}
		REP( i, n ){
			int man = next_int()-1;
			REP( j, n )
				men_prefer[man][j] = next_int()-1;
		}
		marrythemall();
		REP( i, n ) printf("%d %d\n",i+1, men_prefer[i][marry_with[i]-1]+1);
	}	
	
	return 0;
}

























