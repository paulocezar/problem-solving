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
	while( t-- ){
		
		int N, S, Q;
		cin >> N >> S >> Q;
		
		queue< int > station_q[N+1];
		int deliver = 0;
		REP( i, N ){
			int x; cin >> x;
			while( x-- ){
				int y; cin >> y;
				deliver++;
				station_q[i+1].push( y );
			}
		}
		
		stack< int > carrier;
		int cur_station = 1;
		int ans = 0;
		while( true ){
			
			while( !carrier.empty() ){
				if( carrier.top() == cur_station ){
					carrier.pop();
					ans++;
					deliver--;
				} else {
					if( SIZE(station_q[cur_station]) < Q ){
						ans++;
						station_q[cur_station].push( carrier.top() );
						carrier.pop();
					} else break;
				}
			}
			
			while( SIZE(carrier) < S && SIZE(station_q[cur_station]) ){
				ans++;
				carrier.push( station_q[cur_station].front() );
				station_q[cur_station].pop();
			}
			if( deliver == 0 ) break;
			ans += 2;
			
			cur_station++;
			if( cur_station > N ) cur_station = 1;		
		}
		cout << ans << "\n";
	}
	
	return 0;
}

























