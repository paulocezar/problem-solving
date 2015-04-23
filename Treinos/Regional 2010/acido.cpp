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


#define join(a,b) (((a+b)==('S'+'B'))||((a+b)==('F'+'C')))

int dp[301][301];


int solve( int ini, int fim ){
	if( ini >= fim ) return 0;
	int &r = dp[ini][fim];
	if( r == -1 ){
		r = solve(ini+1,fim-1);
		int nd = fim-ini-1;
		if( !(nd&1) && 2*r == nd && join(s[ini],s[fim]) ) r++;
		else{
			for( int mid = ini; mid <= fim; mid++ )
				r = MAX(r,solve(ini,mid)+solve(mid+1,fim));
		}
	}
	return r;
}


int main( int argc, char* argv[] ){
	
	/* gen..
	char alf[4] = { 'S', 'B', 'F', 'C' };
	srand(time(NULL));
	REP( x, 1000 ){
		int len = (rand() % 300)+1;
		REP( i, len ){
			int pos = (rand() % 4);
			cout << alf[pos];
		}
		cout << "\n";
	}
	return 0;
	*/
	
	ios::sync_with_stdio(false);
	/*
	string ss;
	char s[333];
	while( cin >> ss ){
		int nn = SIZE(ss);
		int pstk = 0;
		int ans = 0;
		REP( i, nn ){
			if( pstk && join(ss[i],s[pstk-1]) ){
				pstk--; ans++;
			} else s[pstk++] = ss[i];
		}
		cout << ans << "\n";
	}
	*/
	
	
	int ini, fim, nd, len, i, n;
	string s;
	while( cin >> s ){
		
		n = SIZE(s);
		
		for( i = 0; i < n; i++ ) dp[i][i] = 0;
		
		for( len = 1; len < n; len++ ){
			for( ini = 0; ini+len < n; ini++ ){
				fim = ini+len;
				nd = fim-ini-1;
				if( nd >= 0 && !(nd&1) && dp[ini+1][fim-1]*2 == nd && join(s[ini],s[fim]) ){
					dp[ini][fim] = dp[ini+1][fim-1]+1;
				} else{
					dp[ini][fim] = 0;
					for( int mid = ini; mid+1 <= fim; mid++ )
						dp[ini][fim] = max(dp[ini][fim], dp[ini][mid]+dp[mid+1][fim] );
				}
			}
		}
		cout << dp[0][n-1] << "\n";
	}
	
	
	return 0;
}




















