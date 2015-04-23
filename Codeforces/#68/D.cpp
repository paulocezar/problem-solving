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

typedef pair<int,int> segt;

int N;
map< int, int > bit;
void up( int x ){ while( x <= N ){ bit[x]++; x += x & (-x); } }
void down( int x ){ while( x <= N ){ bit[x]--; if( bit[x] == 0 ) bit.erase(x); x += x & (-x); } }
int get( int x ){ int freq = 0; while( x > 0 ){ freq += bit[x]; x -= x & (-x); } return freq; }

struct comp{
	bool operator()( const segt& x, const segt& y ) const {
		int sx = x.second - x.first;
		int sy = y.second - y.first;
		if( sx != sy ) return sx > sy;
		return x > y;
	}
};

set< segt, comp > h;
set< int > used;

map< int, int > put;

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int Q, x, i, j;
	
	cin >> N >> Q;
	h.insert( segt( 1, N ) );
	
	while( Q-- ){
		cin >> x;
		if( x ){
			
			if( put[x] ){
				
				int pos = put[x];
				TI( used ) itnxt, itprv;
				itnxt = used.upper_bound( pos );
				itprv = used.lower_bound( pos );
				
				int nxt, prv;
				nxt = prv = -1;
				if( itprv != used.begin() ){
					itprv--;
					prv = *itprv;
				} else {
					prv = 0;
				}
				
				if( itnxt != used.end() ){
					nxt = *itnxt;
				} else {
					nxt = N+1;
				}
				
				used.erase( pos );
				put.erase( x );
				down( pos );
				
				int from, to;
				from = to = pos;
				
				if( nxt != pos+1 ){
					h.erase( segt( pos+1, nxt-1 ) );
					to = nxt-1;
				}
				
				if( prv+1 != pos ){
					h.erase( segt(prv+1, pos-1) );
					from = prv+1;
				}
				
				h.insert( segt( from, to ) );
						
			} else {
				segt fre = *(h.begin());
				h.erase( h.begin() );	
				
				int pos = fre.first + (fre.second-fre.first+1)/2;
				
				put[x] = pos;
				used.insert( pos );
				up( pos );
				
				if( pos-1 >= fre.first ) h.insert( segt( fre.first, pos-1 ) );
				if( pos+1 <= fre.second ) h.insert( segt( pos+1, fre.second ) );	
			}
			
		} else {
			cin >> i >> j;
			cout << get(j) - get(i-1) << "\n";
		}
	}
	
	return 0;
}
