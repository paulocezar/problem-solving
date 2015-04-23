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

struct point_t {
	int x, y, z;
	point_t(){ x = y = z = 0; }
	point_t( int xx, int yy, int zz ) : x(xx), y(yy), z(zz) {}
	point_t operator - ( const point_t &a ){
		return point_t( x-a.x, y-a.y, z-a.z );
	}
	bool operator == ( const point_t &a ) const {
		return (x == a.x) && (y == a.y) && (z == a.z);
	}
};

#define MAXN 55

point_t point[MAXN];

bool colinear( point_t &a, point_t &b, point_t &c ){
	point_t ab = a-b, ac = a-c;
	int c1 = ab.y*ac.x - ab.x*ac.y;
	int c2 = ac.x*ab.z - ab.x*ac.z;
	int c3 = ac.y*ab.z - ab.y*ac.z;
	return ( c1 == 0 ) && ( c2 == 0 ) && ( c3 == 0 );	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t, N, cnt, ans, cx, cy, cz, d;
	point_t ab, ac;
	
	cin >> t;
	int teste = 0;
	while( t-- ){
		teste++;
		
		cin >> N;
		REP( i, N ) cin >> point[i].x >> point[i].y >> point[i].z;
		
	/*	if( teste == 11 ){
			cout << "----------\n";
			cout << N << endl;
			REP( i, N ) cout << point[i].x << " " << point[i].y << " " << point[i].z << endl;
			cout << "----------\n";
		}
	*/	
		ans = 0;
		if( N < 3 ) ans = N;
		else {
			REP( a, N ){
				FOR( b, a+1, N ){
						
						FOR( c, b+1, N ){
							
							if( !colinear( point[a], point[b], point[c] ) ){
						
								ab = point[b] - point[a];
								ac = point[c] - point[a];
												
								cx = ( ab.y*ac.z - ab.z*ac.y );
								cy = ( ab.z*ac.x - ab.x*ac.z );
								cz = ( ab.x*ac.y - ab.y*ac.x );
						
								d = -( cx*point[a].x + cy*point[a].y + cz*point[a].z );
		
								cnt = 0;
								REP( i, N ) if( (cx*point[i].x + cy*point[i].y + cz*point[i].z + d) == 0 ) cnt++;
								if( cnt > ans ) ans = cnt;
		
							} else if (!(point[a] == point[b]) && !(point[b] == point[c]) && !(point[a] == point[c])){
								cnt = 0;
								REP( i, N ) if(  colinear( point[a], point[b], point[i] ) ) cnt++;
								if( ans < cnt ) ans = cnt;
							}
							else {
								cnt = 0;
								REP( i, N ) if( point[i] == point[a] || point[i] == point[b] || point[i] == point[c] ) cnt++;
								if( ans < cnt ) ans = cnt;
							}
							
					}
				}
			}
		}
		cout << ans << "\n";
		
	}
	
	return 0;
}
