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
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1011
int N, x[MAXN], y[MAXN], key[MAXN], inq[MAXN];

int getmin(){
	int mn = N; key[N] = INF;
	REP( i, N ) if( inq[i] && key[i] < key[mn] ) mn = i;
	return mn;  
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t, R, tc = 1;
	cin >> t;
	while( t-- ){
		cin >> N >> R; R = SQR( R );
		double rds, rrds; 
		rds = rrds = 0.0;
		int st = 1;
		
		REP( i, N ){ 
			cin >> x[i] >> y[i];
			inq[i] = 1; key[i] = INF;
		}
		
		key[0] = 0;
		int inqd = N;
		
		while( inqd ){
			int u = getmin(); inqd--;
			inq[u] = 0;
			
			if( u ){
				if( key[u] <= R ){ rds += sqrt( key[u] ); }
				else{ rrds += sqrt( key[u] ); st++; }
			}
			
			REP( i, N ) if( inq[i] ){
				int d = SQR(x[u]-x[i]) + SQR(y[u]-y[i]);
				if( d < key[i] ) key[i] = d;
			}
		}
		
		cout << "Case #" << tc++ << ": " << st << " " << int( round(rds) ) << " " << int( round(rrds) ) << "\n";
	}
	return 0;
}




















