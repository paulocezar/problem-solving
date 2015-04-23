#include <map> 
#include <set> 
#include <list>
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
	string curstr, sep;
	int cur, sz = 0;
	
	cin >> n;	
	list< string > wrds[11];
	string a[n];
	
	REP( i, n ){
		cin >> a[i];
		cur = SIZE( a[i] );
		sz += cur;
	}
	
	cin >> sep;
	sz = (2*sz)/n;
	
	REP(i,n) { a[i] += sep; wrds[SIZE(a[i])-1].push_back( a[i] ); }
	sort( a, a+n );
	REP( i, 11 ) wrds[ i ].sort();
	
	REP( i, n ){
		curstr = a[i];		
		cur = SIZE( curstr )-1;
		if( wrds[cur].empty() || *wrds[cur].begin() != curstr ) continue;
		wrds[ cur ].pop_front();
		
		string nxt = *wrds[ sz-cur ].begin();
		wrds[ sz-cur ].pop_front();
		
		cout << a[i] << nxt.substr( 0, sz-cur ) << endl;
	}
	
	return 0;
}
