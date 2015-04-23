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

#define MAXP 15
#define MAXN 100
int code[MAXN];

int popc( int a ){
	int pp = 0;
	while( a ){ pp++; a -= (a & -a); }
	return pp;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, P, N, bit;
	
	cin >> t;
	while( t-- ){
	
		cin >> P >> N;
		REP( i, N ){
			code[i] = 0;
			REP( j, P ){
				cin >> bit;
				if( bit ) code[i] |= (1<<j);
			}
		}
		
		int cur, ans = P;
		int mask = (1<<P) - 1;
		while( mask ){
			cur = popc(mask);
			if( cur < ans ){
				set< int > ncode;
				REP( i, N ) ncode.insert( code[i] & mask );
				
				if( SIZE(ncode) == N ) ans = cur;
			}
			mask--;
		}
		cout << ans << "\n";
		
	}
	
	return 0;
}




















