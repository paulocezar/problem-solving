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
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1001
int N, M;
vector<int> gr[MAXN];
int w[MAXN], pi[MAXN], parent[MAXN];
set< int > RN[ MAXN ];

struct comp {
	bool operator ()( const int& a, const int& b ) const {
		if( w[a] != w[b] ) return w[a] > w[b];
		return a > b;
	}
};

set< int, comp > q;
char chordal(){
	
	for( int i = N; i >= 1; i-- ){
		int z = *q.begin();
		q.erase( z );
		pi[z] = i;
		
		for( int j = 0; j < SIZE( gr[z] ); j++ ) if( pi[ gr[z][j] ] == 0 ){
			q.erase( gr[z][j] );
			w[ gr[z][j] ]++;
			q.insert( gr[z][j] );
		}
	}
	
	for( int i = 1; i <= N; i++ ){
		for( int j = 0; j < SIZE( gr[i] ); j++ ) if( pi[ gr[i][j] ] > pi[ i ] ){
			RN[ i ].insert( gr[i][j] );
			if( pi[ gr[i][j] ] < pi[ parent[i] ] ) parent[i] = gr[i][j];
		}
	}
	
	for( int i = 1; i <= N; i++ ){
		if( parent[i] == 0 ) continue;
		RN[ i ].erase( parent[i] );
		FORIT( x, RN[i] ) if( RN[ parent[i] ].find( *x ) == RN[ parent[i] ].end() ) return '0';
		RN[ i ].insert( parent[i] );
	}
	
	return '1';
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int u, v;
	string ans = "";
	pi[0] = INF; gr[0].clear(); RN[0].clear();
	
	cin >> N >> M;
	while( N + M ){
		
		for( int i = 1; i <= N; i++ ){
			gr[i].clear();
			w[i] = 0;
			pi[i] = 0;
			parent[i] = 0;
			q.insert( i );
			RN[i].clear();
		}
		
		while( M-- ){
			cin >> u >> v;
			gr[u].PB( v );
			gr[v].PB( u );
		}
		
		ans += chordal();
		
		cin >> N >> M;
	}
	cout << ans << "\n";
	
	return 0;
}



















