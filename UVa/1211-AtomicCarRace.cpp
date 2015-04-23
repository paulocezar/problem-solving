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

#define MAXN 111
#define MAXX 10000

int n, a[MAXN];
double cost[MAXX+1];

int calc[MAXN], calc_now;
double b, v, f, e, dp[MAXN];

double solve( int last_checkpoint ){
	if( last_checkpoint == n ) return 0.0;
	
	double &res = dp[last_checkpoint];
	if( calc[last_checkpoint] == calc_now ) return res;
	calc[last_checkpoint] = calc_now;
	res = 2e9;

	for( int nxt_ckp = last_checkpoint+1; nxt_ckp <= n; nxt_ckp++ )
		res = min( res,cost[a[nxt_ckp]-a[last_checkpoint]-1] + (nxt_ckp==n?0:b) + solve(nxt_ckp) );

	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	a[0] = 0;
	
	int r;
	while( cin >> n && n ){
		
		for( int i = 1; i <= n; i++ ) cin >> a[i];
		cin >> b;
		cin >> r >> v >> e >> f;
		
		
		for( int x = 0; x <= a[n]; x++ ) cost[x] = (x?cost[x-1]:0.0) + ((x >= r)?(1.0/(v-e*(x-r))):(1.0/(v-f*(r-x))));
		
		calc_now++;
		cout << fixed << setprecision(4) << solve(0) << "\n";
		
	}
	
	return 0;
}

























