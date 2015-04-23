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

inline int next_int() {
	int res = 0;
	char c = getchar_unlocked();	
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = (res * 10) + (c - '0');
		c = getchar_unlocked();
	}
	return res;
}

#define MAXN 1111
int e[MAXN], s[MAXN];

int main( int argc, char* argv[] ){
	
	int n;
	n = next_int();
	while( n ){
		
		REP( i, n ) e[i] = next_int();
		REP( i, n ) s[i] = next_int();
		
		int se = 0;
		int ss = 0;
		bool ok = true;
		
		REP( i, n ){
			if( e[i] > n || s[i] > n ) ok = false;
			se += e[i];
			ss += s[i];
		}
		
		ok = ok && (se==ss);
		if( ok ){
			
			int sp = 0;
			int pos = 0;
			
			while( sp < n ){
				
				sort( e+pos, e+n );
				while( pos < n && e[pos]==0 ) pos++;
				
				if( n-pos >= s[sp] ){
					REP( i, s[sp] ) e[n-i-1]--;
					sp++;
				} else { ok = false; goto hell; }
				
			}
			
		}
	hell:
		if( ok ) puts("E");
		else puts("N");
		
		n = next_int();
	}
	
	return 0;
}

























