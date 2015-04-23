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

#define MAXN 505
int x[MAXN], y[MAXN];
int D[MAXN];
bool seen[MAXN];
int S, P;

double prim(){
	
	priority_queue< pair< int, int > > q;
	
	REP( i, P ) D[i] = INF, seen[i] = false;
	
	q.push( mp(0,0) );
	D[0] = 0;
	
	while( !q.empty() ){
		
		int dst = -q.top().first;
		int u = q.top().second; q.pop();
		
		if( seen[u] ) continue;
		seen[u] = true;
		
		REP( i, P ){
			int dist = SQR(x[u]-x[i])+SQR(y[u]-y[i]);
			if( !seen[i] && dist < D[i] ){
				D[i] = dist;
				q.push( mp(-D[i], i ) );
			}
		}
	}
	
	sort( D, D+P );
	return sqrt( D[P-S] );
	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int tcases;
	
	cin >> tcases;
	while( tcases-- ){
		
		cin >> S >> P;
		REP( i, P ) cin >> x[i] >> y[i];
		cout << fixed << setprecision(2) << prim() << "\n";
		
	}
	
	return 0;
}
