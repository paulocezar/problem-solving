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

#define MAXN 1111

vector< int > gr[MAXN];
bool seen[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int V, E, T, tc = 1;
	
	while( (cin >> V >> E >> T) && (V||E||T) ){
		FOR( i, 1, V ){
			gr[i].clear();
			seen[i] = false;
		}
		REP( i, E ){
			int u, v;
			cin >> u >> v;
			gr[u].PB( v );
			gr[v].PB( u );
		}
		int ans = E*T;
		
		vector< int > odds;
		
		FOR( i, 1, V ) if( SIZE(gr[i]) && !seen[i] ){
			
			int curodd = 0;
			queue< int > q;
			q.push( i ); seen[i] = true;
			
			while( !q.empty() ){
				int u = q.front(); q.pop();
				curodd += (SIZE(gr[u])%2);
				REP( j, SIZE(gr[u]) ) if( !seen[ gr[u][j] ] ){
					seen[ gr[u][j] ] = true;
					q.push( gr[u][j] ); 
				}
			}
			odds.PB( curodd );
			
		}
		
		int odd = (SIZE(odds)?odds[0]:0);
		FOR( i, 1, SIZE(odds)-1 ){
			if( odd ) odd--;
			else odd++;
			if( odds[i] ) odds[i]--;
			else odds[i]++;
			odd += odds[i];
			ans += T;
		}
		
		odd -= 2;
		if( odd > 0 ) ans += ((odd+1)/2)*T;		
		
		cout << "Case " << tc++ << ": " << ans << "\n";
	}
	
	return 0;
}

























