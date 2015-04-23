#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bitset>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main( int argc, char* argv[] ){
		
	int N, E;
	scanf("%d %d", &N, &E );
	set<int> init;
	
	pair<int,int> pos[E];
	REP( i, E ){
		scanf("%d %d", &pos[i].first, &pos[i].second );
		pos[i].first--;
		init.insert( pos[i].first );
	}
	
	int ans = N;
	sort( pos, pos+E );
	FOR( i, 1, E ){
		
		set< int > nw;
		int d = pos[i].first - pos[0].first;
		if( pos[0].second == -1 ) d = N - d;
		REP( j, E ){
			int mvs = ( pos[j].first + pos[j].second*d + N ) % N;
			if( init.find( mvs ) != init.end() ) nw.insert( mvs );
			else break;
		}
		if( SIZE(nw) == E ) ans = MIN( ans, d );
		
	}
	
	printf("%d\n", ans );
	
	return 0;
}




















