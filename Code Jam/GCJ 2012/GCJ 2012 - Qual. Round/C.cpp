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
	
	int t;
	cin >> t;
	FOR( tc, 1, t ){
		int A, B;
		cin >> A >> B;
		
		set< pair<int,int> > recycled;
		
		int ax = A;
		int ndigs = 0;
		int pot = 1;
		
		while( ax ){
			ndigs++;
			ax /= 10;
			pot *= 10;
		}
		pot /= 100;
		
		FOR( n, A, B ){
			
			
			int cpot = pot;
			int ds = 10;
			REP( i, ndigs-1 ){
				
				int front = n/(10*cpot);
				int back = n%(10*cpot);
				
				int m = back*ds + front;	
				if( m > n && m <= B ) recycled.insert( MP(n,m) );
				
				cpot /= 10;
				ds *= 10;
			}
											
		}
		
		cout << "Case #" << tc << ": " << SIZE(recycled) << "\n";
		
	}
	
	
	return 0;
}

























