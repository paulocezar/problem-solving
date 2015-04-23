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

#define MAXC 6
#define MXDM (1<<MAXC)

const int mod = 4242;
int DIM, aux[MXDM][MXDM], pot[MXDM][MXDM], ans[MXDM][MXDM];

void mult( int a[][MXDM], int b[][MXDM] ){
	REP( i, DIM ) REP( j, DIM ){
		aux[i][j] = 0;
		REP( k, DIM ){
			aux[i][j] += ((a[i][k]*b[k][j])%mod);
			aux[i][j] %= mod;
		}
	}
	REP( i, DIM ) REP( j, DIM )
		a[i][j] = aux[i][j];
}

#define MAXW 11111
char w[MAXW];
int problem[MAXC];

inline bool ok( char c ){ return (('A' <= c) && (c <= 'F')); }

int main( int argc, char* argv[] ){
	
	int t, n, c, sz;
	string w;
	
	t = next_int();
	while( t-- ){
		
		n = next_int();
		c = next_int();
		sz = 0;
		w[sz] = getchar_unlocked();
		while( !ok(w[sz]) ) w[sz] = getchar_unlocked();
		while( ok(w[sz]) ) w[++sz] = getchar_unlocked();
		
		REP( i, c ){
			problem[i] = 0;
			int pos = sz-1;
			while( pos && (w[pos] != char(i+'A')) ) pos--;
			pos--;
			while( pos >= 0 ){
				problem[i] |= (1<<(w[pos]-'A'));
				pos--;
			}
		}
		
		DIM = (1<<c);
		REP( i, DIM ) REP( j, DIM ){
			ans[i][j] = (i==j);
			pot[i][j] = 0;
		}
		
		REP( i, DIM ){
			
			REP( j, c ) if( i & (1<<j) ){
				if( !(problem[j] & i) ) pot[i][i]++;				
				int wtt = i ^ (1<<j);
				if( !(problem[j] & wtt) ) pot[i][wtt]++;
			}
	
		}
		
		while( n ){
			if( n&1 ) mult( ans, pot );
			mult( pot, pot );
			n >>= 1;
		}
		
		int res = 0;
		REP( i, DIM ){ res += ans[i][0]; res %= mod; }
		printf("%d\n", res );

	}
	
	return 0;
}

























