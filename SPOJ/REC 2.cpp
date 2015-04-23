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

int64 mod;

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

void get( char *x, int &sx ){
	sx = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		x[sx++] = c-'0';
		c = getchar_unlocked();
	}	
}
void getmod( char *x, int &sx, int64 &res ){
	res = 0;
	REP( i, sx ){ res = 10*res + x[i]; res %= mod; }
}

int64 aux[2][2];

void mult( int64 a[][2], int64 b[][2] ){
	REP( i, 2 ) REP( j, 2 ){
		aux[i][j] = 0;
		REP( k, 2 ){
			aux[i][j] += (a[i][k]*b[k][j])%mod; aux[i][j] %= mod;
		}
	}
	REP( i, 2 ) REP( j, 2 ) a[i][j] = aux[i][j];
}

int ns, n[111];

void readNrev(){
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	ns = 0;
	while( isdigit(c) ){
		n[ns] = c-'0'; ns++;
		c = getchar_unlocked();
	}
	int i = 0, j = ns-1;
	while( i < j ){
		swap( n[i], n[j] );
		i++; j--;
	}
}

char aa[111], bb[111];

int main( int argc, char* argv[] ){
	
	int t, sa, sb;
	int64 a, b;
	
	scanf("%d", &t );
	while( t-- ){
		
		get(aa, sa);
		get(bb, sb);
		readNrev();
		mod = next_int();
		getmod(aa,sa,a);
		getmod(bb,sb,b);
		while( ns && n[ns-1]==0 ) ns--;
		 
		
		int64 pot[2][2], ans[2][2];
		pot[0][0] = a, pot[0][1] = 1;
		pot[1][0] = 0, pot[1][1] = 1;
		
		ans[0][0] = 1, ans[0][1] = 0;
		ans[1][0] = 0, ans[1][1] = 1;
		
		
		while( ns > 0 ){
			
			if( n[0]&1 ) mult(ans,pot);
			mult(pot,pot);
			
			int nxt, cry = 0;
			RREP( i, ns ){
				nxt = 10*cry + n[i];
				cry = nxt&1;
				n[i] = nxt/2;
			}
			while( ns && n[ns-1]==0 ) ns--;
			
		}
		
		int64 res = (ans[0][0] + ((ans[0][1]*b)%mod))%mod;
		printf("%d\n", int(res) );
		
	}
	
	return 0;
}

























