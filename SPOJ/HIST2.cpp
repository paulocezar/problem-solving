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

#define MAXN 15

int dp[MAXN+1][1<<MAXN];
char calc[MAXN+1][1<<MAXN], calc_now;

int64 dp2[MAXN+1][1<<MAXN];
char calc2[MAXN+1][1<<MAXN], calc2_now;

int h[MAXN+1], N;

int solve( int last, int mask ){
	if( !mask ) return 0;
	
	int &res = dp[last][mask];
	if( calc[last][mask] == calc_now ) return res;
	calc[last][mask] = calc_now;
	
	res = -INF;
	for( int i = 0; i < N; i++ ) if( mask & (1<<i) )
		res = max( res, 2 + h[i] - h[last] + abs(h[last]-h[i]) + solve(i,mask ^ (1<<i)) );
	
	return res;
}

int64 solve2( int last, int mask ){
	if( !mask ) return 1;
	
	int64 &res = dp2[last][mask];
	if( calc2[last][mask] == calc2_now ) return res;
	calc2[last][mask] = calc2_now;
	res = 0;
	
	for( int i = 0; i < N; i++ ) if( mask & (1<<i) )
		if( dp[last][mask] == (2 + h[i] - h[last] + abs(h[last]-h[i]) + dp[i][mask ^ (1<<i)]) )
			res += solve2(i,mask ^ (1<<i));
	
	return res;
}



int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	while( cin >> N && N ){
		for( int i = 0; i < N; i++ )
			cin >> h[i];
		h[N] = 0;
		calc_now++;
		calc2_now++;
		cout << solve( N, (1<<N) - 1 ) << " ";
		cout << solve2( N, (1<<N) - 1 ) << "\n"; 
	}
	
	return 0;
}

























