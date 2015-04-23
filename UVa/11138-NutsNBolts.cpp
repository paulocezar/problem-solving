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
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 555
vector< int > gr[MAXN]; bool seen[MAXN];
int m[MAXN], m1[MAXN], N, M;

int dfs( int u ){
	if( u < 0 ) return 1;
	if( seen[u] ) return 0;
	seen[u] = true;
	REP( i, SIZE(gr[u]) ){
		if( dfs( m1[gr[u][i]] ) ){
			m[u] = gr[u][i];
			m1[gr[u][i]] = u;
			return 1;
		}
	}
	return 0;
}
int dfsExp( int u ){
	REP( i, N ) seen[i] = false;
	return dfs( u );
}

int bipMatch(){
	REP( i, N ) m[i] = -1;
	REP( i, M ) m1[i] = -1;
	int aug, ans = 0;
	do{
		aug = 0;
		bool first = true;
		REP( i, N ) if( m[i] < 0 ){
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
	int t, tc = 1, fit;
	cin >> t;
	while( t-- ){
		cin >> N >> M;
		REP( i, N ){
			gr[i].clear();
			REP( j, M ){
				cin >> fit;
				if( fit ) gr[i].PB( j );
			}
		}
		cout << "Case " << tc++ << ": a maximum of " << bipMatch() << " nuts and bolts can be fitted together\n";
		
	}
	
	return 0;
}




















