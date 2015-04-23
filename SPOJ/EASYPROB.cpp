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

void solve( int x ){
	if( x == 0 ) { cout << "0"; return; }
	if( x == 2 ) { cout << "2"; return; }
	
	if( x == (x&(-x)) ){
		int lg = 0;
		while( (1<<(lg+1)) <= x ) lg++;
		cout << "2(";
		solve( lg );
		cout << ")";
		return;
	} 
	
	int lg = 0;
	while( (1<<(lg+1)) <= x ) lg++;
	
	bool first = true;
	while( lg >= 0 ){
		if( x & (1<<lg) ){
			if( !first ) cout << "+";
			solve( 1<<lg );
			first = false;
		}
		lg--;
	}
	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cout << "137="; solve( 137 ); cout << "\n";
	cout << "1315="; solve( 1315 ); cout << "\n";
	cout << "73="; solve( 73 ); cout << "\n";
	cout << "136="; solve( 136 ); cout << "\n";
	cout << "255="; solve( 255 ); cout << "\n";
	cout << "1384="; solve( 1384 ); cout << "\n";
	cout << "16385="; solve( 16385 ); cout << "\n";
	
	return 0;
}




















