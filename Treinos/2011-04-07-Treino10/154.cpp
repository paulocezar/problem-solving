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

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int mp[256];
	mp['r'] = 0;
	mp['o'] = 1;
	mp['y'] = 2;
	mp['g'] = 3;
	mp['b'] = 4;
	
	string linha;
	cin >> linha;
	while( linha[0] != '#' ){
		
		vector< string > att;
		
		while( linha[0] != 'e' ){
			
			string ths = "xxxxx";
			REP( j, 5 ) ths[ mp[linha[4*j]] ] = linha[4*j+2];
			att.pb( ths );
			
			cin >> linha;
		}
	
		int mn = INF;
		int ans = -1;
		
		REP( i, SIZE(att) ){
			
			int cur = 0;
			REP( j, SIZE(att) ){
				REP( x, 5 ) cur += (att[j][x] != att[i][x]);
			}
			
			if( cur < mn ){
				mn = cur;
				ans = i;
			}
		}
		
		cout << ans+1 << "\n";
		cin >> linha;
	}
	
	return 0;
}
