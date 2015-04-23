#include <iostream>

using namespace std;

int main(){

	int t;
	cin >> t;
	while( t-- ){
		int t1, t2, nxt, len = 2;
		cin >> t1 >> t2;
		nxt = t1 - t2;
		while( nxt <= t2 ){
			t1 = t2;
			t2 = nxt;
			nxt = t1 - t2;
			len++;
		}
		cout << len+1 << "\n";
	}

	return 0;
}

