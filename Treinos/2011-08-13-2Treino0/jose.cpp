#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

	int t;
	string sa, sb;
	cin >> t;
	while( t-- ){
		cin >> sa >> sb;
		int a = 0, b = 0;
		a = 100*(sa[2]-'0') + 10*(sa[1]-'0') + (sa[0]-'0');
		b = 100*(sb[2]-'0') + 10*(sb[1]-'0') + (sb[0]-'0');
		cout << max( a, b ) << "\n";
	}

	return 0;
}

