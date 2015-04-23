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

#define pb push_back
#define mp make_pair

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

int val[256];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	bool first = true;
	string line = "\n";
	while( line == "\n" ) getline(cin,line);
	
	while( true ){
		
		if( first ) first = false;
		else cout << "\n";
		
		int dig = 0;
		
		REP( i, SIZE(line) ) if( line[i] > 0x20 ){
			val[line[i]] = dig++;
		}
		
		getline( cin, line );
		
		while( line[0] && line != "\n" ){
			
			vector<int> digs;
			REP( i, SIZE(line) ) if( line[i] > 0x20 )
				digs.pb( val[line[i]] );
			
			int ans = 0;
			FOR( base, 2, dig+1 ){
				int cur = 0; int pot = 1;
				RREP( i, SIZE(digs) ) if( digs[i] >= base ){ cur = 0; break; }
				else{ cur += pot*digs[i]; pot *= base;  }
				ans += cur;
			}
			cout << ans << "\n";
			
			if( !getline(cin, line) ) return 0;
		}
		
		
		while( !line[0] || line == "\n" ){
			if( !getline(cin,line) ) return 0;
		}
	}
	
	return 0;
}




















