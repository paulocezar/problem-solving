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

#define MAXN 100000

int t[MAXN], x[MAXN];


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n, m;
	cin >> n >> m;
	
	REP( i, n ) cin >> t[i] >> x[i];
	
	int time_passed = 0;
	int cur_stdnt = 0;
	
	while( cur_stdnt < n ){
		
		priority_queue< pair<int,int> > bus;
		while( (cur_stdnt < n) && (SIZE(bus) < m) ){
			bus.push( MP(-x[cur_stdnt], cur_stdnt) );
			time_passed = max( time_passed, t[cur_stdnt] );
			cur_stdnt++;
		}
		
		int lastx = 0;
		while( !bus.empty() ){
			
			int curx = -bus.top().first;
			int stdnt = bus.top().second; bus.pop();
			int k = 1;
			time_passed += (curx-lastx);
			t[stdnt] = time_passed;
			
			while( !bus.empty() && (bus.top().first == -curx) ){
				stdnt = bus.top().second; bus.pop();
				k++;
				t[stdnt] = time_passed;
			}
				
			lastx = curx;
			time_passed += ((k/2) + 1);
		}
		time_passed += lastx;
		
	}
	
	REP( i, n ){ if( i ) cout << " "; cout << t[i]; }
	cout << "\n";
		
	return 0;
}

























