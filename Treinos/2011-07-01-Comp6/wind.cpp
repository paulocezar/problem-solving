#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int tst;
	cin >> tst;
	while( tst-- ){
		
		int h, M;
		cin >> h >> M;	
		
		int t;
		bool ok = false;
		for( t = 1; t <= M; t++ ){
			if( (-6*t*t*t*t + h*t*t*t + 2*t*t + t) <= 0 ){ ok = true; break; }
		}
		if( ok ) cout << "The balloon first touches ground at hour:\n" << t << "\n";
		else cout << "The balloon does not touch ground in the given time.\n";

	}

	return 0;
}
