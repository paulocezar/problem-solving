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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int W, H, sz, cols;
string text;

char pd[1111][1111];

char ok( int pos, int has ){
	if( pos == sz ) return 1;
	if( has == 0 ) return 0;
	char &ret = pd[pos][has];
	if( ret == -1 ){
		ret = 0;
		int can = cols;
		while( (pos < sz) && can && !ret ){
			if( (pos+1 == sz) || text[pos] == ' ' )
				ret = ok( pos+1, has-1 ); 
			pos++;
			can--;
		}
		if( pos < sz && !ret && text[pos] == ' ' ) ret = ok( pos+1, has-1 );
	}
	return ret;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	FOR( tc, 1, t ){
		
		cin >> W >> H; cin.ignore();
		getline( cin, text );
		sz = SIZE(text);
		
		int ans = H;
		while( ans > 0 ){
			int lines = H/ans;
			cols = W/ans;
			REP( i, sz ) REP( j, lines+1 ) pd[i][j] = -1;			
			if( ok( 0, lines ) ) break;
			ans--;
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	
	
	return 0;
}




















