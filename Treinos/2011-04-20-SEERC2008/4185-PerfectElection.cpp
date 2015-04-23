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
#include <stack>

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


int N, M, C;
vector< int > gr[2002];
stack< int > S, P;
int pre[2002];
int comp[2002];
int curComp;

inline int inv( int a ){  return 2*N - a; }


void dfs( int u ){
	
	pre[u] = C++;
	S.push( u );
	P.push( u );
	
	REP( i, SIZE(gr[u]) ) if( pre[gr[u][i]] == -1 ){
		dfs( gr[u][i] );
	} else if( comp[gr[u][i]] == -1 ){
		
		while( !P.empty() && pre[ P.top() ] > pre[ gr[u][i] ] ) P.pop();
		
	}
	
	if(!P.empty() &&  P.top() == u ){

		while(!S.empty() &&  S.top() != u ){
			comp[ S.top() ] = curComp;
			S.pop();
		}
		
		if( !S.empty() ) S.pop();
		if( !P.empty() ) P.pop();
		comp[u] = curComp++;
	}
	
}


int sat(){
	
	REP( i, 2*N + 1 ){ 
		pre[i] = -1;
		comp[i] = -1;
	}
	
	while( !S.empty() ) S.pop();
	while( !P.empty() ) P.pop();
	
	C = 0;
	curComp = 0;
		
	REP( i, 2*N+1 ) if( pre[i] == -1 ) dfs( i );
	
	REP( i, N ) if( comp[i] == comp[inv(i)] ) return 0;
	
	return 1;
	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int a, b;
	
	while( cin >> N >> M ){
		
		REP( i, 2*N+1 ) gr[i].clear();
		
		while( M-- ){
			cin >> a >> b;

			a += N; b += N;
			
			gr[inv(a)].pb( b );
			gr[inv(b)].pb( a );
			
		}
		
		cout << sat() << "\n";
		
		
	}
		
	return 0;
}
