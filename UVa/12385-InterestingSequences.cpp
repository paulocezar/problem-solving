#include <iostream>
#include <set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t, n, a;
	cin >> t;
	while( t-- ){
		cin >> n;
		set< int > sofar;
		int ans = 0;
		for( int i = 0; i < n; i++ ){
			cin >> a;
			if( sofar.find(a) != sofar.end() ){
				ans++;
				sofar.clear();
				sofar.insert( a );
			} else sofar.insert( a );
		}
		cout << ans << "\n";
	}

	return 0;
}

