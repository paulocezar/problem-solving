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

const double EPS = 1e-15;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	int ax, ay, bx, by;
	double p, q, r;
	
	cin >> t;
	while( t-- ){
		
		cin >> ax >> ay >> bx >> by >> p >> q >> r;
		
		double aax[2], aay[2];
		double bbx[2], bby[2];
		
		aax[0] = ax; 			aay[0] = (r - ax*p)/q;
		aax[1] = (r - ay*q)/p;	aay[1] = ay;
		
		bbx[0] = bx;			bby[0] = (r - bx*p)/q;
		bbx[1] = (r - by*q)/p;	bby[1] = by;
		
		double da0 = fabs(ay - (r - ax*p)/q );
		double da1 = fabs(ax - (r - ay*q)/p );
		double db0 = fabs(by - (r - bx*p)/q );
		double db1 = fabs(bx - (r - by*q)/p );
		//a --> aa[0] --> bb[0] --> b
		//a --> aa[0] --> bb[1] --> b 
		//a --> aa[1] --> bb[0] --> b
		//a --> aa[1] --> bb[1] --> b
		
		double ans = abs(ax-bx) + abs(ay-by);
		if( fabs(p) > EPS && fabs(q) > EPS ){
			ans = min( ans, da0 + db0 + sqrt( (aax[0]-bbx[0])*(aax[0]-bbx[0]) + (aay[0]-bby[0])*(aay[0]-bby[0]) ) );
			ans = min( ans, da0 + db1 + sqrt( (aax[0]-bbx[1])*(aax[0]-bbx[1]) + (aay[0]-bby[1])*(aay[0]-bby[1]) ) );
			ans = min( ans, da1 + db0 + sqrt( (aax[1]-bbx[0])*(aax[1]-bbx[0]) + (aay[1]-bby[0])*(aay[1]-bby[0]) ) );
			ans = min( ans, da1 + db1 + sqrt( (aax[1]-bbx[1])*(aax[1]-bbx[1]) + (aay[1]-bby[1])*(aay[1]-bby[1]) ) );
		}	
		cout << fixed << setprecision(12) << ans << "\n";
	}
	
	return 0;
}




















