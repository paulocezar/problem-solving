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

int64 ans[10001];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int coins[21];
	for( int i = 1; i <= 21; i++ )
		coins[i-1] = i*i*i;
	
	ans[0] = 1;
	for( int x = 0; x < 21; x++ )
		for( int i = 1; i <= 10000; i++ ) if( i >= coins[x] )
			ans[i] += ans[i - coins[x]];
	
	int n;
	while( cin >> n ) cout << ans[n] << "\n";
	
	return 0;
}

























