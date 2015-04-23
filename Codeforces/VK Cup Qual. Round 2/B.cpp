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

	int n, m;
	cin >> n >> m;
	
	map< int, map< int, int > > markers, caps;
	
	REP( i, n ){
		int x, y; cin >> x >> y;
		markers[y][x]++;
	}
	REP( i, m ){
		int a, b; cin >> a >> b;
		caps[b][a]++;
	}
	
	int matched = 0, beautifully = 0;
	
	FORIT( dmt, markers ){
		
		int diameter = dmt->first;
		
		FORIT( clr, markers[diameter] ){
			int color = clr->first;
			int matchnow = min( markers[diameter][color], caps[diameter][color] );
			matched += matchnow;
			beautifully += matchnow;
			markers[diameter][color] -= matchnow;
			caps[diameter][color] -= matchnow;
		}
		
		int rem_markers = 0, rem_caps = 0;
		FORIT( clr, markers[diameter] ) rem_markers += (clr->second);
		FORIT( clr, caps[diameter] ) rem_caps += (clr->second);
		
		matched += min( rem_markers, rem_caps );
	}	
	
	cout << matched << " " << beautifully << "\n";
	
	return 0;
}

























