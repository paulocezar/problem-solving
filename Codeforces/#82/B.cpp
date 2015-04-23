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

struct laptop_t{
	int speed, ram, hdd, cost, id;
	laptop_t( int ss = 0, int rr = 0, int hh = 0, int cc = 0, int ii = 0) : speed(ss), ram(rr), hdd(hh), cost(cc), id(ii) {}
	bool operator < ( const laptop_t& l ) const {
		return cost < l.cost;
	}
	bool outdated( laptop_t l ){
		return ((speed < l.speed) && (ram < l.ram) && (hdd < l.hdd));
	}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, a, b, c, d;
	cin >> N;
	vector< laptop_t > laptop( N );
	FOR( i, 1, N ){
		cin >> a >> b >> c >> d;
		laptop[i-1] = laptop_t( a, b, c, d, i );
	}
	sort( ALL(laptop) );
	REP( i, N ){
		bool out = false;
		REP( j, N ) if( i != j ){
			if( laptop[i].outdated(laptop[j]) ){ out = true; break; }
		}
		if( !out ){ cout << laptop[i].id << "\n"; break; }
	}

	return 0;
}




















