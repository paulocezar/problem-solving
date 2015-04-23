#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int t;
	string key, msg;
	cin >> t;
	while( t-- ){
		cin >> key; cin.ignore();
		getline( cin, msg );
		int cur = 0, ksz = int(key.size());
		for( int i = 0; i < ksz; i++ ) key[i] -= 'A';
		for( size_t i = 0, sz = msg.size(); i < sz; i++ ){
			if( 'A' <= msg[i] && msg[i] <= 'Z' ){
				cout << char( (int(msg[i]-'A'+key[cur])%26)+'A' );
				cur = (cur+1)%ksz;
			}
		}
		cout << "\n";
	}
	return 0;
}

