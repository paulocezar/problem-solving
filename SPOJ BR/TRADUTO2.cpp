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

const int64 MOD = 1000000007;
char NN[111];
char wrd[111000];
int N, M;

vector<int64> dp;

bool valid( char* s ){
	REP( i, N )
		if( s[i] > NN[i] ) return false;
		else if( s[i] < NN[i] ) return true;
	return true;
}

int64 solve( int pos ){	
	
	if( dp[pos] != -1 ) return dp[pos];
	
	int64& r = dp[pos];
	r = 0LL;
	if( wrd[pos] == '0' ) return r;
	
	char cur[N+1];
	int curp = pos;
	cur[0] = wrd[curp++];
	
	while( curp-pos < N ){
		r += solve( curp );
		if( r >= MOD ) r -= MOD;
		
		if( curp == M ) break;
		cur[curp-pos] = wrd[curp]; curp++;
	}
	
	if( curp-pos == N && valid(cur) ){ 
		r += solve(curp);
		if( r > MOD ) r -= MOD;
	}
	
	return r;
}

int main( int argc, char* argv[] ){

	scanf("%s %s", NN, wrd );
	
	N = strlen(NN);
	M = strlen(wrd);
	dp = vector<int64>( M+1, -1 );
	dp[M] = 1LL;
	
	printf("%lld\n", solve( 0 ) );
	
	return 0;
}
