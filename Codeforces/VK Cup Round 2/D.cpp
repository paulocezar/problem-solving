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

int64 fstp(int64 a, int b){
	int64 res = 1;
	while( b ){
		if( b&1 ) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	while( t-- ){
		
		int k;
		cin >> k;
		vector< pair<int,int> > a, b, c;
		REP( i, k ){
			int x, y;
			cin >> x >> y;	
			a.PB( MP(x, y/2 ) );
			b.PB( MP(x, y/2 ) );
			c.PB( MP(x, 0 ) );
			if( y%2 == 1 ){
				if( i%3 == 0 ) c.back().second++;
				else if( i%3 == 1 ) b.back().second++;
				else a.back().second++;
			}
			//else if( y%3 == 2 ) a.back().second++, b.back().second++;
		}
		
		int64 aa = 1, bb = 1, cc = 1;
		
		REP( i, SIZE(a) ){
			aa *= fstp(a[i].first,a[i].second);
		}
		REP( i, SIZE(a) ){
			bb *= fstp(b[i].first,b[i].second);
		}
		REP( i, SIZE(a) ){
			cc *= fstp(c[i].first,c[i].second);
		}
		
		cout << 2LL*(aa*bb+bb*cc+cc*aa) << " " << aa << " " << bb << " " << cc << "\n";
		
	}
		
	return 0;
}

























