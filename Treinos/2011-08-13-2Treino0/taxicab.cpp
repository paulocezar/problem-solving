#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	
	const double pi = acos(-1.0);
	int t, r;
	cin >> t;
	while( t-- ){
		cin >> r;
		cout << fixed << setprecision(6) << pi*r*r << "\n";
		cout << fixed << setprecision(6) << 2.0*r*r << "\n";
	}
	return 0;
}

