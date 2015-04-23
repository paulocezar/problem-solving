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

#define MXCMP 256
int bit[MXCMP];

void up( int idx ){
	while( idx < MXCMP ){
		bit[idx]++;
		idx += (idx & -idx);
	}
}

int get( int idx ){
	int res = 0;
	while( idx > 0 ){
		res += bit[idx];
		idx -= (idx & -idx);
	}
	return res;
}

int next_int(){
	int res = 0, sig = 1;
	char c = getchar_unlocked();
	while( !isdigit(c) && c != '-' ) c = getchar_unlocked();
	if( c == '-' ){ sig = -1; c = getchar_unlocked(); }
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res*sig;
}

int a[255][255];
int cur[255];

int main( int argc, char* argv[] ){
	
	//srand( time(NULL) );
	
	int N, M;
	N = next_int();
	M = next_int();
	
	REP( j, M ) a[0][j] = next_int();
	
	FOR( i, 1, N-1 ){
		REP( j, M ){
			a[i][j] = next_int();
			a[i][j] += a[i-1][j];
		} 
	}
	
	int A, B;
	A = next_int();
	B = next_int();
	// count cur-B <= x <= cur-A
	
	int64 ans = 0;
	REP( i1, N ) FOR( i2, i1, N-1 ){
		
		FILL( bit, 0 );
		
		cur[0] = 0;
		REP( j, M ){ cur[j+1] = cur[j] + (a[i2][j]-(i1?a[i1-1][j]:0)); }
		cur[M+1] = 2e9;
		sort( cur, cur+M+2 );
		
		
		up( upper_bound(cur,cur+M+2,0) - cur );
		
		int now = 0;
		REP( j, M ){
			now += ( a[i2][j] - (i1?a[i1-1][j]:0) );
			ans += int64( get(upper_bound(cur,cur+M+2,now-A) - cur) - (get( upper_bound(cur,cur+M+2,now-B-1) - cur)) );
			
			up( upper_bound(cur,cur+M+2,now) - cur );
		}
	
	} 
	printf("%lld\n", ans );
		
	return 0;
}

























