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

#define MAXN 151
#define MAXN5 101
#define MAXN10 51

char calc[MAXN][MAXN5+MAXN10][MAXN10], calc_now;
int dp[MAXN][MAXN5+MAXN10][MAXN10];

int money;

int solve( int C, int n5, int n10 ){
	
	if( C == 0 ) return 0;
	int &res = dp[C][n5][n10];
	if( calc[C][n5][n10] == calc_now ) return res;
	calc[C][n5][n10] = calc_now;
	res = 2e9;
	
	int n1 = money - 5*n5 - 10*n10;
	
	money -= 8;
	if( n10 > 0 ) res = min( res, 1+solve(C-1,n5,n10-1) );
	if( n5 > 1 ) res = min( res, 2+solve(C-1,n5-2,n10) );
	if( n5 > 0 && n1 > 2 ) res = min( res, 4+solve(C-1,n5-1,n10) );
	if( n1 > 7 ) res = min( res, 8+solve(C-1,n5,n10) );
	if( n10 > 0 && n1 > 2 ) res = min( res, 4+solve(C-1,n5+1,n10-1) );
	money += 8;
	
	return res;
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	while( t-- ){
		int C, n1, n5, n10;
		cin >> C >> n1 >> n5 >> n10;
		
		calc_now++;
		money = n1 + 5*n5 + 10*n10;
		
		cout << solve(C,n5,n10) << "\n";
	}
	
	return 0;
}

























