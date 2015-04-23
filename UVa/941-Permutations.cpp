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

int ok;

#define ACTV(x) (ok & (1<<x))
#define TURN(x) (ok ^= (1<<x))
	
int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );

	string S;
	int64 fat[21];
	
	fat[0] = 1;
	FOR( i, 1, 21 ) fat[i] = fat[i-1]*int64(i);
	
	int T;
	cin >> T;
	while( T-- ){
		
		int64 K;
		int sz;
		
		cin >> S;
		cin >> K;
		sz = SIZE(S);
		
		sort( S.begin(), S.end() );
		ok = ( 1<<sz ) - 1;	
		
		string ans = S;
		int cur = 0;
		K++;
		
		while( cur < sz ){
			REP( i, sz ) if( ACTV(i) ){
				if( K <= fat[sz-cur-1] ){
					TURN(i);
					ans[cur] = S[i];
					break;
				} else K -= fat[sz-cur-1];
			}
			cur++;
		}
		cout << ans << "\n";
		
	} 
	
	return 0;
}
