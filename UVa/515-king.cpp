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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct edge_t{
	int u, v, cst;
};

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N, M;
	int u, v, k;
	string op;
	
	cin >> N;
	while( N ){
		cin >> M;
		
		int D[N+1];
		vector< edge_t > edges( M );
		
		REP( i, M ){
			cin >> u >> v >> op >> k;
			if( op[0] == 'g' ){ // s[u-1] - s[u+v] <= -(k+1) 
				edges[i].u = u+v;
				edges[i].v = u-1;
				edges[i].cst = -k-1;
			} else { // s[u+v] - s[u-1] <= (k-1)
				edges[i].u = u-1;
				edges[i].v = u+v;
				edges[i].cst = k-1;			
			}
		}
		FILL( D, 0 );
		
		REP( i, N )
			REP( j, M )
				if( D[edges[j].v] > (D[edges[j].u]+edges[j].cst) )
					D[edges[j].v] = (D[edges[j].u]+edges[j].cst);
		
		bool cycle = false;
		REP( j, M )
			if( D[edges[j].v] > (D[edges[j].u]+edges[j].cst) ){
				cycle = true;
				break;
			}	
		
		if( cycle ) cout << "successful conspiracy\n";
		else cout << "lamentable kingdom\n";	
		
		cin >> N;
	}
	
	return 0;
}
