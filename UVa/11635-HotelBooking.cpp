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

#define MAXN 10000
#define MAXH 10

vector< pair<int,int> > gr[MAXN];
bool ht[MAXN];
int seen[MAXN][60*MAXH+1];

struct st{
	int u, tm, slp; 
	st( int uu = 0, int tt = 0, int ss = 0 ) : u(uu), tm(tt), slp(ss) {}
	bool operator < ( const st& t ) const {
		if( slp != t.slp ) return slp > t.slp;
		if( tm != t.tm ) return tm > t.tm;
		return u > t.u;
	}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, M, h, hh, u, v, t;
	
	while( (cin>>N) && N ){
		
		REP( i, N ){
			gr[i].clear();
			ht[i] = false;
			REP( j, 601 ) seen[i][j] = INF;
		}
		
		cin >> h;
		while( h-- ){
			cin >> hh; hh--;
			ht[ hh ] = true;
		}
		
		cin >> M;
		while( M-- ){
			cin >> u >> v >> t;
			u--; v--;
			gr[u].PB( MP(v, t) );
			gr[v].PB( MP(u, t) );
		}
		
		priority_queue< st > q;
		q.push( st(0,0,0) ); seen[0][0] = 0;
		st cur;
		while( !q.empty() ){
			cur = q.top(); q.pop();
			u = cur.u;
		
			if( u == N-1 ){ cout << cur.slp; goto hell; }
			if( cur.slp > seen[u][cur.tm] ) continue;
			
			REP( i, SIZE(gr[u]) ){
				v = gr[u][i].first;
				t = cur.tm + gr[u][i].second;
			
				if( t > 600 ) continue;
				if( cur.slp < seen[ v ][ t ] ){
					seen[ v ][ t ] = cur.slp;
					q.push( st( v, t, cur.slp ) );
				}
				if( ht[ v ] && (cur.slp+1 < seen[ v ][0]) ){
					seen[ v ][ 0 ] = cur.slp+1;
					q.push( st( v, 0, cur.slp+1 ) );
				}
			} 
		}
			cout << "-1";
		hell:
			cout << "\n";
	}
	
	return 0;
}




















