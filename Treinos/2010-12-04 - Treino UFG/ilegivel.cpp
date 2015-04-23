#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>

using namespace std;

int main(){

	ios::sync_with_stdio( false );
	int t, ct;
	int n, m, ans;
	char first, last;
	string word, line;

	cin >> t;
	for( ct = 1; ct <= t; ct++ ){

		map< char, map< char, map< string, int > > > cnt;

		cin >> n;
		while( n-- ){
			
			cin >> word;
			if( word.size() == 1 ) {  cnt[word[0]]['-'][""] = 1;  continue; }
			first = word[0];
			last = word[word.size()-1];
			word = word.substr( 1, word.size()-2 );
			sort( word.begin(), word.end());

			cnt[first][last][word]++;
		}

		cout << "Cenario #" << ct << ":\n";
		cin >> m; cin.ignore();
		while( m-- ){
			
			ans = 1;
			getline( cin, line );
			
			istringstream inp( line );
			while( getline( inp, word, ' ' ) ){
				
				if( word.size() == 1 ) {
					ans *= cnt[word[0]]['-'][""];
				} else {
					first = word[0];
					last = word[word.size()-1];
					word = word.substr( 1, word.size()-2 );
					sort( word.begin(), word.end());
			
					ans *= cnt[first][last][word];
				}

				if( ans == 0 ) break;
			}
			
			cout << ans << "\n";

		}
		cout << "\n";

	}

	return 0;
}
