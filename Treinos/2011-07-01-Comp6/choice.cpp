#include <iostream>
#include <string>

using namespace std;

#define MAXN 10001
char ans[MAXN];

int main(){
	
	int t;
	char rgt;

	cin >> t;
	while( t-- ){
		
		int n;
		cin >> n;
		int ok = 0;
		for( int i = 0; i < n; i++) cin >> ans[i];
		for( int i = 0; i < n; i++ ){
			cin >> rgt;
			if( rgt == ans[i] ) ok++;
		}
		cout << ok << "\n";
	}

	return 0;
}

