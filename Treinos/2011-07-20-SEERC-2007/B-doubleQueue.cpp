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

#define PB push_back
#define MP make_pair

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

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	map< int, queue<int> > q;
	int op, K, P;
	cin >> op;
	while( op ){
		
		switch( op ){
			case 1: cin >> K >> P; q[ P ].push( K ); break;
			case 2: if( q.empty() ) cout << "0\n";
					else { 
						cout << ( (q.rbegin()->second).front() ) << "\n";
						(q.rbegin()->second).pop();
						if( (q.rbegin()->second).empty() ) q.erase( q.rbegin()->first );
					} break; 
			case 3: if( q.empty() ) cout << "0\n";
					else { 
						cout << ( (q.begin()->second).front() ) << "\n";
						(q.begin()->second).pop();
						if( (q.begin()->second).empty() ) q.erase( q.begin()->first );
					} break; 
		}
		
		cin >> op;
	}
	
	return 0;
}




















