#include <iostream>
#include <string>

using namespace std;

int main(){

	string a, b;
	int sa, sb, i, j;
	cin >> a >> b;

	sa = a.size();
	sb = b.size();

	if( sa == sb ){
		
		for( i = 0; i < sa; i++ )
			if( a[i] != b[sa-i-1] ){
				cout << "NO\n";
				return 0;
			}
			cout << "YES\n";
	} else cout << "NO\n";

	return 0;
}

