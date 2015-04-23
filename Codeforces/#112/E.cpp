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

#define MAXN 1000000

int a[MAXN];
int found[1<<22];
int bit[22];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int N;
	cin >> N;
	
	int ndd = 1;
	
	REP( i, N ){ cin >> a[i]; ndd = max( ndd, int(ceil(log2(a[i]))) ); }
	REP( i, ndd ) bit[i] = (1<<i);
	
	
	int mask = (1<<ndd)-1;
	REP( i, N ) found[ a[i] ^ mask ] = a[i];
 	

	while( mask ){
		
		if( !found[ mask ] ){
			
			REP( i, ndd ) if( !(mask & bit[i]) ){
				if( found[ mask | bit[i] ] ){
					
					found[mask] = found[ mask | bit[i] ];
					break;
					
				}
			}
			
		}
		
		mask--;
	}
	
	REP( i, N ){
		if( i ) cout << " ";
		if( !found[a[i]] ) cout << "-1";
		else cout << found[a[i]];
	}
	cout << "\n";
	
			
	return 0;
}

























