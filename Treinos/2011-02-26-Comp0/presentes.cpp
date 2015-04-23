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
int ct[2], parent[MAXN], mark[MAXN];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t, a, b, n;
	cin >> t;
	FOR( tt, 1, t+1 ){
		
		cin >> a >> b;
		cin >> n; FILL( mark, -1 );
		parent[0] = 0; mark[0] = 0; ct[0] = 1; ct[1] = 0;
		
		FOR( i, 1, n ) cin >> parent[i];
		
		int marked = 1;
		while( marked != n ){
			REP( i, n ) if( mark[i] == -1 && mark[parent[i]] != -1 ){
				mark[i] = 1-mark[parent[i]];
				ct[mark[i]]++;
				marked++;
			}	
		}
		
		cout << "Cenario #" << tt << ":\n" << MAX(a,b)*MIN(ct[0], ct[1]) + MIN(a,b)*MAX(ct[0],ct[1]) << "\n\n";
		
	}
	
	return 0;
}


































