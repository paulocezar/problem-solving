#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

	string s1, s2;
	bool yes = true;
	getline( cin, s1 );
	getline( cin, s2 );
	map< char, int > app;

	int i = 0;
	while( s1[i] ){
		app[s1[i]]++;
		i++;
	}

	i = 0;
	while( s2[i] && yes ){
		if( s2[i] != ' ' && s2[i] != '\n' ){
			app[s2[i]]--;
			if( app[s2[i]] < 0 ) yes = false;
		}
		i++;
	}
	
	if( yes ) cout << "YES\n";
	else cout << "NO\n";


	return 0;
}


