#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <string>
#include <sstream>

using namespace std;

int main(){

	string mail, token, inilist;
	string endlist = "";
	
	cin >> inilist;
	if( inilist[0] == '@' ){
		cout << "No solution\n";
		return 0;
	}
	istringstream iss( inilist );

	
	if( !getline( iss, token, '@' )  ){
		cout << "No solution\n";
		return 0;
	}
	else endlist = token;

	token = "";
	while( getline( iss, token, '@' ) ){
		if( iss.eof() ) break;
		if( token.size() < 2 ) { cout << "No solution\n"; return 0; }
		int i = token.size() / 2;
		endlist += ( "@" + token.substr( 0, i ) + "," + token.substr( i, token.size()-i+1 ) );
		token = "";	
	}

	if( token.size() ){
		endlist += ( "@" + token );
		cout << endlist << endl;
	} else cout << "No solution\n";

	return 0;
}


