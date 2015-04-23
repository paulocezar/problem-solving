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

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int n, m, c;
	int tc = 1;
	
	cin >> n >> m >> c;
	while( n+m+c ){
		
		bool up[n];
		int cons[n];
		REP( i, n ){ cin >> cons[i]; up[i] = 0; }
		
		int cur = 0; int mxm = 0;
		bool blow = false;
 		int equip;
		while( m-- ){
			cin >> equip; equip--;
			if( !up[equip] ) cur += cons[equip];
			else cur -= cons[equip];
			up[equip] = !up[equip];
			if( cur <= c ) mxm = MAX( mxm, cur );
			else blow = true;
		}
		cout << "Sequence " << tc++ << "\n";
		if( blow ) cout << "Fuse was blown.\n\n";
		else cout << "Fuse was not blown.\nMaximal power consumption was " << mxm << " amperes.\n\n";
		
		cin >> n >> m >> c;
	}
	
	return 0;
}
