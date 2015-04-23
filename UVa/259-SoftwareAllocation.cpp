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
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 40

vector< int > gr[MAXN];
int cap[MAXN][MAXN], parent[MAXN];
int flow;

void augment(){
	FILL( parent, -1 );
	
	queue< int > q;
	q.push( 0 ); parent[0] = 0;
	
	int u; 
	while( !q.empty() ){
		u = q.front(); q.pop();
		REP( i, SIZE(gr[u]) ) if( parent[ gr[u][i] ] == -1 && cap[ u ][ gr[u][i] ] > 0 ){
			parent[ gr[u][i] ] = u;
			if( gr[u][i] == 1 ) goto calc_flow;
			q.push( gr[u][i] );
		}
	}
	return;
calc_flow:
	u = 1;
	parent[0] = -1;
	while( parent[u] != -1 ){
		flow = MIN( flow, cap[ parent[u] ][ u ] );
		u = parent[u];
	}
}

int maxflow(){
	int ans = 0;
	while( true ){
		flow = INF;
		augment();
		
		if( flow == INF ) break;
		int v = 1;
		while( parent[v] != -1 ){
			cap[ parent[v] ][ v ] -= flow;
			cap[ v ][ parent[v] ] += flow;
			v = parent[v];
		}
		ans += flow;
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	string line;
	
	REP( i, 26 ){ gr[0].PB( i+2 ); gr[i+2].PB( 0 ); }
	REP( i, 10 ){ gr[28+i].PB(1); gr[1].PB( 28+i ); }
	REP( i, 26 ) REP( j, 10 ){ gr[i+2].PB( 28+j ); gr[28+j].PB( i+2 ); }
	
	while( getline(cin, line) ){
		
		FILL( cap, 0 );

		int nd = 0;
		while( !line.empty() ){
			cap[0][line[0]-'A'+2] += (line[1]-'0');
			nd += (line[1]-'0');
			int i = 3;
			while( line[i] != ';' ) cap[ line[0]-'A'+2 ][ line[i]-'0'+28 ]++, i++; 		
			if( !getline( cin, line ) ) break;
		}
		REP( i, 10 ) cap[ 28+i ][ 1 ] = 1;
		
		int mxflw = maxflow();
		
		if( nd != mxflw ) cout << "!\n";
		else {
			REP( i, 10 ) if( cap[ 28+i ][ 1 ] == 0 ){
					REP( j, 26 ) if( cap[28+i][j+2] == 1 ) {
						cout << char( 'A'+j );
						break;
					}
			} else cout << "_";
			cout << "\n";
		}
		
	}
	
	return 0;
}




















