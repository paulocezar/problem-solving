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

#define MAXN 111
int d[MAXN][MAXN];
int x[MAXN], y[MAXN], N, M, MID;
int m[MAXN], m1[MAXN], v[MAXN];

int dfs( int u ){
	if( u < 0 ) return 1;
	if( v[u] ) return 0;
	v[u] = 1;
 	REP( i, M ) if( d[u][i] <= MID ){
		if( dfs( m1[i] ) ){
			m[u] = i; m1[i] = u;
			return 1;
		}
	}
	return 0;
}

int dfsExp( int u ){
	REP( i, N ) v[i] = 0;
	return dfs(u);
}

int bipMatch(){
	REP( i, N ) m[i] = -1;
	REP( i, M ) m1[i] = -1;
	int aug = 0;
	int ans = 0;
	bool fs;
	do{
		ans += aug;
		aug = 0;
		fs = true;
		REP( i, N ) if( m[i] < 0 ){
			if( fs ) aug += dfsExp( i );
			else aug += dfs( i );
			fs = false;
		}
	} while( aug );
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, P, K;
	string color;
	cin >> t;
	while( t-- ){
		cin >> P >> K;
		N = 0, M = 0;
		vector< int > b, r;
		REP( i, P ){
			cin >> x[i] >> y[i] >> color;
			if( color[0] == 'b' ) b.PB( i );
			else r.PB( i );
		}
		N = SIZE(b);
		M = SIZE(r);
		int lo = INF, hi = -1;
		REP( i, N ){
			REP( j, M ){
				d[i][j] = SQR(x[b[i]]-x[r[j]]) + SQR(y[b[i]]-y[r[j]]);
				lo = MIN( lo, d[i][j] );
				hi = MAX( hi, d[i][j] );
			}
		}
		int ans = -1;
		while( lo <= hi ){
			MID = (lo+hi)/2;
			if( bipMatch() >= K ){
				ans = MID;
				hi = MID-1;
			} else {
				lo = MID+1;
			}
		}
		if( ans == -1 ) cout << "Impossible\n";
		else cout << int( ceil(sqrt(ans)) ) << "\n";
	}
	
	return 0;
}




















