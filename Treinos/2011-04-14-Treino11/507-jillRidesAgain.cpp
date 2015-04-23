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

#define MAXS 20001

int64 a[MAXS];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int ct;
	cin >> ct;
	
	int tst = 1;
	
	while( ct-- ){
		
		int n;
		cin >> n;
		
		REP( i, n-1 ) cin >> a[i];
		
		int beg, end;
		int i, j;
		int64 best, cur;
		
		beg = end = 0;
		i = j = 0;
		best = 0;
		cur = 0;
		
		while( j < n-1 ){
			
			cur += a[j];
			if( cur > best ){
				
				best = cur;
				beg = i; end = j;
				
			} else if( cur == best ){
				if( j-i > end-beg ) beg = i, end = j;
			}
			
			if( cur < 0 ){ cur = 0; i = j+1; }
			j++;
		}
		
		if( best ) cout << "The nicest part of route " << tst++ << " is between stops " << beg+1 << " and " << end+2 << endl;
		else cout << "Route " << tst++ << " has no nice parts\n";
		
	}
	
	return 0;
}
