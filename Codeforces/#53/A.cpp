#include <map> 
#include <set> 
#include <cmath> 
#include <queue> 
#include <vector> 
#include <string> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <cfloat>
#include <ctime> 
#include <climits>

int MIN( int a, int b ){ if( a < b ) return a; return b; }
int ABS( int a ){ if( a < 0 ) return -a; return a; }

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64;

int main( int argc, char* argv[] ){

	int n, x1, x2, y1, y2;
	
	cin >> n >> x1 >> y1 >> x2 >> y2;
	
	int ans;
	if( x1 == x2 && y1 == y2 ) ans = 0;
	else if( x1 == x2 && (x1 == n || x1 == 0) ) ans = ABS( y1-y2 );
	else if( y1 == y2 && (y1 == n || y1 == 0) ) ans = ABS( x1-x2 );
	else ans = MIN( x1+y1+x2+y2, MIN( x1+x2+2*n-y1-y2, MIN( y1+y2+2*n-x1-x2, 4*n-x1-x2-y1-y2  ) ) );
	
	cout << ans << "\n";
	
	return 0;
}
