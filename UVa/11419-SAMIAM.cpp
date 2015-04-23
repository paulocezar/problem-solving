/*
 *  Problema:
 *  Tecnica Utilizada:  
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

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
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

#define MAXN 1001

int vx[MAXN], vy[MAXN];
int mx[MAXN], my[MAXN];
vector<int> graph[MAXN];
bool vis[MAXN];
int N, M;

bool dfs( int u ){
	if( u < 0 ) return true;
	if( vis[u] ) return false;
	vis[u] = true;
	
	REP( w, SIZE(graph[u]) ) if( dfs( my[graph[u][w]] ) ){
		mx[u] = graph[u][w];
		my[graph[u][w]] = u;
		return true;
	}
	
	return false;
}

bool dfsExp( int u ){
	FOR( i, 1, N+1 ) vis[i] = false;
	return dfs( u );
}

int bipMatch(){
	int ans = 0;
	FOR( i, 1, N+1 ) mx[i] = -1;
	FOR( i, 1, M+1 ) my[i] = -1;
	bool first;
	bool augment = true;
	
	while( augment ){
		first = true;
		augment = false;
		FOR( i, 1, N+1 ) if( mx[i] == -1 ){
			bool r;
			
			if( first ) r = dfsExp( i );
			else r = dfs(i);
			
			first = false;
			if( r ){
				ans++;
				augment = true;
			}
		}
	}
	
	return ans;
}

void buildVC( int u ){
	vis[u] = true;
	vx[u] = 0;
	REP( w, SIZE(graph[u]) )if( graph[u][w] != mx[u] && vy[ graph[u][w] ] == 0 ){
		vy[ graph[u][w] ] = 1;
		if( !vis[ my[ graph[u][w] ] ] ) buildVC( my[ graph[u][w] ] );
	}
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int E, x, y;
	
	cin >> N >> M >> E;
	while( N+M+E ){
		
		REP( i, N ) graph[i+1].clear();
		
		while( E-- ){
			cin >> x >> y;
			graph[x].pb( y );
		}
		
		cout << bipMatch();
		
		// T ~ Unmatched L + reachable using alternating paths
		// ANS ..  (L \ T) U ( R intersect T )
		FOR( i, 1, N+1 ){ 
			vis[i] = false;
			if( mx[i] == -1 ) vx[i] = 0;  //  T  -- unmatched L
			else vx[i] = 1;				  // L \ T -- for now..
		}
		FOR( i, 1, M+1 ) vy[i] = 0;      // R  .. ~T -- for now..
		
		FOR( i, 1, N+1 )if( vx[i] == 0 && !vis[i] ) buildVC( i );
		
		FOR( i, 1, N+1 ) if( vx[i] ) cout << " r" << i;
		FOR( i, 1, M+1 ) if( vy[i] ) cout << " c" << i;
		cout << "\n";
		
		cin >> N >> M >> E;
	}
	
	return 0;
}


































