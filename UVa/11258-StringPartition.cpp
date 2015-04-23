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
#include <climits> 
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

#define MAXN 201

string S; int N;

int64 dp[MAXN];

int64 solve( int pos ){
	if( pos == N ) return 0;
	int64& r = dp[pos];
	if( r == -1 ){
		r = 0;
		if( S[pos] == 0 ){
			r = MAX( r, solve(pos+1) );
			if( pos+1 < N && S[pos+1] != 0 ){
				pos++; goto hell;
			}
		} else {
			hell:
			int64 cur = 0;
			while( pos < N && ((10LL*cur)+(S[pos]-'0')) < INT_MAX ){
				cur = ((10LL*cur)+(S[pos]-'0'));
				r = MAX( r, cur + solve( pos+1) );
				pos++;
			}	
		}
	}
	return r;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		cin >> S;
		N = SIZE( S ); REP( i, N ) dp[i] = -1;
		cout << solve( 0 ) << "\n";
	}
	
	return 0;
}


































