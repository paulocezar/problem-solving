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

const double EPS = 1e-9;
inline int sgn(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(double a, double b) { return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct frac{
	int num, den;
	frac( int n = 0, int d = 0 ) : num(n), den(d){ int g = __gcd( num, den ); num /= g; den /= g; }
	double spread( frac& a ){
		return double(a.num*den)/double(a.den*num);
	}
	bool operator <( const frac& a ) const {
		return num*a.den < a.num*den;
	}
	bool operator ==( const frac& a ) const {
		return (num == a.num) && (den == a.den);
	}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int f, r, x;
	cin >> f;
	while( f ){
		cin >> r;
		int x;
		vector< int > fr;
		REP( i, f ){ cin >> x; fr.pb( x ); }
		
		vector< frac > rt;
		REP( i, r ){ 
			cin >> x;
			REP( j, f ) rt.pb( frac( x, fr[j] ) );
		}
		sort( rt.begin(), rt.end() );
		
		double mx = 0;
		REP( i, SIZE(rt)-1 ) if( !(rt[i] == rt[i+1]) )mx = MAX( mx, rt[i].spread( rt[i+1] ) );
		cout << fixed << setprecision(2) << mx << "\n";
		
		cin >> f;
	}
	
	return 0;
}




















