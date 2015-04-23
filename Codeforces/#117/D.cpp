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

#define MAXN 100001
int p[MAXN];

string smallest_divisor( string &s ){
	
	int n = SIZE(s);
	
	p[0] = 0, p[1] = 0;
	FOR( i, 1, n-1 ){
		int j = p[i];
		while( s[i] != s[j] ){
			if( j == 0 ){ j = -1; break; }
			j = p[j];
		}
		p[i+1] = j+1; 
	}
	
	int x = n/(n-p[n]);
	if( x*(n-p[n]) != n ) x = 1;
	
	int len = n/x;
	return s.substr(0,len);
	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	string s1, s2;
	cin >> s1 >> s2;
	
	if( SIZE(s1) > SIZE(s2) ) swap(s1,s2);
	
	
	string divisor = smallest_divisor(s1);
	
	int n1 = SIZE(s1);
	int n2 = SIZE(s2);
	int nd = SIZE(divisor);
	
	REP( i, n2 ) if( divisor[i%nd] != s2[i] ){
		cout << "0\n";
		return 0;
	}
	
	int len = nd;
	int ans = 0;
	while( len <= n1 ){
		if( n1 % len == 0 && n2 % len == 0 ) ans++;
		len += nd;
	}
	cout << ans << "\n";

	return 0;
}

























