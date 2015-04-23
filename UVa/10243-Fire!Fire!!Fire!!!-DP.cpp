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

#define MAXN 1111
int dp[MAXN][2];
int parent[MAXN];

vector<int> gr[MAXN];

int solve( int u, int cov ){
	if( dp[u][cov] == -1 ){
		
		dp[u][cov] = 1-cov;
		
		REP( i, SIZE(gr[u]) ){
			int v = gr[u][i];
			if( parent[v] == u ){
				
				if( !cov ) dp[u][cov] += MIN( solve(v, 0), solve(v,1) );
				else dp[u][cov] += solve(v,0);
			}
		}
		
	}
	return dp[u][cov];
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int sz, N;
	
	while( (cin>>N) && N ){
		REP( i, N ){
			cin >> sz;
			gr[i].resize( sz );
			REP( j, sz ){
				cin >> gr[i][j]; gr[i][j]--;
			}
			parent[i] = -1; dp[i][0] = -1; dp[i][1] = -1;
		}
		
		parent[0] = 0;
		queue<int> q; q.push( 0 );
		while( !q.empty() ){
			sz = q.front(); q.pop();
			REP( i, SIZE(gr[sz]) ) if( parent[gr[sz][i]] == -1 ){
				parent[ gr[sz][i] ] = sz; 
				q.push( gr[sz][i] );
			}
		}
		if( N == 1 ) cout << "1\n";
		else cout << MIN( solve(0, 0), solve( 0, 1 ) ) << "\n";
	}
	
	return 0;
}




















