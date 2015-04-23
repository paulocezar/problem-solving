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
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 111

struct point_t{
	int x, y;
	explicit point_t( int xx = 0, int yy = 0 ) : x(xx), y(yy) {}
	bool operator < ( const point_t& p ) const {
		if( x != p.x ) return x < p.x;
		return y < p.y;
	}
};

point_t stk[MAXN];

inline double trap( point_t& a, point_t& b ){
	return (0.5*(b.x-a.x)*(b.y+a.y));
}

double area( vector<point_t>& poly ){
	double ret = 0.0;
	REP( i, SIZE(poly) )
		ret += trap( poly[i], poly[(i+1)%SIZE(poly)] );
	return fabs( ret );
}

inline int dist( point_t& p1, point_t& p2 ){
	return SQR(p1.x-p2.x) + SQR(p1.y-p2.y);
}

int sideSign( point_t& p1, point_t& p2, point_t& p3 ){
	int sg = (p1.x-p3.x)*(p2.y-p3.y)-(p1.y-p3.y)*(p2.x-p3.x);
	if( sg == 0 ) return 0;
	if( sg > 0 ) return 1;
	return -1;
}

bool better( point_t& p1, point_t& p2, point_t& p3 ){
	int sg = (p1.y-p3.y)*(p2.x-p3.x)-(p1.x-p3.x)*(p2.y-p3.y);
	if( sg == 0 ){
		if( dist(p3, p1) > dist(p3,p2) ) return true;
		return false;
	}
	if( sg < 0 ) return true;
	return false;
}

void graham( vector<point_t> vin, vector<point_t>& vout ){
	vout.clear();
	int N = SIZE(vin);
	sort( ALL( vin ) );
	int pstk, i;
	stk[0] = vin[0];
	stk[1] = vin[1];
	pstk = 2; i = 2;
	while( i < N ){
		while( pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2]) ) pstk--;
		stk[pstk++] = vin[i++];
	}
	REP( i, pstk ) vout.PB( stk[i] );
	REP( i, N ){
		vin[i].y = -vin[i].y;
		vin[i].x = -vin[i].x;
	}
	sort( ALL(vin) );
	stk[0] = vin[0];
	stk[1] = vin[1];
	pstk = 2; i = 2;
	while( i < N ){
		while( pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2]) ) pstk--;
		stk[pstk++] = vin[i++];
	}
	FOR( i, 1, pstk-2 ){
		stk[i].x = -stk[i].x;
		stk[i].y = -stk[i].y;
		vout.PB( stk[i] );
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	cout << fixed << setprecision(2);
	int N, tc = 1;
	vector< point_t > poly, invol;
	while( (cin >> N) && N ){
		poly.resize( N );
		REP( i, N ) cin >> poly[i].x >> poly[i].y;
		graham( poly, invol );
		double ai = area( invol );
		double ap = area( poly );
		cout << "Tile #" << tc++ << "\nWasted Space = " << (ai-ap)*100/ai << " %\n\n";
	}
	
	return 0;
}




















