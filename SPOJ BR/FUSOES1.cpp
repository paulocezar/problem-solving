#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 100001
int pa[MAXN], rk[MAXN];

int find( int x ){
	
	int a = x, pax;
	while( pa[a] != a ) a = pa[a]; 
	
	while( pa[x] != x ){
		pax = pa[x];
		pa[x] = a;
		x = pax;
	}
	
	return a;
}

void fUnion( int x, int y ){
	int px = find(x);
	int py = find(y);
	if( px == py ) return;
	if( rk[px] < rk[py] ){ px ^= py; py ^= px; px ^= py; }
	if( rk[px] == rk[py] ) rk[px]++;
	pa[py] = px;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int N, K, a, b;
	char op;
	
	cin >> N >> K;
	REP( i, N ) { pa[i+1] = i+1; rk[i+1] = 0; }
	cin.ignore();
	while( K-- ){
		cin >> op >> a >> b;
		if( op == 'C' ){
			if( find(a) == find(b) ) cout << "S\n";
			else cout << "N\n";
		} else fUnion( a, b );
	}
	
	return 0;
}
