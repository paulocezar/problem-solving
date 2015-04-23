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

#define MAXN 15

int N, n_sols;
int row[MAXN];
int y[1<<MAXN];

void play( int x, int col, int d1, int d2 ){
	if( x == N ){ n_sols++; return; }
	
	int canput = row[x] & col;
	int put;
	while( canput ){
		put = canput & -canput;
		if( (d1 & (1<<(x+y[put])))  && (d2 & (1<<(x-y[put]+N-1))) )
			play( x+1, col ^ put, d1 ^ (1<<(x+y[put])), d2 ^ (1<<(x-y[put]+N-1)) );
		canput ^= put;
	}
	
	/*  2x Faster..
	
		int canput = row[x] & col & ( d1 >> x ) & (d2 >> (N-x-1));
		int put;
		while( canput ){
			put = canput & -canput;
			play( x+1, col ^ put, d1 ^ ( put<<x ), d2 ^ (put<<(N-x-1)) );
			canput ^= put;
		}
	*/
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int tc = 1;
	string line;
	
	int vv = 1, rv = 0;
	while( vv < (1<<MAXN) ){ y[vv] = rv++; vv <<= 1; } 
	
	while( (cin>>N) && N ){
		REP( i, N ){
			cin >> line;
			row[ i ] = (1<<N)-1;
			REP( j, N ) if( line[j] == '*' ) row[i] ^= (1<<j);
		}
		n_sols = 0;
		play( 0, (1<<N)-1, (1<<(2*N-1))-1, (1<<(2*N-1))-1 );
		cout << "Case " << tc++ << ": " << n_sols << "\n";
	}
	
	return 0;
}




















