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

#define MAXN 100001
#define MAXM 101

struct bigInt{
	string dig;
	bigInt(){ dig = "0"; }
	bigInt( string digs ) : dig(digs) { }
	
	bigInt operator + ( const bigInt& a ){
		
		string s = "";
		int car = 0;
		int i = SIZE(dig) - 1;
		int j = SIZE(a.dig) - 1;
		RREP( x, MAX(SIZE(dig), SIZE(a.dig)) ){
			
			char cr = 0;
			if( i >= 0 ) cr = dig[i]-'0';
			if( j >= 0 ) cr += a.dig[j]-'0';
			cr += car;
			if( cr >= 10 ) { cr -= 10; car = 1; }
			else car = 0;
			cr += '0';
			
			s = cr + s;
			i--, j--;
			
		}
		
		if( car ) s = "1" + s;
		return bigInt( s ); 
	}
};

bigInt dp[2][MAXM];

/*int64 solve( int i, int j ){
	
	if( j == 0 ) return 1;
	if( i == 0 ) return 0;

	int64 &r = dp[i][j];
	if( r != -1 ) return r;
	
	r = solve( i-1, j );
	if( x[i-1] == z[j-1] ) r += solve( i-1, j-1 );
	
	return r;
}*/

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int ct;
	cin >> ct;
	while( ct-- ){
		
		string x, z;
		cin >> x >> z;
		
		int old = 0;
		int cur = 1;
		
		REP( j, SIZE(z)+1 ) dp[old][j] = bigInt( "0" );;
		dp[old][0] = bigInt( "1" );
		dp[cur][0] = bigInt( "1" );
		
		REP( i, SIZE(x) ){
			REP( j, SIZE(z) ){
				dp[cur][j+1] = dp[old][j+1];
				if( x[i] == z[j] ) dp[cur][j+1] = dp[cur][j+1] + dp[old][j];
			}
			old = !old;
			cur = !cur;
		}
				
		cout << dp[old][SIZE(z)].dig << "\n";
					
	}
	
	return 0;
}
