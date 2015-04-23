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

#define MAXN 1010

int N, P;
int in[MAXN], out[MAXN], parent[MAXN];
vector< pair<int,int> > gr[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int u, v, c;
	
	cin >> N >> P;
	REP( i, N ){
		in[i] = 0;
		out[i] = 0;
		gr[i].clear();
		parent[i] = -1;
	}
	
	REP( i, P ){
		cin >> u >> v >> c; u--; v--;
		gr[ u ].PB( MP(v, c) );
		in[v]++;
		out[u]++;
	}
	
	queue< pair<int,int> > q;
	
	REP( i, N ) if( !in[i] && out[i] ){
		q.push( MP( i, INF ) );
		parent[i] = i;
	}
	
	vector< pair<int, pair<int,int> > > ans;
	while( !q.empty() ){
		u = q.front().first;
		c = q.front().second; q.pop();
		if( !out[u] ){
			ans.PB( MP( parent[u], MP( u, c ) ) );
			continue;
		}
		REP( i, SIZE(gr[u]) ){
			v = gr[u][i].first;
			parent[v] = parent[u];
			q.push( MP(v, MIN(c, gr[u][i].second) ) );
		}
	}
	cout << SIZE(ans) << "\n";
	sort( ALL(ans) );
	REP( i, SIZE(ans) ){
		cout << ans[i].first+1 << " " << ans[i].second.first+1 << " " << ans[i].second.second << "\n";
	}
	return 0;
}




















