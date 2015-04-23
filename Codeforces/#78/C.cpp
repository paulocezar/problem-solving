#include <map> 
#include <set> 
#include <list>
#include <stack>
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
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct orientacao_t {

	char f, c;
	char v[4];
	
	orientacao_t() {}

	orientacao_t(char frente, char costas, char vizinhos[] ): f( frente ), c( costas )
	{	
		for( int i = 0; i < 4; i++ ) v[i] = vizinhos[i];
	}

	bool operator == ( const orientacao_t &o ) const {
		if( f == o.f && c == o.c  ){
			if( v[0] == o.v[0] && v[1] == o.v[1] && v[2] == o.v[2] && v[3] == o.v[3] ) return true;
			if( v[0] == o.v[1] && v[1] == o.v[2] && v[2] == o.v[3] && v[3] == o.v[0] ) return true;
			if( v[0] == o.v[2] && v[1] == o.v[3] && v[2] == o.v[0] && v[3] == o.v[1] ) return true;
			if( v[0] == o.v[3] && v[1] == o.v[0] && v[2] == o.v[1] && v[3] == o.v[2] ) return true;
		}
		if( f == o.c && c == o.f  ){
			if( v[2] == o.v[0] && v[1] == o.v[1] && v[0] == o.v[2] && v[3] == o.v[3] ) return true;
			if( v[2] == o.v[1] && v[1] == o.v[2] && v[0] == o.v[3] && v[3] == o.v[0] ) return true;
			if( v[2] == o.v[2] && v[1] == o.v[3] && v[0] == o.v[0] && v[3] == o.v[1] ) return true;
			if( v[2] == o.v[3] && v[1] == o.v[0] && v[0] == o.v[1] && v[3] == o.v[2] ) return true;
		}
		return false;
	}
	
	void operator = ( const orientacao_t &o ) {
		f = o.f;
		c = o.c;
		for( int i = 0; i < 4; i++ ) v[i] = o.v[i];
	}

};

struct cubo_t {

	orientacao_t orientacao[3];
	
	cubo_t(){}

	cubo_t( char a, char b, char c, char d, char e, char f ){
	
		char v[4];
		
		v[0] = e; v[1] = d; v[2] = c; v[3] = b;
		orientacao[0] = orientacao_t( a, f, v );

		v[0] = e; v[1] = a; v[2] = c; v[3] = f;
		orientacao[1] = orientacao_t( b, d, v );
		
		v[0] = d; v[1] = a; v[2] = b; v[3] = f;
		orientacao[2] = orientacao_t( e, c, v );
	}

	bool operator == ( const cubo_t &c ) const {
		for( int i = 0; i < 3; i++ )
			for( int j = 0; j < 3; j++ )
				if( orientacao[i] == c.orientacao[j] ) return true;
		return false;
	}
	
	void operator = ( const cubo_t &c ) {
		orientacao[0] = c.orientacao[0];
		orientacao[1] = c.orientacao[1];
		orientacao[2] = c.orientacao[2];
	}

};


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	string s;
	cin >> s;
	sort( ALL(s) );
	
	vector< cubo_t > cubes;
	int eq = 0;
	
	do{
		cubo_t aux = cubo_t( s[0], s[1], s[2], s[3], s[4], s[5] );
		REP( i, SIZE(cubes) ) if( aux == cubes[i] ) goto hell;
		cubes.PB( aux );
	hell: 
		eq++;
	} while( next_permutation(ALL(s)) );
	
	cout << SIZE(cubes) << "\n";
	
	return 0;
}




















