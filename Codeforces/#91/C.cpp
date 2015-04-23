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

int N;
bool islucky( int64 num ){
	while( num ){
		int dig = num%10;
		if( dig != 4 && dig != 7 ) return false;
		num /= 10;
	}
	return true;
}

vector< int64 > lucky;
void gen( int64 cur ){
	if( cur > 7777777777LL ) return;
	if( cur ) lucky.PB( cur );
	gen( 10LL*cur + 4LL );
	gen( 10LL*cur + 7LL );
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	lucky.clear();
	gen( 0 );
	sort( ALL(lucky) );
	
	int n;
	int64 k;
	
	cin >> n >> k;
	N = min( n, 13 );
	int mask = (1<<N)-1;
	
	int64 f[N+1]; f[0] = 1;
	FOR( i, 1, N ) f[i] = f[i-1]*i;
	
	if( f[N] < k ) cout << "-1\n";
	else {
		
		int ans[N];
		REP( pos, N ){
			
			int64 skiped = 0;
			int nsk = 0;
			while( skiped+f[N-pos-1] < k ){
				skiped += f[N-pos-1];
				nsk++;
			}
			
			k -= skiped;
			REP( i, N ) if( mask & (1<<i) ){
				if( nsk == 0 ){
					ans[pos] = i;
					mask ^= (1<<i);
					break;
				}
				nsk--;
			}
			
		}
		
		//REP( i, max(n-13,0)) cout << i+1 << " ";
		//REP( i, N ) cout << max(n-13,0)+ans[i]+1 << " ";
		//cout << endl;
			
		int res = 0;
		while( lucky[res] <= max(n-13,0) ) res++;
		REP( i, N ) if( islucky(max(n-13,0)+i+1) && islucky(max(n-13,0)+ans[i]+1) )
			res++;
		cout << res << "\n";
		
	}
	
			
	return 0;
}




















