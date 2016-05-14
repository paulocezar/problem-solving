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

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 2012
double D, t[MAXN], x[MAXN], a;
int N;
	
double solve(){
	if( N == 1 || x[0] >= D ) return sqrt( 2.0 * D / a );
	if( x[1] >= D ) return max( (D-x[0])*(t[1]-t[0])/(x[1]-x[0]), sqrt( 2.0 * D / a ) );
	
	double im_at = x[0];
	double time_passed = sqrt( 2.0 * x[0] / a );
	double my_vel = a * time_passed; 
	
	FOR( i, 1, N-1 ){
		
		if( t[i] >= time_passed ){
			
			double ds = (x[i]-x[i-1]);
			double dt = (t[i]-t[i-1]);
			double other_vel = ds/dt;

			x[i-1] + other_vel  

			double mydt = t[i]-time_passed;
			double max_vel = a * mydt;
			double can_reach = im_at + my_vel * mydt + .5*a*mydt*mydt;
			if( can_reach >= )

		}
		
	}
	return time_passed;
}
	
int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int tst;
	cout << fixed << setprecision(7);
	cin >> tst;
	FOR( tc, 1, tst ){
		cout << "Case #" << tc << ":\n";
		int A;
		cin >> D >> N >> A;
		REP( i, N ) cin >> t[i] >> x[i];
		REP( i, A ){
			cin >> a;
			cout << solve() << endl;
		}
	}
	
	
	return 0;
}

























