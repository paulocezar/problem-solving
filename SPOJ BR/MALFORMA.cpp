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

#define MAXN 51
int64 K, dp[MAXN][MAXN][2];
int N;

int64 solve( int opn, int cls, int bad ){
	if( (opn+cls) == N ) return dp[opn][cls][bad] = ((opn != cls) || bad);
	if( dp[opn][cls][bad] == -1 ){
		dp[opn][cls][bad] = solve( opn+1, cls, bad );
		dp[opn][cls][bad] += solve( opn, cls+1, bad || ((cls+1)>opn) );
	}
	return dp[opn][cls][bad];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	string ans;
	
	cin >> t;
	while( t-- ){
		cin >> N >> K;
		if( N & 1LL ){
			if( K >= (1LL<<N) ) ans = "-1";
			else {
				ans = "";
				REP( i, N ){
					if( K & (1LL<<i) ) ans += ")";
					else ans += "(";
				}
				reverse( ALL(ans) );
			}
		} else {
			REP( i, N+1 ) REP( j, N+1 ){
				dp[i][j][0] = -1;
				dp[i][j][1] = 1LL<<(N-(i+j));
			}
			solve( 0, 0, 0 );
			
			int opn = 0;
			int cls = 0;
			int bd = 0;
			if( dp[0][0][0] > K ){
				ans = "";
				while( (opn+cls) < N ){
					//cout << K << " " << dp[ps+1][opn+1][cls][bd] << " " << dp[ps+1][opn][cls+1][ bd || ((cls+1)>opn) ] << endl;
					if( dp[opn+1][cls][bd] > K ){
						ans += "(";
						opn++;
					} else {
						K -= dp[opn+1][cls][bd];
						ans += ")";
						cls++;
					}
					bd = bd || ( cls > opn );
				}
			} else ans = "-1";	
		}
		
		cout << ans << "\n";
	}

	return 0;
}




















