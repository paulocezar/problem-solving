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

#define MAXN 100001
#define MAXD 1001

int tree[ MAXD ][ MAXD ];

int main( int argc, char* argv[] ){

	int t, n;
	int x, y, cur, curx, cury;
	
	scanf("%d", &t );
	
	while( t-- ){
		
		scanf("%d", &n );
		FILL( tree, 0 );
		
		REP( i, n ){
			
			scanf("%d %d", &x, &y );
			
			cur = 0;
			curx = x;
			while( curx > 0 ){
				cury = y;
				while( cury > 0 ){
					cur = MAX( cur, tree[curx][cury] );
					cury -= ( cury & -cury );
				}
				curx -= ( curx & -curx );
			}
			
			cur++;
			
			while( x < MAXD ){
				cury = y;
				while( cury < MAXD ){
					tree[x][cury] = MAX( tree[x][cury], cur );
					cury += ( cury & -cury );
				}
				x += ( x & -x );
			}
			
		}
		
		cur = 0;
		x = 1000;
		while( x > 0 ){
			y = 1000;
			while( y > 0 ){
				cur = MAX( cur, tree[x][y] );
				y -= ( y & -y );
			}
			x -= ( x & -x );
		}
		
		printf("%d\n", cur );
	}
	
	return 0;
}
