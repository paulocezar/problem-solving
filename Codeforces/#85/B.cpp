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
#include <bitset>

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

#define MXXX 100001

int64 sieve_size;
bitset< MXXX+10 > bs;
vector< int > primes;

void sieve(){
	sieve_size = MXXX; primes.clear();
	bs.reset(); bs.set( 2, true ); primes.PB( 2 );
	FOR( i, 3, sieve_size ) if( i&1 ) bs.set( i, true );
	for( int i = 3; i <= 320; i+=2 ) if( bs.test(i) ){
		for( int j = i*i; j <= sieve_size; j+=i ) bs.set(j, false);
	}
	for( int i = 3; i < MXXX; i+=2 ) if( bs.test(i) )
		primes.PB( i );
}

int last[100001];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	//sieve();
	
	int N, x, y;
	cin >> N;
	
	REP( i, 100001 ) last[i] = -2;
	
	REP( j, N ){
		
		cin >> x >> y;
		int ans = 0;
		
		for( int i = 1; i*i <= x; i++ ){
			
			if( !(x % i) ){
				if( last[i] < j-y ) ans++;
				last[i] = j;
				
				int c = x/i;
				if( c > i ){
					if( last[c] < j-y ) ans++;
					last[c] = j;
				}
				
			}
			
		}
		
		cout << ans << "\n";
	}
	
	
	return 0;
}




















