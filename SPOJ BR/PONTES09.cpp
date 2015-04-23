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

int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

vector< vector< pair<int,int> > > gr;
int dist[1111];

int main( int argc, char* argv[] ){
	
	int N, M;
	N = next_int();
	M = next_int();
	
	gr.resize(N+2);
	FOR( i, 0, N+1 ){ gr[i].clear(); dist[i] = INF; }
	
	while( M-- ){
		int S = next_int();
		int T = next_int();
		int B = next_int();
		gr[S].PB( MP(T,B) );
		gr[T].PB( MP(S,B) );
	}
	
	priority_queue< pair<int,int> > q;
	q.push( MP(0,0) );
	dist[0] = 0;
	
	while( !q.empty() ){
		int u = q.top().second;
		int dis = -q.top().first; q.pop();
		if( u == N+1 ) break;
		if( dis > dist[u] ) continue;
		REP( i, SIZE(gr[u]) ){
			int v = gr[u][i].first;
			int cs = gr[u][i].second;
			if( dis+cs < dist[v] ){
				dist[v] = dis+cs;
				q.push( MP(-dist[v],v) );
			}
		}
	}
	
	printf("%d\n", dist[N+1] );
	
	return 0;
}


























