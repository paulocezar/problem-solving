#include <iostream>

using namespace std;

inline int min( int a, int b ) { if( a < b ) return a; return b; }

int main(){

	int n, a, i;
	int rest[3];
	rest[0] = rest[1] = rest[2] = 0;

	cin >> n;
	for( i = 0; i < n; i++ ){

		cin >> a;
		rest[a%3]++;

	}

	int ans = rest[0]/2;
	ans += min( rest[1], rest[2] );

	cout << ans << "\n";

	return 0;
}

