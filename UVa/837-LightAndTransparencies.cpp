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

struct event_t{
	double x, tr;
	char tp;
	bool operator < ( const event_t& a ) const {
		if( x != a.x ) return x < a.x;
		return tp < a.tp;
	}
};

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );

	double x1, y1, x2, y2, transp;
	
	int T;
	cin >> T;
	while( T-- ){
	
		int N;
		cin >> N;
		
		event_t event[2*N];
		set< double > xxx;
		
		REP( i, N ){
			cin >> x1 >> y1 >> x2 >> y2 >> transp;
			event[2*i].x = x1;
			event[2*i+1].x = x2;
			event[2*i].tr = event[2*i+1].tr = transp;
			if( x1 < x2 ){ event[2*i].tp = 0; event[2*i+1].tp = 1; }
			else{ event[2*i].tp = 1; event[2*i+1].tp = 0; }
			xxx.insert( x1 );
			xxx.insert( x2 );
		}
		sort( event, event + 2*N );
		cout << SIZE( xxx ) + 1 << "\n";
		cout << "-inf " << fixed << setprecision( 3 ) << event[0].x << " 1.000\n";
		
		double cur = event[0].tr;
		double last = event[0].x;
		FOR( i, 1, 2*N ){
			if( event[i].x != last ){
				cout << fixed << setprecision( 3 ) << last << " " << event[i].x << " " << cur << "\n";
				last = event[i].x;
			}
			if( event[i].tp == 0 ) cur *= event[i].tr;
			else if( event[i].tp == 1 ) cur /= event[i].tr;
		}
		cout << fixed << setprecision( 3 ) << last << " +inf 1.000\n";
		if( T ) cout << "\n";
	}
	
	return 0;
}
