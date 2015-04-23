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

#define MAXN 300001
#define MAXR 100001

int bit[MAXR];
int best[MAXN];

struct data{
	int a, h, id;
	bool operator < ( const data& x ) const {
		if( a != x.a ) return a < x.a;
		return h < x.h;
	}
	bool operator == ( const data& x ) const {
		return (a == x.a) && (h == x.h);
	}
};

data rates[MAXN];

int MAXVAL;

int get( int idx ){
	int ans = 0;
	while( idx > 0 ){
		ans += bit[idx];
		idx -= (idx & -idx );
	}
	return ans;
}

void up( int idx ){
	while( idx <= MAXVAL ){
		bit[idx]++;
		idx += ( idx & -idx );
	}
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N;
	cin >> N;
	
	MAXVAL = 0;
	REP( i, N ){
		cin >> rates[i].a >> rates[i].h;
		rates[i].id = i;
		MAXVAL = MAX( MAXVAL, rates[i].h );
	}
	
	sort( rates, rates+N );
	
	REP( i, MAXVAL+1 ) bit[i] = 0;
	
	best[rates[0].id] = 0; up( rates[0].h );
	FOR( i, 1, N ){
		if( rates[i] == rates[i-1] ){
			best[ rates[i].id ] = best[ rates[i-1].id ];
		} else {
			best[ rates[i].id ] = get( rates[i].h );
		}
		up( rates[i].h );
	}
	
	REP( i, N ) cout << best[i] << "\n";
	
	return 0;
}
