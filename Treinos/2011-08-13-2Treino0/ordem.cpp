#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	int t, v[3];
	string nm;
	cin >> t;
	while( t-- ){
		cin >> v[0] >> v[1] >> v[2];
		sort( v, v+3 );
		cin >> nm;
		for( int i = 0; i < 3; i++ ){
			cout << v[nm[i]-'A'];
			if( i+1 < 3 ) cout << " ";
			else cout << "\n";
		}
	
	}

	return 0;
}

