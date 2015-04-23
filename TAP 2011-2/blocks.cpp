#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int t, N;
	cin >> t;
	while( t-- ){
		cin >> N;
		
		int ans = 1001*1001*1001;

		for( int x = 1; x <= N; x++ )
			for( int y = 1; y <= N; y++ )	if( x*y <= N ){
				int z = N/(x*y);
				if( x*y*z == N ) ans = min( ans, 2*(x*y + x*z + y*z) );
			}
		
		cout << ans << "\n";

	}

	return 0;
}

