#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main(){

	int n;
	long long x, sq;
	vector< long long > squares;
	
	map< long long, bool > square;
	
	for( long long a = 0; a*a <= 2147483647; a++ ){
		
		squares.push_back( a*a );
		square[ a*a ] = true;
		
	}
	
	cin >> n;
	while( n-- ){
	
		cin >> x;
		
		sq = (long long) sqrt( (long double)x );
		sq *= sq;

		long long ans = 0ll;
		
		for( int i = 0; i < squares.size() && squares[i] <= sq; i++ ){
			if( square.find( x-squares[i] ) != square.end() ) ans++;
		}
		
		if( ans & 1ll ) cout << ans/2ll + 1ll << "\n";
		else cout << ans/2ll << "\n";
	
	}

	return 0;
}
