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

#define MAXN 101
#define MAXV 64001
#define OFFST 32000

#define NOT 0
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

char dp[MAXN][MAXV];
int N, OBJ, a[MAXN];

int solve( int pos, int val ){
	if( pos == N ) return val == OBJ;
	char& r = dp[pos][val+OFFST];
	if( r == -1 ){
		int nval = val+a[pos];
		if( -32000 <= nval && nval <= 32000 && solve( pos+1, nval ) ) return r = ADD; 
		nval = val-a[pos];
		if( -32000 <= nval && nval <= 32000 && solve( pos+1, nval ) ) return r = SUB;
		nval = val*a[pos];
		if( -32000 <= nval && nval <= 32000 && solve( pos+1, nval ) ) return r = MUL;
		nval = val/a[pos];
		if( a[pos]*(val/a[pos]) == val && -32000 <= nval && nval <= 32000 && solve( pos+1, nval ) ) return r = DIV;
		r = NOT;
	}
	return r;
}

void printans( int pos, int val ){
	if( pos == N ){ cout << "=" << val << "\n"; return; }
	switch( dp[pos][val+OFFST] ){
		case ADD: cout << "+" << a[pos]; printans( pos+1, val+a[pos] ); break;
		case SUB: cout << "-" << a[pos]; printans( pos+1, val-a[pos] ); break;
		case MUL: cout << "*" << a[pos]; printans( pos+1, val*a[pos] ); break;
		case DIV: cout << "/" << a[pos]; printans( pos+1, val/a[pos] ); break;
	}
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		cin >> N;
		REP( i, N ){ cin >> a[i]; FILL( dp[i], -1 ); }
		cin >> OBJ;
		if( solve( 1, a[0] ) ){ cout << a[0]; printans( 1, a[0] ); }
		else cout << "NO EXPRESSION\n";
	}
	
	return 0;
}


































