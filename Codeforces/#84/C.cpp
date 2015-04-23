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

#define MAXN 100000
int pa[MAXN], rk[MAXN];
int64 sz[MAXN];

int find( int x ){
	int a = x;
	while( pa[a] != a ) a = pa[a];
	int y;
	while( pa[x] != a ){
		y = pa[x];
		pa[x] = a;
		x = y;
	}
	return a;
}

void fUnion( int x, int y ){
	int px = find(x);
	int py = find(y);
	if( px == py ) return;
	if( rk[py] > rk[px] ){ px ^= py; py ^= px; px ^= py; }
	if( rk[px] == rk[py] ) rk[px]++;
	pa[py] = px;
	sz[px] += sz[py];
}

bool lucky( int N ){
	while( N ){
		if( N%10 != 4 && N%10 != 7 ) return false;
		N /= 10;
	}
	return true;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, u, v, w;
	
	cin >> N;
	REP( i, N ) pa[i] = i, rk[i] = 0, sz[i] = 1;
	
	REP( i, N-1 ){
		cin >> u >> v >> w; u--, v--;
		if( !lucky(w) ) fUnion( u, v );
	}
	
	int64 ans = 0;
	REP( i, N ) if( i == find(i) )
		ans += sz[i]*(N-sz[i])*(N-sz[i]-1);
	cout << ans << "\n";
	
	return 0;
}




















