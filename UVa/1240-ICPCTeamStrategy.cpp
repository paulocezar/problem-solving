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

int dp[3][1<<12], popc[1<<12], tneeded[3][12], ds[12], N;

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio(false);
	
	for( int i = 0; i < 12; i++ ) ds[i] = (1<<i);
	for( int i = 0; i < (1<<12); i++ ) popc[i] = (i&1) + popc[i>>1];
	
	int t;
	cin >> t;
	while( t-- ){
		
		cin >> N;
		
		for( int who = 0; who < 3; who++ )
			for( int i = 0; i < N; i++ )
				cin >> tneeded[who][i];
		
		int all = (1<<N)-1;
		int ans = 0;
		dp[0][0] = dp[1][0] = dp[2][0] = 0;
		
		for( int solved = 1; solved <= all; solved++ ){
			for( int who = 0; who < 3; who++ ){
				dp[who][solved] = 281;
				
				for( int prob = 0; prob < N; prob++ ) if( solved & ds[prob] ){
					for( int prev = 0; prev < 3; prev++ ) if( prev != who )
						dp[who][solved] = min( dp[who][solved], dp[prev][solved ^ ds[prob]] + tneeded[who][prob] );
				}			
				
				if( dp[who][solved] <= 280 ) ans = max( ans, popc[solved] );
			}	
		}
		
		cout << ans << "\n";
		
	}
	
	
	return 0;
}

























