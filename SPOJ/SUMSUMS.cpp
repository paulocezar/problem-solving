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

const long long MOD = 98765431;
const long long INV = 65843621;

long long pow( long long n ){
	long long ans = 1;
	long long pot = 2;
	while( n ){
		if( n&1 ) ans *= pot;
		ans %= MOD;
		pot *= pot;
		pot %= MOD;
		n >>= 1;
	}
	return ans;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N;
	long long T;
	cin >> N >> T;
	
	long long in[N];
	long long sum = 0;
	
	REP( i, N ){
		cin >> in[i];
		sum += in[i];
		sum %= MOD;
	}
	
	if( N == 1 ){
		if( T == 0 ) cout << in[0] << "\n";
		else cout << "0\n";
		return 0;
	} else if( N == 2 ){
		if( T&1 ){
			cout << in[1] << "\n" << in[0] << "\n";
		} else cout << in[0] << "\n" << in[1] << "\n";
		return 0;
	}
	
	long long ans[2][2], pot[2][2];
	pot[0][0] = N-2;  pot[0][1] = N-1;
	pot[1][0] = 1;    pot[1][1] = 0;
	
	ans[0][0] = 1;  ans[0][1] =   0;
	ans[1][0] = 0;    ans[1][1] = 1;
	
	long long TT = T;
	while( TT ){
		
		if( TT&1 ){
			
			long long t1 = (ans[0][0]*pot[0][0] % MOD) + (ans[0][1]*pot[1][0] % MOD );
			long long t2 = (ans[0][0]*pot[0][1] % MOD) + (ans[0][1]*pot[1][1] % MOD );
			long long t3 = (ans[1][0]*pot[0][0] % MOD) + (ans[1][1]*pot[1][0] % MOD );
			long long t4 = (ans[1][0]*pot[0][1] % MOD) + (ans[1][1]*pot[1][1] % MOD );
		
			ans[0][0] = t1 % MOD;  ans[0][1] = t2 % MOD;
			ans[1][0] = t3 % MOD;  ans[1][1] = t4 % MOD;
			
		}
		
		long long t1 = (pot[0][0]*pot[0][0] % MOD) + (pot[0][1]*pot[1][0] % MOD );
		long long t2 = (pot[0][0]*pot[0][1] % MOD) + (pot[0][1]*pot[1][1] % MOD );
		long long t3 = (pot[1][0]*pot[0][0] % MOD) + (pot[1][1]*pot[1][0] % MOD );
		long long t4 = (pot[1][0]*pot[0][1] % MOD) + (pot[1][1]*pot[1][1] % MOD );
	
		pot[0][0] = t1 % MOD;  pot[0][1] = t2 % MOD;
		pot[1][0] = t3 % MOD;  pot[1][1] = t4 % MOD;
		
		TT >>= 1;
	}
	
	sum *= ans[1][0];
	sum %= MOD;
	
	if( T&1 ){
		REP( i, N ) cout << (sum - in[i]+MOD)%MOD << "\n";
	} else{
		REP( i, N ) cout << (sum + in[i]) % MOD << "\n";
	}
	
	return 0;
}
