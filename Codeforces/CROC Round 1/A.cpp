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

int gcd( int a, int b ){
	while( b ){
		a %= b;
		swap( a, b );
	}
	return a;
}

int mmc( int a, int b ){
	return (a/gcd(a,b))*b;
}

bool win( char a, char b ){
	if( a == 'R' && b =='S' ) return true;
	if( a == 'S' && b == 'P' ) return true;
	if( a == 'P' && b == 'R' ) return true;
	return false;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	
	string A, B;
	cin >> A >> B;
	int m = SIZE(A);
	int k = SIZE(B);
	
	int need = mmc(m,k);
	int aa = 0, bb = 0;
	REP( i, need ){
		if( win(A[i%m], B[i%k]) ) bb++;
		if( win(B[i%k], A[i%m]) ) aa++;
	}
	
	int repeated = n / need;
	aa = repeated*aa;
	bb = repeated*bb;
	
	int other = n % need;	
	REP( i, other ){
		if( win(A[i%m], B[i%k]) ) bb++;
		if( win(B[i%k], A[i%m]) ) aa++;
	}
	
	cout << aa << " " << bb << "\n";
	
	
	return 0;
}

























