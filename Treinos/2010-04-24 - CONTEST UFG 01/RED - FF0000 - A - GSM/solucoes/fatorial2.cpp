#include <iostream>

using namespace std;

int main(){

	long long n, out;

	while( cin >> n ){
		out = 0;
		while( n / 5 ) out += n/5, n /= 5;
		cout << out << endl;
	}

	return 0;
}

