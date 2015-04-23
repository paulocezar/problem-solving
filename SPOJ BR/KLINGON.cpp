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

#define MAXN 10001
#define MAXV 1001

int lo[MAXN], sz[MAXN];
int check[MAXV];
char seen[MAXV];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N, pt;
	
	cin >> N;
	while( N ){
		
		FILL( seen, 0 );
		pt = 0;
		
		vector< vector< int > > nota( N );
		
		REP( i, N ){
			cin >> sz[i];
			nota[i] = vector< int > ( sz[i] );
			lo[i] = 0;
			REP( j, sz[i] ){
				cin >> nota[i][j];
				if( !seen[nota[i][j]] ){
					seen[nota[i][j]] = 1;
					check[pt++] = nota[i][j];
				}
			}
			sort( nota[i].begin(), nota[i].end() );
		}
		sort( check, check+pt );
		
		int ans = INF;
		REP( x, pt ){
			int cur = 0;
			REP( i, N ){
				for(  ;lo[i] < sz[i]; lo[i]++ ) if( nota[i][lo[i]] > check[x] ) break;
				cur += ABS( sz[i] - 2*lo[i] );
			}
			if( cur < ans ) ans = cur;
		}
		cout << ans << "\n";
		
		cin >> N;
	}
	
	return 0;
}
