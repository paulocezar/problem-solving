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

#define MAXN 100000

int64 a[MAXN];
int id[MAXN];
int at[MAXN];

bool comp( int x, int y ){
	if( a[x] != a[y] ) return a[x] > a[y];
	return x > y;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int N, K;
	cin >> N >> K;
	int64 bd;
	cin >> bd;
	
	
	REP( i, N ){
		
		cin >> a[i];
		id[i] = i;
		
	}
	
	sort( id, id+N-1, comp );
	
	REP( i, N ) at[ id[i] ] = i;
	
	int res = N-1;
	
	K--;
	int64 ksum = 0;
	REP( i, K ) ksum += a[ id[i] ];
	
	REP( cand, N ) {
		
		int64 nksum = ksum;
		if( at[cand] < K ){
			nksum -= a[ cand ];
			nksum += a[ id[K] ];
		}
		
		if( nksum + a[cand] > bd ){ res = cand; break; }
		
	}
	
	cout << res+1 << "\n";
	
	return 0;
}

























