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

int common(int64 x, int64 y){
	int ans = 0;
	int bit = 30;
	while( bit >= 0 ){
		if( (x&(1LL<<bit)) != (y&(1LL<<bit)) ) break;
		ans++;
		bit--;
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n, k;
	
	cin >> n >> k;
	int64 a[n];
	int nxt[n];
	
	REP( i, n ) cin >> a[i];
	sort( a, a+n );
	
	priority_queue< pair<int64, int> > q;
	
	REP( i, n-1 ){
		nxt[i] = i+1;
		q.push( MP( -(a[i]^a[i+1]), -i  ) ); 
	}
	
	while( k-- ){	
		int64 cur = -q.top().first;
		int i = -q.top().second; q.pop();
		
		cout << cur;
		
		nxt[i]++;
		if( nxt[i] < n ) q.push( MP( -(a[i]^a[nxt[i]]), -i ) );
	
		if( k ) cout << " ";
	}	
	cout << "\n";
	
	return 0;
}

























