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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 111
int from[MAXN], to[MAXN], val[2*MAXN];
int cur;

char segt[512];
char updt[512];

void refresh(int node,bool prop){
	if(prop){
		int ls = 2*node+1;
		int rs = ls+1;
		updt[ls]+=updt[node];
		updt[rs]+=updt[node];
	}
	segt[node] += updt[node];
	updt[node] = 0;
}

void update( int node, int lo, int hi ){
	if( from[cur] <= lo && hi <= to[cur] ){
		updt[node]++;
		refresh(node,lo!=hi);
	} else {
		
		int ls = 2*node+1;
		int rs = ls+1;
		int mid = (lo+hi)/2;
		
		refresh(node,lo!=hi);
		refresh(ls,lo!=mid);
		refresh(rs,(mid+1)!=hi);
		
		if( mid >= from[cur] ) update(ls,lo,mid);
		if( mid+1 <= to[cur] ) update(rs,mid+1,hi);	
		
		segt[node] = MAX(segt[ls],segt[rs]);
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, N;
	cin >> t;
	while( t-- ){
		cin >> N;
		REP( i, N ){
			cin >> from[i] >> to[i];
			val[2*i] = from[i];
			val[2*i+1] = to[i];
		}
		sort( val, val+2*N );
		
		map< int, int > a;
		a[val[0]] = 0;
		int nxt = 1;
		
		FOR( i, 1, 2*N-1 ) if( val[i] != val[i-1] ) a[val[i]] = nxt++;
		
		FILL(segt,0);
		FILL(updt,0);
		
		cur = 0;
		while( cur < N ){
			from[cur] = a[from[cur]];
			to[cur] = a[to[cur]];
			update( 0, 0, nxt-1 );
			cur++;
		}
		cout << int(segt[0]) << "\n";
	}
	
	return 0;
}




















