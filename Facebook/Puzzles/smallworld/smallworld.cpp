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
#include <fstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define TI(x) x::iterator
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

struct point{
	int id;
	double x, y;
	point(){};
	point( int ii, double xx, double yy ) : id(ii), x(xx), y(yy) {};
	bool operator < ( const point& a ) const {
		return x < a.x;
	}
	double dist( const point& a ){ return SQR(x-a.x) + SQR(y-a.y);  }
};

class ycomp {
	bool operator()( point a, point b ){
		return a.y < b.y;
	}
} compy;

struct kdt {
	point median;
	kdt *left, *right;
	kdt(){ left = NULL; right = NULL; }
	kdt( TI( vector< point > ) beg, TI( vector< point > ) end, char ax ){
		
		left = right = NULL;
		switch( ax ){
			case 0 : sort( beg, end ); break;
			case 1 : sort( beg, end, compy ); break;
			default: break;
		}
		
		int mid = (end-beg)/2;
		median = *(beg+mid);
		if( beg+(mid-1) > beg ) left = &kdt( beg, beg+(mid-1) !ax );
		if( beg+(mid+1) < end ) right = &kdt( beg+(mid+1), end, !ax );
	
	}	
};

int main( int argc, char* argv[] ){

	ifstream in( argv[1] );
	int id;
	double x, y;
	vector< point > points;
	
	while( in >> id >> x >> y ){
		points.pb( point(id, x, y) );
	}
	
	kdt tree( points.begin(), points.end(), 0 );

	return 0;
}
