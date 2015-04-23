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

#define MAXN 111

int pa[MAXN], rk[MAXN];

int find( int x ){
	int ax, y = x;
	while( y != pa[y] ) y = pa[y];
	while( x != y ){
		ax = pa[x];
		pa[x] = y;
		x = ax;
	}
	return y;
}

void fUnion(int x, int y){
	int px = find(x);
	int py = find(y);
	if( px == py ) return;
	if( rk[px] < rk[py] ) swap(px,py);
	pa[py] = px;
	if( rk[px] == rk[py] ) rk[px]++;
}

int main( int argc, char* argv[] ){
	
	
	int t, n, m, u, v, q;
	
	scanf("%d", &t );
	while( t-- ){
		scanf("%d %d", &n, &m );
		REP( i, n ) pa[i] = i, rk[i] = 0;
		REP( i, m ){ scanf("%d %d", &u, &v ); fUnion(u,v); }
		scanf("%d", &q );
		while( q-- ){
			scanf("%d %d", &u, &v );
			if( find(u) == find(v) ) puts("YO");
			else puts("NO");
		}	
	}
		
	return 0;
}

























