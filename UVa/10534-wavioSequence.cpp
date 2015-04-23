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

#define MAXN 10000

int a[MAXN];
int lis[MAXN];
int lds[MAXN];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N;
	while( cin >> N ){
		
		multiset< int > st;
		multiset<int>::iterator it;
		
		REP( i, N ){
			cin >> a[i];
			
			st.insert( a[i] ); it = st.find( a[i] ); it++;
			if( it != st.end() ) st.erase( it );
			
			lis[i] = SIZE(st);
		}
		
		st.clear();
		RREP( i, N ){
			
			st.insert( a[i] ); it = st.find( a[i] ); it++;
			if( it != st.end() ) st.erase( it );
			
			lds[i] = SIZE(st);	
		}
		
		//REP( i, N ) cout << lis[i] << " "; cout << endl;
		//REP( i, N ) cout << lds[i] << " "; cout << endl;
		
		int ans = 1;
		
		REP( i, N ) ans = MAX( ans, 2*MIN( lis[i], lds[i] ) - 1 );
		
			
		cout << ans << "\n";
	}
	
	return 0;
}
