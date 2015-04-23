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



int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int64 N, c1, n1, c2, n2, m1, m2;
	
	while( cin >> N && N ){
		cin >> c1 >> n1;
		cin >> c2 >> n2;
		
		int64 x = 1, y = 0;
		int64 nx = 0, ny = 1, q;

		int64 a, d = n1, b = n2;
		
		while(b){
			q = d/b;
			x -= q*nx; swap(x, nx);
			y -= q*ny; swap(y, ny);
			d -= q*b; swap(d, b);
		}
		
		if( N % d ) cout << "failed\n";
		else {
			x *= (N/d);
			y *= (N/d);
			
			a = n1/d;
			b = n2/d;
			
			int64 lo = (int64)ceil( double(-x)/b );
			int64 hi = (int64)floor( double(y)/a );

			if( lo > hi ) cout << "failed\n";
			else {
			
				if( (c1*( x + lo*b ) + c2*( y - lo*a )) <= (c1*( x + hi*b ) + c2*( y - hi*a ) ) )
					m1 = x + lo*b, m2 = y - lo*a;
				else
					m1 = x + hi*b, m2 = y - hi*a;
				
				cout << m1 << " " << m2 << "\n";
			}
		}
	}
		
	return 0;
}

























