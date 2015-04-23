#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string words[20];
int id[20];

int main(){

	int t, n;
	ios::sync_with_stdio( false );
	string ans;
	
	cin >> t;
	while( t-- ){
		cin >> n;
		
		for( int i = 0; i < n; i++ ) { cin >> words[i]; id[i] = i; }
		
		ans = "{";
		
		do {
			
			string s = "";
			for( int i = 0; i < n; i++ ) s += words[ id[i] ];
			if( s < ans ) ans = s;
			
		} while( next_permutation( id, id+n ) );
		
		cout << ans << "\n";
	}

	return 0;
}
