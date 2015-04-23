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

int ans[100*500+1];
int coin[100];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	
	while( t-- ){
		int n;
		cin >> n;
		
		int mx = 0;
		for( int i = 0; i < n; i++ ){
			cin >> coin[i];
			mx += coin[i];
		}
		
		for( int i = 0; i <= mx; i++ ) ans[i] = 0;
		ans[0] = 1;
		
		for( int i = 0; i < n; i++ )
			for( int j = mx; j >= coin[i]; j-- )
				ans[j] += ans[j-coin[i]];
		
		int ideal = mx/2;
		while( !ans[ideal] ) ideal--;
		cout << mx-2*ideal << "\n";
		
		
	}
	
	return 0;
}

























