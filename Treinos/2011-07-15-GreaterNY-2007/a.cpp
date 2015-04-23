#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int t, n;
	string s;
	
	cin >> t;
	int tc = 1;
	while( t-- ){
		cin >> n >> s; n--;
		cout << tc++ << " ";
		for( int i = 0; i < s.size(); i++ ){
			if( i != n ) cout << s[i];
		}
		cout << "\n";
	}
	
	return 0;
}