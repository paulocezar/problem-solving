#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(double a, double b) { return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N;
int digit[10];
int inp[10];
string sdigit[10] = { "YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY" };
	
int enc( string s ){
	int ans = 0;
	REP( i, SIZE(s) ) if( s[i] == 'Y' ) ans |= (1<<i);
	return ans;
}

bool solve( int val, int pos, int burn ){
	//cout << val << " " << pos << " " << burn << endl;
	if( pos == N ) return true;
	if( val < 0 ) return false;
	
	if( burn & inp[pos] ) return false;
	if( inp[pos] & (~digit[val]) ) return false;
	int off = digit[val] & (~inp[pos]);
	return solve( val-1, pos+1, burn | off );
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	REP( i, 10 ) digit[i] = enc( sdigit[i] );
		
	cin >> N;
	while( N ){
		
		REP( i, N ){ cin >> sdigit[i]; inp[i] = enc(sdigit[i]); }
		
		RREP( i, 10 ) if( solve(i, 0, 0) ){ cout << "MATCH\n"; goto hell; }
		cout << "MISMATCH\n";	
	hell:
		cin >> N;
	}
	
	return 0;
}




















