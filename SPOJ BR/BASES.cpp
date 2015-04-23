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
#include <iomanip>
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;
#define MXN 20

int B;

struct poly_t{
	int a[MXN]; int n;
	poly_t() : n(0) { FILL(a, 0); }
	poly_t( string s ){
		n = SIZE(s); FILL(a,0);
		RREP( i, n ) a[n-i-1] = s[i]-'0';

	}
	poly_t& operator +=( const poly_t& x ){
		n = MAX( n, x.n );
		REP( i, n ) a[i] += x.a[i];
		return *this;
	}
	poly_t operator +( const poly_t& x ){ return poly_t(*this) += x; }
	void fix(){
		while( a[0] == 0 && n ){
			REP( i, n-1 ) a[i] = a[i+1];
			n--;
		}
		FOR( i, n, MXN-1 ) a[i] = 0;
	}
	
	poly_t& operator -=( const poly_t& x ){
		n = MAX( n, x.n );
		REP( i, n ) a[i] -= x.a[i];
		return *this;
	}
	poly_t operator -( const poly_t& x ){ return poly_t(*this) -= x; }
	
	poly_t operator *( const poly_t& x ) const {
		poly_t r;
		REP( i, n ) REP( j, x.n )
			if( a[i]*x.a[j] ){ 
				r.n = MAX( r.n, i+j+1 );
				r.a[i+j] += a[i]*x.a[j];
			}
		return r;
	}
	poly_t& operator *=(const poly_t& x) { return *this = *this * x; }
	operator string() const{
		ostringstream s;
		if( n == 0 ) s << " NULL ";
		else{ 
			int i = n-1;
			while( !a[i] ) i--;
			s << a[i] << "*X^" << i;
			while( --i >= 0 ){ 
				if( a[i] ) s << " + " << a[i] << "*X^" << i;
			}
		}
		return s.str();
	}
	friend ostream& operator <<( ostream& o, const poly_t& x ){
		return o << (string) x;
	}
	bool P( int r, int y ){
	
		if( n == 0 ) return false;
		if( a[0] == 0 ){
			if( y % r  ) return false;
			poly_t aux;
			aux.n = n-1;
			REP( i, n-1 ) aux.a[i] = a[i+1];
			return aux.P( r, y/r );
		}
		if( n == 1 ) return y == a[0];
		if( ABS(y-a[0]) % r ) return false;
		poly_t aux;
		aux.n = n-1;
		REP( i, n-1 ) aux.a[i] = a[i+1];
		return aux.P( r, (y-a[0])/r );
	}
	bool showRoots(){
		if( n == 0 ) return false;
		
		int gr = 0;
		while( !a[gr] ) gr++;
		
		int sq = int( ceil( sqrt( ABS(a[gr]) ) ) );
		bool find = false;
		
		vector< int > div;
		FOR( i, 1, sq ) if( ABS(a[gr]) % i == 0 ){
			if( i >= B ) div.PB( i );
			if( (ABS(a[gr]) / i) > i && (ABS(a[gr]) / i) >= B ) div.PB( ABS(a[gr]) / i );
		}
		sort( ALL(div) );

		REP( i, SIZE(div) ){
			if( (i+1 < SIZE(div) && div[i+1] == div[i]) || !P( div[i], 0 ) ) continue;
			if( find ) cout << " "; find = true;
			cout << div[i];
		}
		
		if( !find ) cout << "*";
		return true;
	}
};

string line;
poly_t parse( int beg, int end ){
	string cur = "";
	while( beg < end && line[beg] != '*' && line[beg] != '+' ) cur += line[beg++];
	if( beg == end ) return poly_t( cur );
	if( line[beg] == '+' ) return poly_t(cur) + parse( beg+1, end );
	poly_t p( cur ); beg++;
hell:
	cur = "";
	while( beg < end && line[beg] != '*' && line[beg] != '+' ) cur += line[beg++];
	if( beg == end ) return p * poly_t( cur );
	if( line[beg] == '+' ) return ( p * poly_t(cur) ) + parse( beg+1, end );
	p *= poly_t( cur ); beg++;
	goto hell;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( cin >> line && line != "=" ){
		
		poly_t poly, poly2;		
		
		int sz = SIZE(line);
		B = 2; REP( i, sz ) if( '0' <= line[i] && line[i] <= '9' ) B = MAX( B, line[i]-'0'+1 );
		int eq = 0; while( line[eq] != '=' ) eq++;
		
		poly = parse( 0,  eq );
		poly2 = parse( eq+1, sz );
		poly -= poly2; poly.fix();
		
		if( !poly.showRoots() ) cout << B << "+\n";
		else cout << "\n";
	}
	
	return 0;
}




















