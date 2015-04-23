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
#define RTI(X) __typeof((X).rbegin())
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

#define MAXN 222

string name[MAXN];
int64 pp[MAXN];

int ans[64000], leng[MAXN];

void calc( int len, string &ss, int64 &pptr ){
	pptr = 0;
	
	string s = "#";
	REP( i, len ) { s += ss[i]; s += "#"; }
	len = 2*len + 1;
	
	for( int i = 0; i < len; i++ ) ans[i] = 0;

	int cur = 1;
	while( cur < len ){
		
		while( (cur > ans[cur])
				&& (cur+ans[cur]+1 < len)
				&& ((s[cur-ans[cur]-1]|32) == (s[cur+ans[cur]+1]|32)) ) ans[cur]++;
		
		int j = 1;
		while( (cur+j < len) && (j < ans[cur]-ans[cur-j]) ){
			ans[cur+j] = ans[cur-j];
			j++;
		}
		
		if( cur+j < len )
			ans[cur+j] = ans[cur]-j;
		cur += j;
		
	}
	//for( int i = 0; i < len; i++ ) cout << ans[i] << " "; cout << endl;
	for( int i = 2; i < len; i+=2 ) pptr += (int64(ans[i]/2LL)*int64(ans[i]+2LL))/2LL;
	
}

int N, s, t, c;
int cap[MAXN][MAXN], ocap[MAXN][MAXN];
int parent[MAXN], flow;
vector< int > gr[MAXN];

bool augment(){
	int u, v;
	queue< int > q;
	REP( i, N ) parent[i] = -1;
	parent[s] = 0;
	q.push( s );
	while( !q.empty() ){
		u = q.front(); q.pop();
		for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
			v = gr[u][i];
			if( parent[v] == -1 && cap[u][v] > 0 ){
				parent[v] = u;
				if( v == t ) goto calc_flow;
				q.push( v );
			}
		}
	}
	return false;
calc_flow:
	parent[s] = -1;
	v = t; flow = INF;
	while( parent[v] != -1 ){
		flow = min( flow, cap[parent[v]][v] );
		v = parent[v];
	}
	v = t;
	while( parent[v] != -1 ){
		cap[parent[v]][v] -= flow;
		cap[v][parent[v]] += flow;
		v = parent[v];
	}
	return true;
}

int64 maxflow(){
	int64 ans = 0;
	while( augment() ) ans += flow;
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int m, k;
	while( (cin >> N >> m >> k) && (N+m+k) ){
		
		REP( i, N ){ cin >> name[i]; leng[i] = SIZE(name[i]); }
		REP( i, N ){ gr[i].clear(); REP( j, N ) ocap[i][j] = 0; }
		
		map< int64, int > app;
		REP( i, N ){ calc( leng[i], name[i], pp[i] ); app[pp[i]]++; }
		
		int64 needed = 0;
		if( SIZE(app) >= k ){
			RTI(app) ax = app.rbegin();
			
			while( --k ) ax++;
			needed = ax->first;
		}
		
		REP( i, m ){
			int u, v, x; cin >> u >> v >> x;
			if( !(ocap[u][v] || ocap[v][u]) ){ gr[u].PB( v ); gr[v].PB( u ); }
			ocap[u][v] = x;
		}

		int k = 0;
		REP( i, N ) if( pp[i] >= needed ) k++;
		cout << k << "\n";
		s = 0;
		REP( i, N ) if( pp[i] >= needed ){
			t = i;
			REP( a, N ) REP( b, N ) cap[a][b] = ocap[a][b];
			cout << name[i] << " (" << pp[i] << ") ";
			if( s==t ) cout << "0\n";
			else cout << maxflow() << "\n";
		}
		
	}
		
	return 0;
}

























