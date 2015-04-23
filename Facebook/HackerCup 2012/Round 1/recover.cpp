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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 10000

const int MOD = 1000003;

int n, ptr, pos;

int a[MAXN];
int aux[MAXN];

string s;

void mmerge( int b1, int e1, int b2, int e2 ){
	ptr = 0;
	int beg = b1;
	
	while( (b1<=e1) && (b2<=e2) ){
		if( s[pos] == '1' ){
			aux[ptr++] = a[b1++];
			pos++;
		} else {
			aux[ptr++] = a[b2++];
			pos++;
		}
	}
	
	while( b1 <= e1 ) aux[ptr++] = a[b1++];
	while( b2 <= e2 ) aux[ptr++] = a[b2++];
	
	int xxx = 0;
	while( ptr ){
		a[beg+xxx] = aux[xxx];
		xxx++;
		ptr--;
	}
	
}

void msort( int b, int e ){
	int len = e-b+1;
	if( len <= 1 ) return;
	
	int mid = len/2;
	
	msort( b, b+mid-1);
	msort( b+mid, e);
	mmerge( b, b+mid-1, b+mid, e );
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	FOR( tc, 1, t ){
		
		cin >> n;
		cin >> s;
		REP( i, n ) a[i] = i;
		
		pos = 0;
		msort( 0, n-1 );
		
		REP( i, n ) aux[ a[i] ] = (i+1);
		
		int ans = 1;
		REP( i, n ){
			ans = (31*ans + aux[i]) % MOD;
		}
		
		cout << "Case #" << tc << ": " << ans << "\n";	
	}
	
	return 0;
}




















