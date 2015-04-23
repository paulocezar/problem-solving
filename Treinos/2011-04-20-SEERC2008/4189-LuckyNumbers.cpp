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

vector< int64 > lucky;
int64 very[350000];
int verySz;

void build( int64 cur ){
	
	if( cur > 1000000000000LL ) return;
	if( cur ) lucky.pb( cur );
	
	build( 10LL*cur + 4LL );
	build( 10LL*cur + 7LL );
	
}

void createVeryLucky(){
	
	int64 cur;
	set< int64 > veryLucky;
	
	queue< int64 > q;
	sort( lucky.begin(), lucky.end() );
	REP( i, SIZE(lucky) ) { 
		veryLucky.insert( lucky[i] ).second;
		q.push( lucky[i] );
	}
	
	while( !q.empty() ){
	
		cur = q.front(); q.pop();
		
		REP( i, SIZE(lucky) ) if( cur*lucky[i] > 1000000000000LL ) break; else if( veryLucky.insert( cur*lucky[i] ).second ) q.push( cur*lucky[i] );
		
	}
	
	verySz = 0;
	for( set<int64>::iterator xx = veryLucky.begin(); xx != veryLucky.end(); xx++ ) very[ verySz++ ] = *xx;

}


int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	build( 0 );
	createVeryLucky();
	
	int t;
	cin >> t;
	while( t-- ){
		int64 A, B;
		cin >> A >> B;
		
		int64* end = upper_bound( very, very+verySz, B ); end--;
		int64* beg = lower_bound(  very, very+verySz, A );
		
		cout << end - beg + 1 << "\n";
	}
	
	
	
	
	return 0;
}
