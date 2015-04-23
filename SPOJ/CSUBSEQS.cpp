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

map< int, int64 > dp;

int encode( int p1, int p2, int p3, int p4, int end ){
	return  (((((((p1<<6) | p2)<<6) | p3)<<6) | p4)<<6 | end);
}

void decode( int state, int &p1, int &p2, int &p3, int &p4, int &end ){
	end = state & 63; state >>= 6;
	p4 = state & 63; state >>= 6;
	p3 = state & 63; state >>= 6;
	p2 = state & 63; state >>= 6;
	p1 = state & 63;
}

string s[4];
int pre[4][26][55];

int64 solve( int state ){
	
	int p1, p2, p3, p4, ending;
	
	if( dp.count( state ) ) return dp[ state ];
	int64 &res = dp[ state ];
	
	decode( state, p1, p2, p3, p4, ending );
	
	p1 = pre[0][ending][p1];
	p2 = pre[1][ending][p2];
	p3 = pre[2][ending][p3];
	p4 = pre[3][ending][p4];
	
	if( p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0 ) return 0;
	res = 1;
	
	if( p1 && p2 && p3 && p4 ) for( char ndn = 0; ndn < 26; ndn++ )
		res += solve( encode(p1-1, p2-1, p3-1, p4-1, ndn) );
	
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	
	REP( i, 4 ) REP( j, 26 ) REP( k, SIZE(s[i]) )
		pre[i][j][k] = ((s[i][k]==(j+'a'))?(k):(k?pre[i][j][k-1]:-1));
	
	int64 res = 0;
	for( int ending = 0; ending < 26; ending++ )
		res += solve( encode(SIZE(s[0])-1,SIZE(s[1])-1,SIZE(s[2])-1,SIZE(s[3])-1,ending) );
	cout << res << "\n";
	
	return 0;
}

























