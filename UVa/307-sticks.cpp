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

int a[1001];
bool used[1001];
int n, src, lookinfor, sneeded;

bool bt( int pos, int len ){
	
	if( sneeded == 0 ) return true;
	
	FOR( i, pos, n ) if( !used[i] ){
		
		if( len+a[i] == lookinfor ){
			used[i] = true;
			sneeded--;
			if( bt(0, 0) ) return true;
			sneeded++;
			used[i] = false;
			return false;	
		} else if( len+a[i] < lookinfor ){
			used[i] = true;
			if( bt( i+1, len+a[i] ) ) return true;
			used[i] = false;
			while( i+1 < n && a[i+1] == a[i] ) i++;
		}
		
		/* sem isso -> TLE ... se esse e o primeiro stick que eu coloquei, e nao teve como resolver..
		  nao importa qual outro eu coloque tambem nao vai dar pra resolver. */
		if( len == 0 ) return false;
		
	}
	
	return false;
}

int main( int argc, char* argv[] ){

	while( scanf("%d", &n ) && n ){
		
		int total = 0;
		REP( i, n ){ 
			scanf("%d", &a[i] );
			total += a[i];
			used[i] = false;
		}
		sort( a, a+n, greater<int>() );
		
		vector< int > divs;
		for( int i = 1; i*i <= total; i++ ) if( total % i == 0 ){
			if( i >= a[0] ) divs.pb( i );
			if( (total/i) > i && (total/i) >= a[0] ) divs.pb( total/i );
		}
		sort( divs.begin(), divs.end() );		
		
		REP( i, SIZE(divs) ) if( divs[i] <= total/2 ){
			lookinfor = divs[i];
			sneeded = total/divs[i];
			
			if( bt( 0, 0 ) ){
				printf( "%d\n", divs[i] );
				break;
			}
		} else {
			printf("%d\n", total );
			break;
		}
		
	}
	
	
	return 0;
}
