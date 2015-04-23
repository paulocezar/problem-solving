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

#define MAXN 20001
int bit[MAXN];
int N;

void up( int x ){
	while( x <= N ){
		bit[x]--;
		x += ( x & -x );
	}
}


void sum( int x ){
	while( x <= N ){
		bit[x]++;
		x += ( x & -x );
	}
}

int get( int x ){
	int ans = 0;
	while( x > 0 ){
		ans += bit[x];
		x -= ( x & -x );
	}
	return ans;
}

int out[MAXN+1];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T;
	cin >> T;
	while( T-- ){
		
		cin >> N;
		FILL( bit, 0 );
		REP( i, N ) sum( i+1 );
		
		int idx = 0;
		int total = N;
		
		FOR( i, 1, N+1 ){
			
			int g = get( idx );
			int frente = total - g;
			int v;
			
			if( i+1 > frente ){
				v = (i+1-frente)%total;
				if( v == 0 ) v = total;
			} else {
				v = g+i+1;
			}
			
			int lo = 1; int hi = N;
			while( lo < hi ){
				
				int mid = (lo+hi)/2;
				int mmid = get( mid );
				
				if( mmid > v ){
					hi = mid-1;
				} else if( mmid < v ) lo = mid+1;
				else hi = mid;
				
			}
			
			idx = hi;
			out[idx] = i;
			up( idx );
				
			total--;
		}
		
		FOR( i, 1, N+1 ) cout << out[i] << " ";
		
	}
	
	return 0;
}
