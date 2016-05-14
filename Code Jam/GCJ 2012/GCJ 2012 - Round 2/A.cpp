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

#define MAXN 10000
int d[MAXN], l[MAXN];

int lseen[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	FOR( tc, 1, t ){
		
		cout << "Case #" << tc << ": ";
		
		int N;
		cin >> N;
		REP( i, N ) cin >> d[i] >> l[i];
		
		int D;
		cin >> D;
		
		priority_queue< pair<int,int> > q;
		q.push( MP( min(d[0],l[0]), 0 ) );
		
		memset( lseen, 0, sizeof(lseen) );
		
		while( !q.empty() ){
			
			int cur = q.top().second;
			int reach = q.top().first; q.pop();
			if( reach <= lseen[cur] ) continue;
			
			if( (d[cur]+reach) >= D ){ cout << "YES"; goto hell;}
			lseen[cur] = reach;
			
			int nxt = cur+1;
			while( nxt < N && d[cur]+reach >= d[nxt] ){
				q.push( MP(min(d[nxt]-d[cur], l[nxt]), nxt) );
				nxt++;
			}
			
		}
		cout << "NO";
	hell:
		cout << "\n";
		
	}	
	
	return 0;
}


























