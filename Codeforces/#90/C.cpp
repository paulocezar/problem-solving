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

struct subject_t{
	int64 a, b; int c, id;
	subject_t( int64 aa = 0, int64 bb = 0, int cc = 0, int ii = 0 ) : a(aa), b(bb), c(cc), id(ii) {}
	bool operator < ( const subject_t& s ) const {
		if( c != s.c ) return c < s.c;
		if( a != s.a ) return a < s.a;
		return b < s.b;
	}
};

#define MAXN 55
subject_t subject[MAXN];
int n, m, k;

int64 dp[51][51][51][101];

int64 solve( int pos, int last, int sub, int more ){
	if( pos == n ) return 0;
	if( sub == m ) return -2e17;
	
	int64 &r = dp[pos][last][sub][more];
	if( r != -1 ) return r;
	
	int64 ans = solve( pos, last, sub+1, more );
	if( subject[sub].c > subject[last].c ){
		int64 past = subject[last].a+more;
		if( subject[sub].a <= past+k && past+k <= subject[sub].b ){
			int64 ax = solve(pos+1, sub, sub+1, past+k-subject[sub].a);
			if( ax != -2e17 ) ans = max( ans, ax+past+k ); 
		}
		if( subject[sub].a <= past*k && past*k <= subject[sub].b ){
			int64 ax = solve(pos+1, sub, sub+1, past*k-subject[sub].a);
			if( ax != -2e17 ) ans = max( ans, ax+past*k );
		}
	}
	r = ans;
	return ans;
}


void show( int pos, int last, int sub, int more ){
	if( pos == n || sub == m ) return;
	int64 r = dp[pos][last][sub][more];
	
	if( sub+1 < m && dp[pos][last][sub+1][more] == r ){
		show( pos, last, sub+1, more );
		return;
	}
	
	if( subject[sub].c > subject[last].c ){
	
		int64 past = subject[last].a+more;
		if( subject[sub].a <= past+k && past+k <= subject[sub].b ){
			int64 ax = solve(pos+1, sub, sub+1, past+k-subject[sub].a);
			if( ax != -2e17 ){
				if( r == ax+past+k ){
					cout << subject[sub].id << " " << past+k << "\n";
					show(pos+1, sub, sub+1, past+k-subject[sub].a);
					return;
				}
			}
		}
		
		if( subject[sub].a <= past*k && past*k <= subject[sub].b ){
			int64 ax = solve(pos+1, sub, sub+1, past*k-subject[sub].a);
			if( ax != -2e17 ){
				if( r == ax+past*k ){
					cout << subject[sub].id << " " << past*k << "\n";
					show(pos+1, sub, sub+1, past*k-subject[sub].a);
					return;
				}
			}
		}
		
	}
	
	return;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cin >> n >> m >> k;
	REP( i, m ){
		cin >> subject[i].a >> subject[i].b >> subject[i].c; subject[i].id = i+1;
	}
	sort( subject, subject+m );
	
	REP( i, m ) REP( j, m ) REP( k, m ) REP( l, 101 )
		dp[i][j][k][l] = -1;
	
	int64 ans = -2e17;
	int first = 0;
	while( first < m ){
		int df = subject[first].b-subject[first].a;
		REP( i, df+1 ){
			int64 ax = solve( 1, first, first+1, i );
			if( ax != -2e17 ) ans = max( ans, ax+subject[first].a+i );
		}
		first++;
	}
	
	if( ans == -2e17 ) cout << "NO\n";
	else {
		cout << "YES\n";
		
		first = 0;
		while( first < m ){
			int df = subject[first].b-subject[first].a;
			REP( i, df+1 ){
				int64 ax = solve( 1, first, first+1, i );
				if( ax != -2e17 && ans == ax+subject[first].a+i ){
					cout << subject[first].id << " " << subject[first].a+i << "\n";
					show( 1, first, first+1, i );
					goto hell;
				}
			}
			first++;
		}
		
	}
hell:	
	return 0;
}




















