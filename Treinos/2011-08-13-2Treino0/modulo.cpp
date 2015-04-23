#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	char seen[44];
	int t, x;
	cin >> t;
	while( t-- ){
		memset( seen, 0, sizeof(seen) );
		for( int i = 0; i < 10; i++ ){
			cin >> x;
			seen[x%42] = 1;
		}
		int ans = 0;
		for( int i = 0; i < 42; i++ ) if( seen[i] ) ans++;
		cout << ans << "\n";
	}

	return 0;
}

