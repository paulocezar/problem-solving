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

struct doll_t{
	int w, l, h;
	doll_t( int a = 0, int b = 0, int c = 0 ) : w(a), l(b), h(c) {}
	bool operator < ( const doll_t &d ) const {
		if( w != d.w ) return w < d.w;
		if( l != d.l ) return l < d.l;
		return h < d.h;
	}
	bool fits( const doll_t &d ){ return ((w<d.w)&&(l<d.l)&&(h<d.h)); }
};

#define MAXDOLLS 555
doll_t doll[MAXDOLLS];
int in[MAXDOLLS];

#define MAXN MAXDOLLS

int DOLLS;
vector< int > gr[MAXN];
bool seen[MAXN];		
int m[MAXN], m1[MAXN];

int dfs( int u ){
	if( u < 0 ) return 1;
	if( seen[u] ) return 0;
	seen[u] = true;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		int v = gr[u][i];
		if( !in[ v ] ) continue;
		
		if( dfs( m1[ v ] ) ){
			m[u] = v;
			m1[ v ] = u;
			return 1;
		}
	}
	return 0;
}

int dfsExp( int u ){
	for( int i = 0; i < DOLLS; i++ ) seen[i] = false;
	return dfs( u );
}

int bipMatch(){
	for( int i = 0; i < DOLLS; i++ ) m[i] = -1;
	for( int i = 0; i < DOLLS; i++ ) m1[i] = -1;
	int aug, ans = 0;
	do{
		aug = 0;
		bool first = true;
		for( int i = 0; i < DOLLS; i++ ) if( m[i] < 0 ){
			if( first ) aug += dfsExp( i );
			else aug += dfs( i );
			first = false;
		}
		ans += aug;
	} while( aug );
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( cin >> DOLLS && DOLLS ){
	
		REP( i, DOLLS ){
			cin >> doll[i].w >> doll[i].l >> doll[i].h;
			in[i] = 0; gr[i].clear();
		}
		
		sort( doll, doll+DOLLS );
		
		REP( i, DOLLS ) FOR( j, i+1, DOLLS-1 ) if( doll[i].fits( doll[j] ) ){
			gr[i].PB( j ); in[j]++;
		}
		
		cout << DOLLS - bipMatch() << "\n";
		
	}
		
	return 0;
}

























