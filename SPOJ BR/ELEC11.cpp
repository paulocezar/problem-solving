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

#define MAXN 2*10000

int comp[2][MAXN];
int dist[2][MAXN];
int seen[2][MAXN], seen_now;

map< int, int > hsh;
vector< pair<int,int> > gr[MAXN];

int val, cur_comp;

void dfs( int p, int u ){
	
	dist[p][u] = val;
	seen[p][u] = seen_now;
	comp[p][u] = cur_comp;
	
	REP( i, SIZE(gr[u]) ){
		int v = gr[u][i].first;
		
		if( seen[1-p][v] != seen_now ){
			
			if( p ) val -= gr[u][i].second;
			else val += gr[u][i].second;
			
			dfs( 1-p, v );
			
			if( p ) val += gr[u][i].second;
			else val -= gr[u][i].second;
			
		}
	}
	
}

int next_int(){
	int res = 0, sig = 1;
	char c = getchar_unlocked();
	while( !isdigit(c) && c != '-' ) c = getchar_unlocked();
	if( c == '-' ){ sig = -1; c = getchar_unlocked(); }
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return sig*res;
}

int main( int argc, char* argv[] ){
	
	int M, Q, X, Y, A;
	
	M = next_int();
	Q = next_int();
	while(  M || Q ){
		
		REP( i, 2*M ) gr[i].clear();
		hsh.clear();
		
		int id = 0;
		
		REP( i, M ){
			X = next_int();
			Y = next_int();
			A = next_int();
			if( X == Y ) A = 2*A;
			if( !hsh.count(X) ) hsh[X] = id++;
			if( !hsh.count(Y) ) hsh[Y] = id++;
			
			X = hsh[X];
			Y = hsh[Y];
			
			gr[ X ].PB( MP(Y,A) );
			gr[ Y ].PB( MP(X,A) );
		}
		
		seen_now++;
		cur_comp = 0;
		REP( i, id ){
			if( seen[0][i] != seen_now ){
				val = 0;
				dfs( 0, i );
				cur_comp++;
			}
		}
		
		while( Q-- ){
			X = next_int();
			Y = next_int();
			
			if( !hsh.count(X) || !hsh.count(Y) ) puts("*");
			else {
				X = hsh[X];
				Y = hsh[Y];
				
				if( comp[0][X] == comp[1][Y] ) printf("%d\n", ((dist[1][Y]-dist[0][X])>>(X==Y)) );
				else if( comp[1][X] == comp[0][Y] ) printf("%d\n", ((dist[1][X]-dist[0][Y])>>(X==Y)) );
				else if( (comp[0][X] == comp[1][X]) && (comp[0][Y] == comp[1][Y]) )
					printf("%d\n", (( ((dist[1][X]-dist[0][X])  +  (dist[1][Y]-dist[0][Y]))/2 )>>(X==Y)) );
				else puts("*");

			}
		}
		puts("-");
		
		M = next_int();
		Q = next_int();
	}	
	
	return 0;
}


























