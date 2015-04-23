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

#define MAXN 1111
double x[MAXN], y[MAXN];

double dist[MAXN][MAXN];

int visited[MAXN], visited_now;

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N;
	while( cin >> N && N ){
	REP( i, N ) cin >> x[i] >> y[i];
	
	REP( i, N ) REP( j, N )
		dist[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);

	double lo = 0., hi = 1e9;
	REP( step, 100 ){
		double mid = (lo+hi)*.5;
		
		queue< int > q;
		q.push( 0 ); visited[0] = ++visited_now;
		int seen = 0;
		
		while( !q.empty() ){
			int u = q.front(); q.pop();
			seen++;
			REP( i, N ) if( dist[u][i] <= mid && visited[i] != visited_now ){
				visited[i] = visited_now;
				q.push( i );
			}
		}
		
		if( seen == N ) hi = mid;
		else lo = mid;		
		
	}
	cout << fixed << setprecision(4) << sqrt(lo) << "\n";
	}
	return 0;
}

























