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

char calc[101][101][11];
int dp[101][101][11];

int solve( int from, int to, int k ){
	if( from > to ) return 0;
	if( k == 1 ) return (((from+to)*(to-from+1))/2);
	int &res = dp[from][to][k];
	if( calc[from][to][k] ) return res;
	calc[from][to][k] = 1;
	res = INF;
	for( int blow = from; blow <= to; blow++ )
		res = min( res, max(blow+solve(blow+1,to,k),blow+solve(from,blow-1,k-1)) );
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	while( t-- ){
		int k, m;
		cin >> k >> m;
		cout << solve(1,m,k) << "\n";
	}
	
	return 0;
}

























