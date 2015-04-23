#include <map> 
#include <set> 
#include <cmath> 
#include <queue> 
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define TI(X) X::iterator
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int n;
	cin >> n;
	
	int sz = (n+1)/2;
	int a[sz];
	int b[sz];
	
	REP( i, sz ) cin >> a[i];
	
	if( n&1 ){
		b[sz-1] = a[sz-1];
		RFOR( i, sz-1, 0 ) cin >> b[i];
	} else RREP( i, sz ) cin >> b[i];
	
	int ans = n;
	
	map< int, int > xx;
	REP( i, sz ){
		xx[ a[i]-i ]++;
		if( i != sz-1 || !(n&1) ) xx[ b[i]-i ]++;
	}
	
	for( map<int, int>::iterator ii = xx.begin(); ii != xx.end(); ii++ ) if( ii->first > 0 && (n - ii->second) < ans )
		ans = n - ii->second;
	
	
	cout << ans << endl;
	
	return 0;
}
