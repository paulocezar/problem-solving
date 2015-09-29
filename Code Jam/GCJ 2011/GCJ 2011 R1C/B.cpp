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

#define MAXC 1010
int64 a[MAXC];

bool comp( const int& aa, const int& bb ){
	return a[aa] > a[bb];
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T;
	cin >> T;
	FOR( tc, 1, T+1 ){
		
		int64 L, t, N, C;
		cin >> L >> t >> N >> C;
		int id[C];
		
		REP( i, C ){
			cin >> a[i];
			id[i] = i;
		}
		sort( id, id+C, comp );
		int64 ans = 0;
		
		if( L == 0LL ){
		
			ans = 0;
			REP( i, N ) ans += a[i%C];
			ans = 2*ans;
			
		} else{
			
			int64 acum = 0;
			int64 ganho = 0;
			
			REP( i, N ) if( 2*acum + 2*a[i%C] >= t ){
				ans += a[i%C];
				int64 curganho = 0;
				if( 2*acum >= t ) curganho = a[i%C];
				else curganho = ( 2*a[i%C] - ( t - 2*acum ) )/2;
				
				int64 LL = L-1;
				int ps = 0;
				while( LL > 0 && ps < C ){
					
					int64 amt = min( LL, (N+1/a[id[ps]]) - (i/a[id[ps]]) );
					curganho += amt*a[ id[ps] ];
					ps++;
					LL -= amt;
					
				}
				ganho = max( ganho, curganho );
				acum += a[i%C];
				
			} else { ans += a[i%C]; acum += a[i%C]; }
			ans = 2*ans - ganho;
	

		}
		cout << "Case #" << tc << ": " << ans << "\n";
		
	}
	
	return 0;
}


































