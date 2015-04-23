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
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct envelope_t{
	int h, w, id;
	envelope_t( int hh = 0, int ww = 0, int ii = 0 ) : h(hh), w(ww), id(ii) {}
	bool operator < ( const envelope_t& e ) const {
		if( h != e.h ) return h < e.h;
		return w < e.w;
	}
};

bool fit( int h1, int w1, int h2, int w2 ){
	return ((h1 < h2) && (w1 < w2)); 
}

#define MAXN 5000
envelope_t e[MAXN];
int pa[MAXN], dp[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, h, w;
	cin >> N >> h >> w;
	REP( i, N ){
		cin >> e[i].h >> e[i].w;
		e[i].id = i;
	}
	sort( e, e+N );
	
	int ans = 0, ians;
	REP( i, N ){
		
		if( fit(h,w,e[i].h,e[i].w) ){
			dp[i] = 1; pa[i] = i;
		} else dp[i] = 0;
		
		int j = i-1;
		while( j >= 0 ){
			if( fit(e[j].h,e[j].w,e[i].h,e[i].w) ){
				if( dp[j] && (dp[j]+1 > dp[i]) ){
					dp[i] = dp[j]+1;
					pa[i] = j;
				}
			}
			j--;
		}
		
		if( dp[i] > ans ){
			ans = dp[i];
			ians = i;
		}		
	}
	
	cout << ans << "\n";
	if( ans ){
		vector< int > show;
		while( pa[ians] != ians ){
			show.PB( e[ians].id+1 );
			ians = pa[ians];
		}
		show.PB( e[ians].id+1 );
		reverse( ALL(show) );
		REP( i, SIZE(show) ){
			if( i ) cout << " ";
			cout << show[i];
		}
		cout << "\n";
	}
	return 0;
}




















