#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){

	int n, age;
	int ans = 0;
	string person;
	
	cin >> n;

	while( n-- ){
		cin >> person;
		if( person[0] >= 'A' && person[0] <= 'Z' ){
			
			if( person == "ABSINTH" || person == "BEER" || person == "BRANDY" || person == "CHAMPAGNE" ||
			 	person == "GIN" || person == "RUM" || person == "SAKE" || person == "TEQUILA" || 
				person == "VODKA" || person == "WHISKEY" || person == "WINE" ) ans++;
			
		} else {
			age = 0;
			int i = 0;
			while( person[i] ) age = 10*age + person[i++]-'0';
			if( age < 18 ) ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}
