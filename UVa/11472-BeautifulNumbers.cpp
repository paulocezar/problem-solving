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

#define PB push_back
#define MP make_pair

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1000000007;

char calc[10][101][1<<10], calc_now;
int n, dp[10][101][1<<10];

int solve( int last, int need, int unused ){
	if( need < 0 ) return 0;
	if( !need ) return (unused?0:1);
	
	int &res = dp[last][need][unused];
	if( calc[last][need][unused] == calc_now ) return res;
	calc[last][need][unused] = calc_now;
	
	res = (unused?0:1);
	if( last+1 < n ){
		int nunused = unused;
		nunused &= ~(1<<(last+1));
		res += solve( last+1, need-1, nunused);
		res %= MOD;
	}	 
	if( last-1 >= 0 ){
		int nunused = unused;
		nunused &= ~(1<<(last-1));
		res += solve( last-1, need-1, nunused);
		res %= MOD;
	}
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		int m;
		cin >> n >> m;
		int res = 0;
		
		calc_now++;
		for( int i = 1; i < n; i++ ){
			int unused = (1<<n) - 1;
			unused ^= (1<<i);
			res += solve( i, m-1, unused );
			res %= MOD;
		}
		
		cout << res << "\n";
	}
	
	return 0;
}

























