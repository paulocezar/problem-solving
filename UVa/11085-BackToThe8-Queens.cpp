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

#define MAXN 8
#define SOLS 92

int ns, sol[SOLS][MAXN];
int cand[MAXN];
int col, okl, okc1, okc2;

void build(){
	if( col == 8 ){
		REP( i, 8 ) sol[ns][i] = cand[i]+1; ns++;
		return;
	}
	REP( i, 8 ) if( (okl & (1<<i)) && (okc1 & (1<<(i+col))) && (okc2 & (1<<(i-col+7))) ){
		okl ^= (1<<i);
		okc1 ^= (1<<(i+col));
		okc2 ^= (1<<(i-col+7));
		cand[col] = i;
		col++;
		build();
		col--;
		okl |= (1<<i);
		okc1 |= (1<<(i+col));
		okc2 |= (1<<(i-col+7));
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	ns = 0; okl = (1<<8) - 1;  col = 0;
	okc1 = okc2 = (1<<15) - 1; 
	build();
	int t = 1;
	
	while( cin >> cand[0] ){ 
		FOR( i, 1, 8 ) cin >> cand[i];
		
		int ans = 8;
		REP(i, ns ){
			int cur = 0;
			REP( j, 8 ) if( cand[j] != sol[i][j] ) cur++;
			ans = MIN( ans, cur );
			if( cur == 0 ) break;
		}
		cout << "Case " << t++ << ": " << ans << "\n";
		
	}
	return 0;
}




















