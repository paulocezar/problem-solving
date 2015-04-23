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

int mat[111][111];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N;
	while( cin >> N && N ){
		
		for( int i = 0; i < N; i++ ) for( int j = 0; j < N; j++ ){
			cin >> mat[i][j];
			if( i ) mat[i][j] += mat[i-1][j];
		}
		
		int ans = -2e9;
		for( int i1 = 0; i1 < N; i1++ ) for( int i2 = i1; i2 < N; i2++ ){
			int cur = 0, mx = -2e9;
			
			for( int j = 0; j < N; j++ ){
				cur += (mat[i2][j] - (i1?mat[i1-1][j]:0));
				mx = max( mx, cur );
				if( cur < 0 ) cur = 0;
			}
			
			ans = max( ans, mx );
		}
		cout << ans << "\n";
	}
	
	return 0;
}

























