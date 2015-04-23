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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

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

#define MAXN 100
int v[MAXN];
char reach[5001];
int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n, x, xp;
	double perc;
	cin >> n >> x;
	while( n+x ){
		
		int j = 0;
		REP( i, n ){
			cin >> perc;
			if( i == x-1 ) xp = int(1000.0*perc)/10;
			else v[j++] = int(1000.0*perc)/10;
		}
		
		if( xp > 5000 ) cout << "100.00\n";
		else {
			FILL( reach, 0 ); reach[0] = 1;

			REP( i, n-1 ){
				RFOR( k, 5000, v[i] ) if( reach[k-v[i]] ) reach[k] = 1;
			}	
			j = 4999;
			while( !reach[j] ) j--;
			
			perc = double(xp) / double(10000-j);
			perc *= 100.0;
			cout << fixed << setprecision(2) << perc << "\n";
		
		}
		
		cin >> n >> x;
	}
	
	return 0;
}




















