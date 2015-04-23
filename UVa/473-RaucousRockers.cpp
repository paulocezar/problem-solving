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

vector< vector< vector<int> > > dp;
vector<int> song;
int N, T, M;

int solve( int pos, int mins, int discs ){
	if( pos == N ) return 0;
	int &r = dp[pos][mins][discs];
	if( r == -1 ){
		r = solve( pos+1, mins, discs );
		if( mins >= song[pos] ) r = MAX( r, 1 + solve( pos+1, mins-song[pos], discs ) );
		else if( discs ) r = MAX( r, 1 + solve( pos+1, T-song[pos], discs-1 ) );
	}
	return r;	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t; string line;
	cin >> t;
	while( t-- ){
		
		cin >> N >> T >> M;
		dp.resize( N ); song.resize( N );
		
		cin.ignore();
		getline(cin, line );
		REP( i, SIZE(line) ) if( !( '0' <= line[i] && line[i] <= '9' ) ) line[i] = ' ';
		istringstream in( line );
		REP( i, N ){
			in >> song[i];
			dp[i].resize( T+1 );
			REP( j, T+1 ){
				dp[i][j].resize( M+1 );
				REP( k, M+1 ){
					dp[i][j][k] = -1;
				}
			}
		}
		cout << solve( 0, 0, M ) << "\n";
		if( t ) cout << "\n";
	}	
	return 0;
}




















