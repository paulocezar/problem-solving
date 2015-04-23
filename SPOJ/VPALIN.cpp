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

vector< int > f;
vector< char > s;

int64 period( int n ){
	
	if( SIZE(f) < n+1 ) f.resize(n+1);
	f[0] = f[1] = 0;
	
	FOR( i, 1, n-1 ){
		int j = f[i];
		while( s[j] != s[i] ){
			if( j == 0 ){ j = -1; break; }
			j = f[j];
		}
		f[i+1] = j+1;
	}
	
	int len = ((n%(n-f[n]))?n:(n-f[n]));
	int64 hsh = 0;
	REP( i, len ) hsh = 33LL*hsh + (s[i]-'a');
	return hsh;
}

int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n;
	n = next_int();
	
	map< int64, int64 > vish;
	REP( i, n ){
		int len = next_int();
		if( SIZE(s) < len ) s.resize(len);
		
		s[0] = getchar_unlocked();
		while( !('a' <= s[0] && s[0] <= 'z') ) s[0] = getchar_unlocked();
		
		FOR( i, 1, len-1 ) s[i] = getchar_unlocked();
		vish[ period(len) ]++;
	}
	int64 ans = 0;
	FORIT(one,vish) ans += (one->second)*(one->second);
	printf("%lld\n", ans);
	return 0;
}

























