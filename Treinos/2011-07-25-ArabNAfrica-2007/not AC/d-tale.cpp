#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int main(){

	ios::sync_with_stdio(false);	
	string str, ans;
	
	for(getline(cin, str); str != "EOF"; getline(cin, str)){
		ans = "";		
		for( size_t i = 0; i < str.size(); i++ ){
			switch( str[i] ){
				case 'd':
					if( i+1 < str.size() && str[i+1] == 'd' ) ans += "p", i++;
					else ans += 'd';
					break;
				case 'p':
					if( i+3 < str.size() && ( str[i+1] == 'i' && str[i+2] == 'n' && str[i+3] == 'k' ) ) ans += "floyd", i+=3;
					else ans += 'p';
					break;
				case 'e':
					if( i+1 < str.size() && str[i+1] == 'i' ){
						if( i == 0 || str[i-1] != 'c' ) ans += "ie", i++;
						else ans += 'e';
					} else ans += 'e';
					break;
				default: if( isspace(str[i]) || ('a' <= str[i] && str[i] <= 'z') ) ans += str[i];
			}		
		}
		cout << ans << "\n";
	}
	
	return 0;
}

