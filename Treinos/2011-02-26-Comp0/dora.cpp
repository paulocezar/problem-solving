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

#define MAXN 1001
vector< int > primos;
void crivo(){
	bool primo[MAXN];
	REP( i, MAXN ) primo[i] = i&1;
	primo[1] = 0; primo[2] = 1;
	for( int i = 3; i <= 32; i++ )if( primo[i] ){
		for( int j = i+i; j < MAXN; j+=i ) primo[j] = false;
	
	}
	REP( i, MAXN ) if( primo[i] ) primos.pb( i );
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	crivo();
	int t, b, n;
	cin >> t;
	FOR( ct, 1, t+1 ){
		
		cin >> b >> n;
		
		vector< pair<int,int> > fact;
		int i = 0;
		while( i < SIZE(primos) && primos[i] <= b && b > 1 ){
			int tms = 0;
			while( b % primos[i] == 0 ){
				tms++;
				b = b / primos[i];
			}
			if( tms ) fact.pb( mp(primos[i], tms) );
			i++;
		}
		
		int ans = INF;
		FORIT( x, fact ){
			int nn = n;
			int cur = 0;
			while( nn ){
				cur += nn/x->first;
				nn /= x->first;
			}
			ans = MIN( ans, cur/x->second );
		}
		if( ans == INF ) ans = 0;
		
		cout << "Cenario #" << ct << ":\n" << ans << "\n\n";
		
	}
	
	return 0;
}

































