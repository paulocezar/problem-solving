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

#define MAXN 10001
#define MAXC 6

int N, dp[MAXN][MAXC], parent[MAXN];
vector< int > tree[MAXN]; 

int solve( int u, int clr ){
	
	if( SIZE(tree[u]) == 0 ) return clr+1;
	//cout << "at " << u << " clr " << clr << endl;
	int& r = dp[u][clr];
	if( r == -1 ){
		
		r = clr+1;
		REP( w, SIZE(tree[u]) ){
			int cur = INF;
			REP( nclr, MAXC ) if( nclr != clr )
				cur = MIN( cur, solve( tree[u][w], nclr ) );
			r += cur;
		}
		
	}
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	while( cin >> N && N ){
		cin.ignore();
		
		REP( i, N ) parent[i] = -1;
		
		string linha;
		REP( i, N ){
			getline( cin, linha );
			istringstream in( linha );
			
			int u, v;
			in >> u; in.ignore();
			tree[u].clear();
			while( in >> v ){
				tree[u].pb( v );
				parent[v] = u;
			}
		}
		
		REP( i, N ) REP( j, MAXC ) dp[i][j] = -1;
		
		int ans = INF;
		REP( j, N ) if( SIZE(tree[j]) && parent[j] == -1 ){
			REP( i, MAXC ) ans = MIN( ans, solve( j, i ) );
			break;
		}
		cout << ans << "\n";
		
	}
	
	return 0;
}


































