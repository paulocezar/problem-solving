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
#include <bitset>
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

const double EPS = 1e-6;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct lemm_t{
	int m, v, id;
	lemm_t(int mm = 0, int vv = 0, int ii = 0 ) : m(mm), v(vv), id(ii) {}
	bool operator < (const lemm_t &l ) const {
		if( m != l.m ) return m < l.m;
		return v < l.v;
	}
};

lemm_t lemming[100000];

int n, k, h;

bool candoit( double t, bool print=false){
	
	int pos = k;
	int lem = n;
	
	vector< int > ans;
	
	while( lem && pos ){
		double hh = double(pos)*h;
		double nd = hh/double(lemming[lem-1].v);
		
		if( t-nd >= EPS ){
			if( print ) ans.PB( lemming[lem-1].id );
			lem--;
			pos--;
		} else {
			lem--;
		}
	}
	
	if( !lem && pos ) return false;
	
	if( print ){
		RREP( i, k ){
			cout << ans[i];
			if( i != 0 ) cout << " ";
		}
		cout << "\n";
	}
	
	return true;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	cin >> n >> k >> h;
	
	REP( i, n ){ cin >> lemming[i].m; lemming[i].id = i+1; }
	REP( i, n ) cin >> lemming[i].v;
	
	sort( lemming, lemming+n );
	
	double lo = 0, hi = 1e9;
	
	REP( i, 500 ){
		double mid = (lo+hi)/2.0;
		
		if( candoit(mid) ) hi = mid;
		else lo = mid;
	}
	
	candoit( hi, true );
	
	return 0;
}

























