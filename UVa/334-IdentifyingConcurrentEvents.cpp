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

#define MAXV 222
bool gr[MAXV][MAXV];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, V, M, e, old, tc = 1;
	string nm, nm2;
	
	while( (cin>>N) && N ){
		
		FILL( gr, false );
		map< string, int > id;
		vector< string > evt;
		
		V = 0;
		REP( i, N ){
			cin >> e; old = -1;
			while( e-- ){
				cin >> nm;
				if( id.find(nm) == id.end() ) id[nm] = V++, evt.PB( nm );
				if( old != -1 ) gr[ old ][ id[nm] ] = true;
				old = id[nm];
			}
		}
		cin >> M;
		while( M-- ){
			cin >> nm >> nm2;
			if( id.find(nm) == id.end() ) id[nm] = V++, evt.PB( nm );
			if( id.find(nm2) == id.end() ) id[nm2] = V++, evt.PB( nm2 );
			gr[ id[nm] ][ id[nm2] ] = true;
		}
		
		REP( k, V )
			REP( i, V )
			REP( j, V )
				gr[i][j] = gr[i][j] || ( gr[i][k] && gr[k][j] );
		
		vector< pair<int,int> > ans;
		REP( i, V ) FOR( j, i+1, V-1 ) if( !gr[i][j] && !gr[j][i] )
			ans.PB( MP(i,j) );
		if( SIZE(ans) ) cout << "Case " << tc++ << ", " << SIZE(ans) << " concurrent events:\n";
		else cout << "Case " << tc++ << ", " << "no concurrent events.";
		REP( i, MIN(SIZE(ans), 2) ) cout << "(" << evt[ ans[i].first ] << "," << evt[ ans[i].second ] << ") ";
		cout << "\n";
	} 
	
	return 0;
}




















