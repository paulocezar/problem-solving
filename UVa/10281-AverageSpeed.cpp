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

int conv( string cur ){
	return 60*60*( 10*(cur[0]-'0') + (cur[1]-'0') ) + 60*( 10*(cur[3]-'0') + (cur[4]-'0') ) + ( 10*(cur[6]-'0') + (cur[7]-'0') );
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	string linha, etime;
	double cvel, vel = 0;
	int last = 0;
	double walked = 0;
	
	while( getline( cin, linha ) ){
		istringstream in( linha );
		in >> etime;
		int cur = conv( etime );
		if( in >> cvel ){
			walked += (vel/3.6)*( cur - last );
			last = cur;
			vel = cvel;
		} else {
			walked += (vel/3.6)*( cur - last );
			last = cur;
			cout << fixed << setprecision(2) << etime << " " << walked/1000.0 << " km\n";
		}
	}
	
	return 0;
}
