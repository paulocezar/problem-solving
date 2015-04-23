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

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int nc, u, v, x, y, tc = 1;
	
	while( cin >> nc && nc ){
		
		vector< int > cansend[31];
		map< int, int > id;
		
		REP( i, nc ){
			cin >> x >> y;
			if( !id.count(x) ){ u = SIZE(id); id[x] = u; }
			if( !id.count(y) ){ u = SIZE(id); id[y] = u; }
			x = id[x];
			y = id[y];
			cansend[x].PB( y );
			cansend[y].PB( x );
		}
		
		int from, ttl;
		while( cin >> from >> ttl && (from||ttl) ){
			
			queue< int > q;
			q.push( id[from] );
			
			int seen = 0;
			seen |= (1<<id[from]);
			
			REP( tm, ttl ){
				int sz = SIZE(q);
				REP( i, sz ){
					u = q.front(); q.pop();
					REP( j, SIZE(cansend[u]) ){
						v = cansend[u][j];
						if( !(seen&(1<<v)) ) q.push( v );
						seen |= (1<<v);
					}
				}
			}
			int ans = SIZE(id) - __builtin_popcount(seen);
			
			cout << "Case " << tc++ << ": " << ans << " nodes not reachable from node " << from << " with TTL = " << ttl << ".\n";
		}
	}
	
	return 0;
}

























