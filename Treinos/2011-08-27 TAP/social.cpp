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

#define MAXN 1000000
int pa[MAXN], rk[MAXN];

int find( int x ){
	int a = x, ax;
	while( pa[a] != a ) a = pa[a];
	while( pa[x] != a ){
		ax = pa[x];
		pa[x] = a;
		x = ax;
	}
	return a;
}

void fUnion( int a, int b ){
	int paa = find(a);
	int pb = find(b);
	if( paa == pb ) return;
	if( rk[pb] > rk[paa] ) swap( paa, pb );
	if( rk[paa] == rk[pb] ) rk[paa]++;
	pa[pb] = paa;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, N, K, M, u, v;
	cin >> t;
	FOR( tc, 1, t ){
		cin >> N;
		REP( i, N ) pa[i] = i, rk[i] = 0;
		cin >> K;
		while( K-- ){ cin >> u >> v; fUnion(u,v); }
		cin >> M;
		cout << "Cenario #" << tc << ":\n";
		while( M-- ){
			cin >> u >> v;
			cout << int(find(u)==find(v)) << "\n";
		}
		cout << "\n";
	}
	
	return 0;
}




















