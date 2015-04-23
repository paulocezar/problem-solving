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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct edge_t{
	int v, w;
	edge_t( int vv = 0, int ww = 0 ) : v(vv), w(ww) {}
};

#define MAXS 111
int zone[MAXS], itn[MAXS], dist[MAXS];
vector< edge_t > gr[MAXS];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int Z, S, K, station, T, B, X, Y;
	
testcase:
	cin >> Z >> S;
	if( Z+S ){
		
		REP( i, Z ){
			cin >> K;
			while( K-- ){ cin >> station; zone[station] = i; gr[station].clear(); dist[station] = INF; }
		}
		
		cin >> T >> B;
		REP( i, T ){
			cin >> K;
			REP( j, K ) cin >> itn[j];
			REP( j, K ){
				int cost = 0;
				FOR( k, j+1, K-1 ){
					if( zone[itn[k-1]] != zone[itn[k]] ) cost += 4;
					gr[itn[j]].PB( edge_t(itn[k],cost) );
				}
				cost = 0;
				RFOR( k, j-1, 0 ){
					if( zone[itn[k+1]] != zone[itn[k]] ) cost += 4;
					gr[itn[j]].PB( edge_t(itn[k],cost) );
				}
			}
		}
		REP( i, B ){
			cin >> K;
			REP( j, K ) cin >> itn[j];
			REP( j, K ) FOR( k, j+1, K-1 ){
				gr[itn[j]].PB( edge_t(itn[k],1) );
				gr[itn[k]].PB( edge_t(itn[j],1) );
			}
		}
		cin >> X >> Y;
		
		dist[X] = 2;
		priority_queue< pair<int,int> > q;
		q.push( MP(-dist[X], X)  );
		
		while( !q.empty() ){
			int u = q.top().second;
			int w = -q.top().first; q.pop();
			if( u == Y ){ cout << w << "\n"; break; }
			if( w > dist[u] ) continue;
			REP( i, SIZE(gr[u]) ){
				int v = gr[u][i].v;
				if( w+gr[u][i].w < dist[v] ){
					dist[v] = w+gr[u][i].w;
					q.push( MP(-dist[v],v) );
				}
			}
		}
		
		goto testcase;
	}
	
	return 0;
}




















