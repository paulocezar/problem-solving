#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){

	int t;
	cin >> t;
	while( t-- ){
		
		int n;
		cin >> n; cin.ignore();
		string linha;
		int s = 0, t = 0;

		while( n-- ){
			getline( cin, linha );
			for( size_t i = 0; i < linha.size(); i++ ){
				if( linha[i] == 's' || linha[i] == 'S' ) s++;
				else if( linha[i] == 't' || linha[i] == 'T' ) t++;
			}
		}
		if( t > s ) cout << "English\n";
		else cout << "French\n";

	}	

	return 0;
}

