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

int64 MOD;

int64 mypow( int64 a, int64 p ){
	if( p == 0 ) return 1;
	int64 ans = mypow( a, p/2 );
	ans *= ans;
	ans %= MOD;
	if( p&1 ) return (ans*a)%MOD;
	return ans;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );

	int t;
	int64 L, N, M, A1, A2, A3, A4, A5, B1, B2, B3, B4, B5, nxt, inv;

	cin >> t;
	while( t-- ){
		cin >> MOD >> L;
		
		int64 ct[MOD];
		memset( ct, 0, sizeof( ct ) );
		
		cin >> N >> A1 >> A2 >> A3 >> A4 >> A5;
		cin >> M >> B1 >> B2 >> B3 >> B4 >> B5;
		
		int64 ans = 0;
		
		ct[ A1 ]++;
		ct[ A2 ]++;		
		for( int i = 3; i <= N; i++ ){
			nxt = ( ( ( ( A1 * A3 ) % MOD ) + ( (A2 * A4) % MOD ) ) % MOD ) + A5;
			nxt %= MOD;
			ct[ ( mypow( nxt, MOD-2)*L ) % MOD ]++;
			A1 = A2;
			A2 = nxt;
		}
		
		
		for( int j = B1+1; j < MOD; j++ ) ans += ct[j];
		for( int j = B2+1; j < MOD; j++ ) ans += ct[j];
		ans += 2*ct[0];
		
		
		for( int i = 3; i <= M; i++ ){
			nxt = ( ( ( ( B1 * B3 ) % MOD ) + ( (B2 * B4) % MOD ) ) % MOD ) + B5;
			nxt %= MOD;

			for( int j = nxt+1; j < MOD; j++ ) ans += ct[j];
			ans += ct[0];

			B1 = B2;
			B2 = nxt;
		}
		
		
		cout << ans << endl; 
		
	}
	
	return 0;
}
