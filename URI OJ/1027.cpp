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
	
	int N, x, y;
	while( cin >> N ){
		
		vector< int > real_y;
		map< int, vector< int > > occ;
		
		REP( i, N ){
			cin >> x >> y;
			occ[ y ].PB( x ); 
			real_y.PB( y );
		}
		
		sort( ALL(real_y) ); 
		real_y.resize( unique(ALL(real_y)) - real_y.begin() );
		REP( i, SIZE(real_y) ) sort( ALL(occ[real_y[i]]) );
		
		
		vector< int > major;
		REP( i, SIZE(real_y)-1 ){
			if( real_y[i+1]-real_y[i] == 2 )
				major.PB( real_y[i]+1 );
			if( i+2 < SIZE(real_y) && real_y[i+2]-real_y[i] == 2 )
				major.PB( real_y[i]+1 );
		}
		
		int ans = 0;
		REP( i, SIZE(major) ){
			int yu = major[i]-1;
			int yl = major[i]+1;
			
			int lu = -INF;
			int ll = -INF;
			
			int u = 0, l = 0;
			int cur = 0;
			
			while( u < SIZE(occ[yu]) && l < SIZE(occ[yl]) ){
		
				if( cur&1 ){ //put u
					while( u < SIZE(occ[yu]) && occ[yu][u] <= ll ) u++;
					if( u < SIZE(occ[yu]) ){
						lu = occ[yu][u];
						cur++;
					}
				} else { // put l
					while( l < SIZE(occ[yl]) && occ[yl][l] <= lu ) l++;
					if( l < SIZE(occ[yl]) ){
						ll = occ[yl][l];
						cur++;
					}
				}
				
			}
			
			
			ans = max( ans, cur );
			
			yl = major[i]-1;
			yu = major[i]+1;
			
			lu = -INF;
			ll = -INF;
			
			u = 0, l = 0;
			cur = 0;
			
			while( u < SIZE(occ[yu]) && l < SIZE(occ[yl]) ){
		
				if( cur&1 ){
					while( u < SIZE(occ[yu]) && occ[yu][u] <= ll ) u++;
					if( u < SIZE(occ[yu]) ){
						lu = occ[yu][u];
						cur++;
					}
				} else {
					while( l < SIZE(occ[yl]) && occ[yl][l] <= lu ) l++;
					if( l < SIZE(occ[yl]) ){
						ll = occ[yl][l];
						cur++;
					}
				}
				
			}
			ans = max( ans, cur );
			
		}
		if( N>0 && ans == 0 ) ans = 1;
		cout << ans << "\n";
		
	}
	
	return 0;
}

























