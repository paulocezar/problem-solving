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

#define MAXN 155

string wrd;
int dp[MAXN][MAXN];

char wut( int i, int j ){
	if( i == j ) return 0;
	if( i > j ) return 1;
	if( dp[i][j] != -1 ) return dp[i][j]; 
	dp[i][j] = 0;
	
	int ni = i;
	while( ni <= j && wrd[ni] == wrd[i] ) ni++;
	ni--;
	
	if( ni > i ) dp[i][j] = wut( ni+1, j );
	int pos = ni+1;
	while( pos <= j && !dp[i][j] ){
		if( wrd[pos] == wrd[i] ){
			int bg = pos;
			while( pos <= j && wrd[pos] == wrd[i] ) pos++;
			pos--;
			
			dp[i][j] = wut( ni+1, bg-1 ) && wut( pos+1, j );
			if( !dp[i][j] ) dp[i][j] = wut(ni+1,bg-1) && wut(pos,j);
		}
		pos++;
	}
	
	if( dp[i][j] ) return dp[i][j];
	
	int nj = j;
	while( nj >= i && wrd[nj] == wrd[j] ) nj--;
	nj++;
	
	if( j > nj ) dp[i][j] = wut(i, nj-1);
	pos = nj-1;
	while( pos >= i && !dp[i][j] ){
		if( wrd[pos] == wrd[j] ){
			int bg = pos;
			while( pos >= i && wrd[pos] == wrd[j] ) pos--;
			pos++;
			
			dp[i][j] = wut( i, pos-1 ) && wut( bg+1, nj-1 );
			if( !dp[i][j] ) dp[i][j] = wut( i, pos ) && wut(bg+1,nj-1);
		}
		pos--;
	}
	
	return dp[i][j];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		string ans = "";
		REP( i, 5 ){
			cin >> wrd;
			FILL( dp, -1 );
			ans += ( wut( 0, SIZE(wrd)-1 )?('R'):('I') );
		}
		cout << ans << "\n";
	}
	
	return 0;
}




















