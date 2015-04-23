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

#define MAXN 101
int o[MAXN], p[MAXN], b[MAXN];

bool comp( int aa, int bb ){
	if( o[aa] != o[bb] ) return o[aa] > o[bb];
	if( p[aa] != p[bb] ) return p[aa] > p[bb];
	if( b[aa] != b[bb] ) return b[aa] > b[bb];
	return aa < bb;
}

int a[MAXN];

int main( int argc, char* argv[] ){
	
	int N = next_int();
	int M = next_int();

	REP( i, N ) a[i] = i+1;
	
	while( M-- ){
		int oo, pp, bb;
		oo = next_int();
		pp = next_int();
		bb = next_int();
		o[oo]++;
		p[pp]++;
		b[bb]++;
	}
	
	sort( a, a+N, comp );
	printf("%d", a[0] );
	FOR( i, 1, N-1 ) printf(" %d", a[i] );
	puts("");
	return 0;
}


























