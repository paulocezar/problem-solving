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

#define MAXN 100001
#define LGMN 17

int segt[1<<(LGMN+1)];
char todo[1<<(LGMN+1)];
int from, to;

void push( int node, int beg, int end ){
	
	todo[node] = 1 - todo[node];
	segt[node] = (end-beg+1) - segt[node];
	
}

void update( int node, int beg, int end ){
	if( beg >= from && end <= to ){
		push( node, beg, end );
	} else {
		int lft = 2*node + 1;
		int rgt = 2*node + 2;
		int mid = (beg+end)/2;
		
		if( todo[node] ){
			push( lft, beg, mid );
			push( rgt, mid+1, end );
			todo[node] = 0;
		}
		
		if( mid >= from ) update( lft, beg, mid );
		if( mid+1 <= to ) update( rgt, mid+1, end );
		segt[node] = segt[lft] + segt[rgt];	
	}	
}

int query( int node, int beg, int end ){
	if( beg >= from && end <= to ){
		return segt[node];
	} else {
		int lft = 2*node + 1;
		int rgt = 2*node + 2;
		int mid = (beg+end)/2;
		
		if( todo[node] ){
			push( lft, beg, mid );
			push( rgt, mid+1, end );
			todo[node] = 0;
		}
		
		if( mid < from ) return query( rgt, mid+1, end );
		if( mid+1 > to ) return query( lft, beg, mid );
		return query( lft, beg, mid ) + query( rgt, mid+1, end );	
	}	
}


int main( int argc, char* argv[] ){

	//ios::sync_with_stdio( false );
	
	int N, M;
	scanf("%d %d", &N, &M );
	FILL( segt, 0 );
	FILL( todo, 0 );
	
	int op;
	while( M-- ){
		scanf("%d %d %d", &op, &from, &to );
		if( op == 0 ) update( 0, 1, N );
		else printf("%d\n", query( 0, 1, N ) );
	}
	
	return 0;
}


