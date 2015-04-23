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

struct edge_t{
	int v, w;
	edge_t( int vv = 0, int ww = 0 ) : v(vv), w(ww) {}
};

vector< edge_t > gr[MAXN];
int dist[MAXN];


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, M, A, B;
	while( (cin >> N >> M >> A >> B) && (N+M+A+B) ){
		FOR( i, 0, N+1 ){ gr[i].clear(); dist[i] = INF; }
		REP( i, A ){
			int X; cin >> X; X++;
			gr[0].PB( edge_t(X,0) );
		}
		REP( i, B ){
			int X; cin >> X; X++;
			gr[X].PB( edge_t(N+1,0) );
		}
		while( M-- ){
			int X, Y, C;
			cin >> X >> Y >> C; X++; Y++;
			gr[X].PB( edge_t(Y,C) );
			gr[Y].PB( edge_t(X,C) );
		}
		dist[0] = 0;
		priority_queue< pair<int,int> > q;
		q.push( MP(0,0) );
		while( !q.empty() ){
			
			int u = q.top().second;
			int cst = -q.top().first; q.pop();
			
			if( u == N+1 ) break;
			if( cst > dist[u] ) continue;
			
			REP( i, SIZE(gr[u])){
				if( cst+gr[u][i].w < dist[gr[u][i].v] ){
					dist[gr[u][i].v] = cst+gr[u][i].w;
					q.push( MP(-dist[gr[u][i].v], gr[u][i].v) );
				}
			}
		}
		cout << dist[N+1] << "\n";
	}
			
	return 0;
}

























