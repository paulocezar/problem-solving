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

#define LGMX 11

int segt[1<<LGMX][1<<LGMX];

int x, y, cur;

int gety( int xnode, int node, int lo, int hi ){
	if( lo >= 1 && hi <= y ) return segt[xnode][node];
	int mid = (lo+hi)/2;
	int q1, q2;
	q1 = q2 = 0;
	if( mid > 0 ) q1 = gety( xnode, 2*node + 1, lo, mid );
	if( y >= mid+1 ) q2 = gety( xnode, 2*node + 2, mid+1, hi );
	return MAX( q1, q2 );
}

int get( int node, int lo, int hi ){
	if( lo >= 1 && hi <= x ) return gety( node, 0, 1, 1000 );
	int mid = (lo+hi)/2;
	int q1, q2;
	q1 = q2 = 0;
	if( mid > 0 ) q1 = get( 2*node + 1, lo, mid );
	if( x >= mid+1 ) q2 = get( 2*node + 2, mid+1, hi );
	return MAX( q1, q2 );
}

int main( int argc, char* argv[] ){

	int t, n;
	int yseg, xnode, ynode, lo, hi, mid;
	
	scanf("%d", &t );
	
	while( t-- ){
		scanf("%d", &n );
		FILL( segt, 0 );
		
		REP( i, n ){
			scanf("%d %d", &x, &y );
			cur = get( 0, 1, 1000 ) + 1;
			
			yseg = 0;
			lo = 1; hi = 1000;
			while( lo < hi ){
				mid = (lo+hi)/2;
				if( mid < y ){ yseg = 2*yseg+2; lo = mid+1; }
				else{ yseg = 2*yseg+1; hi = mid; }
			}
			
			xnode = 0;
			lo = 1; hi = 1000;
			while( lo < hi ){
				mid = (lo+hi)/2;
				ynode = yseg;
				while( true ){
					segt[xnode][ynode] = MAX( segt[xnode][ynode], cur );
					if( ynode == 0 ) break;
					ynode = (ynode-1)/2;
				}
				if( mid < x ){ xnode = 2*xnode+2; lo = mid+1; }
				else{ xnode = 2*xnode+1; hi = mid; }
			}
			ynode = yseg;
			while( true ){
				segt[xnode][ynode] = MAX( segt[xnode][ynode], cur );
				if( ynode == 0 ) break;
				ynode = (ynode-1)/2;
			}
			
		}
		printf("%d\n", segt[0][0] );
	}
	
	return 0;
}
