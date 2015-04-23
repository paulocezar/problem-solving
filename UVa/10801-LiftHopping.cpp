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
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 6
#define MAXK 100

int t[MAXN], seen[MAXK];
vector<int> see[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	string line;
	int N, K, u, v, d;
	
	while( cin >> N >> K ){
		FILL( seen, INF  );
		REP( i, N ) cin >> t[i];
		cin.ignore();
		REP( i, N ){
			see[i].clear();
			getline( cin, line );
			istringstream in(line);
			while( in >> v ) see[i].PB( v );
		}
		
		priority_queue< pair<int,int> > q;
		REP( elev, N ) if( binary_search( ALL(see[elev]), 0 ) ){
			REP( i, SIZE(see[elev]) )if( t[elev]*see[elev][i] < seen[ see[elev][i] ] ){
				seen[ see[elev][i] ] = t[elev]*see[elev][i];
				q.push( MP( -seen[ see[elev][i] ], see[elev][i] ) );
			}
		}
		
		while( !q.empty() ){
			u = q.top().second;
			d = -q.top().first; q.pop();
			if( d > seen[ u ] ) continue;
			if( u == K ) break;
			REP( elev, N ) if( binary_search( ALL(see[elev]), u ) ){
				REP( i, SIZE(see[elev]) ) if( d+60+t[elev]*ABS(u-see[elev][i]) < seen[see[elev][i]] ){
					seen[ see[elev][i] ] = d+60+t[elev]*ABS(u-see[elev][i]);
					q.push( MP( -seen[ see[elev][i] ], see[elev][i] ) );
				}
			}
		}
		
		if( seen[K] == INF ) cout << "IMPOSSIBLE\n";
		else cout << seen[K] << '\n';
	}
	return 0;
}




















