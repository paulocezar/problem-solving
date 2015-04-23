#include <iostream>

using namespace std;

int main(){

	int t;
	cin >> t;
	while( t-- ){
		int A, E;
		cin >> A >> E;
		
		if( A >= 3 && E <= 4 ) cout << "TroyMartian\n";
		if( A <= 6 && E >= 2 ) cout << "VladSaturnian\n";
		if( A <= 2 && E <= 3 ) cout << "GraemeMercurian\n";

	}

	return 0;
}

