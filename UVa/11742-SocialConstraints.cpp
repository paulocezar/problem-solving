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

#define MAXN 8
#define MAXM 20

int r[MAXM][3];
int a[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n, m;
	cin >> n >> m;
	while( n+m ){
		
		REP( i, m ) cin >> r[i][0] >> r[i][1] >> r[i][2];
		REP( i, n ) a[i] = i;
		
		int ans = 0;
		do{
		
			bool ok = true;
			
			REP( i, m ){
			
				int x = 0, y = 0;
				while( a[x] != r[i][0] ) x++;
				while( a[y] != r[i][1] ) y++;
				
				if( r[i][2] < 0 ){ if( ABS(x-y) < -r[i][2] ) ok = false; }
				else if( ABS(x-y) > r[i][2] ) ok = false;
				
				if( !ok ) break;
			}
			
			if( ok ) ans++;
			
		} while( next_permutation(a, a+n) );
		cout << ans << "\n";
		
		cin >> n >> m;
	}
	
	return 0;
}




















