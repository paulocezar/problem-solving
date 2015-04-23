#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int t;
	cin >> t;
	while( t-- ){
		int tt, m, x, y;
		cin >> tt;
		while( tt-- ){
			cin >> m >> x >> y;
			while( m-- ){
				x = x % 5;
				y = y % 5;
			}
			if( y == 0 ){
				if( x == 1 || x == 2 || x == 3 ) cout << "crystal\n";
				else cout << "empty\n";
			} else if( y == 1 && x == 2 ) cout << "crystal\n";
			else cout << "empty\n";
		}
	}

	return 0;
}

